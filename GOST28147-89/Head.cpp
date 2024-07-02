#include "Head.h"
#include "msclr/marshal_cppstd.h"
#include <iostream>
#include <sstream>
#include <chrono>

using namespace GOST2814789;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GOST2814789::Head form;
	Application::Run(% form);
}

//Описание одного раунда зашифрования
uint32_t round(uint32_t First, uint32_t Second, uint8_t SBlocks[8][16], uint32_t Keys32b[], int j) {
	uint32_t iter, temp;
	iter = (First + Keys32b[j % 8]) % UINT32_MAX;

	uint8_t blocks4bit[4];
	for (uint8_t k = 0; k < 4; k++) {
		blocks4bit[k] = (uint8_t)(iter >> (28 - (k * 8)));
		blocks4bit[k] = (blocks4bit[k] << 4) | (uint8_t)(iter & 0x0F);
	}

	uint8_t blocks4bit_1, blocks4bit_2;
	for (uint8_t k = 0; k < 4; k++) {
		blocks4bit_1 = SBlocks[j % 8][blocks4bit[k] & 0x0F];
		blocks4bit_2 = SBlocks[j % 8][blocks4bit[k] >> 4];

		blocks4bit[k] = blocks4bit_2;
		blocks4bit[k] = (blocks4bit[k] << 4) | blocks4bit_1;
	}

	for (uint8_t k = 0; k < 4; k++) {
		iter = (iter << 8) | blocks4bit[k];
	}

	iter = ((iter << 11) | (iter >> (-11 & 31))) & (((uint64_t)1 << 32) - 1);

	temp = First;
	return(iter ^ Second, temp);
}

//Функция зашифрования
System::Void GOST2814789::Head::Encrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	GOST2814789::Head::StatusLabel->Text = "В процессе...";

	using namespace std;
	using namespace msclr::interop;

	if (GOST2814789::Head::FirstTextBox->Text == "" || GOST2814789::Head::KeyTextBox->Text == "" || ResultFilePath == "") {
		GOST2814789::Head::StatusLabel->Text = "Заполните все поля!";
	}
	else {
		//Выравниваю блоки в тексте
		string text = marshal_as<string>(GOST2814789::Head::FirstTextBox->Text);
		if (text.size() % 8 != 0) {
			for (int i = 0; i < (8 - (text.size() % 8)); i++) {
				text.append(" ");
			}
		}

		//Форматирую ключ под 256 бит
		string key = marshal_as<string>(GOST2814789::Head::KeyTextBox->Text);
		if (key.size() < 32) {
			int counter = 0;
			for (int i = key.size() - 1; i < 32; i++) {
				key.push_back(key[counter]);
				counter++;
			}
		}
		else if (key.size() > 32) {
			string tkey = "";
			for (int i = 0; i < 32; i++) {
				tkey.push_back(key[i]);
			}
			key = tkey;
		}
		string Keys[8];
		int counter = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				Keys[i].push_back(key[counter]);
				counter++;
			}
		}

		//Подготавливаю ключ для работы с битами
		uint32_t Keys32b[8];
		for (int i = 0; i < 8; i++) {
			istringstream(Keys[i]) >> Keys32b[i];
		}
		
		//Создаю массив S-блоков
		uint8_t SBlocks[8][16] = {
			{4,10,9,2,13,8,0,14,6,11,1,12,7,15,5,3},
			{14,11,4,12,6,13,15,10,2,3,8,1,0,7,5,9},
			{5,8,1,13,10,3,4,2,14,15,12,7,6,0,9,11},
			{7,13,10,1,0,8,9,15,14,4,6,12,11,2,5,3},
			{6,12,7,1,5,15,13,8,4,10,9,14,0,3,11,2},
			{4,11,10,0,7,2,1,13,3,6,8,5,9,12,15,14},
			{13,11,4,1,3,15,5,9,0,10,14,7,6,8,2,12},
			{1,15,13,0,5,7,10,4,9,2,3,14,6,11,8,12}
		};

		//Заполнение переменных для вхождения в цикл
		uint32_t First, Second;
		for (int i = 0; i < 4; i++) {
			First = (First << (i * 8)) | static_cast<uint8_t>(text[i]);
			Second = (Second << (i * 8)) | static_cast<uint8_t>(text[i+4]);
		}

		string result = "";

		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < text.size(); i += 8) {
			for (int j = 0; j < 24; j++) {
				First, Second = round(First, Second, SBlocks, Keys32b, j);
			}
			for (int j = 31; j >= 24; j--) {
				First, Second = round(First, Second, SBlocks, Keys32b, j);
			}

			uint64_t Result;
			Result = First;
			Result = (Result << 32) | Second;
			for (int j = 1; j < 9; j++) {
				result.push_back(static_cast<char>((uint8_t)(Result << (i*8))));
			}

			if (i > 1) {
				for (int j = 0; j < 4; j++) {
					First = (First << (j * 8)) | static_cast<uint8_t>(text[i]);
					Second = (Second << (j * 8)) | static_cast<uint8_t>(text[i + 4]);
				}
			}
		}
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		GOST2814789::Head::SecondTextBox->Text = marshal_as<String^>(result);

		FILE* f = fopen(ResultFilePath.c_str(), "wb");
		fputs(result.c_str(), f);
		fclose(f);

		stringstream hexString;

		for (size_t i = 0; i < result.length(); ++i) {
			hexString << hex << (int)result[i];
			if (i < result.length() - 1) {
				hexString << " ";
			}
		}

		GOST2814789::Head::SecondHexBox->Text = marshal_as<String^>(hexString.str());
		GOST2814789::Head::StatusLabel->Text = "Зашифрование успешно!";
		GOST2814789::Head::TimeLabel->Text = "Время зашифрования: " + Convert::ToString(duration.count()) + " секунд.";
	}
}


//Функция расшифрования
System::Void GOST2814789::Head::Decrypt_Click(System::Object^ sender, System::EventArgs^ e)
{
	GOST2814789::Head::StatusLabel->Text = "В процессе...";

	using namespace std;
	using namespace msclr::interop;

	if (GOST2814789::Head::FirstTextBox->Text == "" || GOST2814789::Head::KeyTextBox->Text == "" || ResultFilePath == "") {
		GOST2814789::Head::StatusLabel->Text = "Заполните все поля!";
	}
	else {
		//Выравниваю блоки в тексте
		string text = marshal_as<string>(GOST2814789::Head::FirstTextBox->Text);
		if (text.size() % 8 != 0) {
			for (int i = 0; i < (8 - (text.size() % 8)); i++) {
				text.append(" ");
			}
		}

		//Форматирую ключ под 256 бит
		string key = marshal_as<string>(GOST2814789::Head::KeyTextBox->Text);
		if (key.size() < 32) {
			int counter = 0;
			for (int i = key.size() - 1; i < 32; i++) {
				key.push_back(key[counter]);
				counter++;
			}
		}
		else if (key.size() > 32) {
			string tkey = "";
			for (int i = 0; i < 32; i++) {
				tkey.push_back(key[i]);
			}
			key = tkey;
		}
	}
}