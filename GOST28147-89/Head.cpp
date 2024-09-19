#include "Head.h"
#include "msclr/marshal_cppstd.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <fstream>

using namespace GOST2814789;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GOST2814789::Head form;
	Application::Run(% form);
}

/*
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
*/

/*
uint32_t round(uint32_t First, uint32_t Second, uint8_t SBlocks[8][16], uint32_t Keys32b[], int j) {
	// Сложение с ключом с ограничением по модулю 2^32
	uint32_t iter = (First + Keys32b[j % 8]) & 0xFFFFFFFF;

	// Рассчитываем замены по S-блокам
	uint8_t blocks4bit[8];
	for (uint8_t k = 0; k < 8; k++) {
		blocks4bit[k] = (iter >> (4 * (7 - k))) & 0x0F;
		blocks4bit[k] = SBlocks[k][blocks4bit[k]];
	}

	// Собираем обратно 32-битное значение
	iter = 0;
	for (uint8_t k = 0; k < 8; k++) {
		iter |= ((uint32_t)blocks4bit[k] << (4 * (7 - k)));
	}

	// Циклический сдвиг влево на 11 бит
	iter = ((iter << 11) | (iter >> (32 - 11))) & 0xFFFFFFFF;

	// XOR с Second
	iter ^= Second;

	return iter;
}*/

uint32_t round(uint32_t First, uint32_t Second, uint8_t SBlocks[8][16], uint32_t Keys32b[], int j) {
	// Сложение с ключом по модулю 2^32
	uint32_t iter = (First + Keys32b[j % 8]) & 0xFFFFFFFF;

	// Применение S-блоков
	uint8_t blocks4bit[8];
	for (uint8_t k = 0; k < 8; k++) {
		// Извлечение 4-битных блоков
		blocks4bit[k] = (iter >> (4 * (7 - k))) & 0x0F;
		// Замена через S-блок
		blocks4bit[k] = SBlocks[k][blocks4bit[k]];
	}

	// Собираем значение обратно в 32-битное
	iter = 0;
	for (uint8_t k = 0; k < 8; k++) {
		iter |= ((uint32_t)blocks4bit[k] << (4 * (7 - k)));
	}

	// Циклический сдвиг влево на 11 бит
	iter = ((iter << 11) | (iter >> (32 - 11))) & 0xFFFFFFFF;

	// XOR с Second
	iter ^= Second;

	return iter;
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
		while (text.size() % 8 != 0) {
			text.append(" ");
		}

		// Форматирую ключ под 256 бит
		string key = marshal_as<string>(GOST2814789::Head::KeyTextBox->Text);
		if (key.size() < 32) {
			int counter = 0;
			for (int i = key.size(); i < 32; i++) {
				key.push_back(key[counter % key.size()]);
				counter++;
			}
		}
		else if (key.size() > 32) {
			key = key.substr(0, 32); // Обрезаем строку до 32 символов
		}

		// Подготавливаю ключ для работы с битами
		uint32_t Keys32b[8];
		for (int i = 0; i < 8; i++) {
			// Преобразуем каждые 4 байта ключа в одно 32-битное число
			Keys32b[i] = (static_cast<uint8_t>(key[i * 4]) << 24) |
				(static_cast<uint8_t>(key[i * 4 + 1]) << 16) |
				(static_cast<uint8_t>(key[i * 4 + 2]) << 8) |
				static_cast<uint8_t>(key[i * 4 + 3]);
		}

		/*
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
		*/
		
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
			// Загружаем по 4 байта в First и Second
			uint32_t First = 0, Second = 0;
			for (int j = 0; j < 4; j++) {
				First |= (static_cast<uint8_t>(text[i + j]) << (8 * j));
				Second |= (static_cast<uint8_t>(text[i + 4 + j]) << (8 * j));
			}

			// 24 раунда с ключами в прямом порядке
			for (int j = 0; j < 24; j++) {
				uint32_t temp = Second;
				Second = First;
				First = round(First, temp, SBlocks, Keys32b, j);
			}

			// 8 раундов с ключами в обратном порядке
			for (int j = 31; j >= 24; j--) {
				uint32_t temp = Second;
				Second = First;
				First = round(First, temp, SBlocks, Keys32b, j);
			}

			// Собираем результат
			uint64_t Result = ((uint64_t)First << 32) | Second;

			// Разбиваем результат на массив из 8 символов (байт)
			char c = 0;
			char resultBytes[8] = {c,c,c,c,c,c,c,c};
			for (int j = 7; j >= 0; j--) {
				resultBytes[j] = static_cast<char>((Result >> (8 * j)) & 0xFF);
			}

			// Копируем символы в итоговый результат
			for (int j = 0; j < 8; j++) {
				result.push_back(resultBytes[j]);
			}
		}
		/*
		for (int i = 0; i < text.size(); i += 8) {
			for (int j = 0; j < 24; j++) {
				Second = First;
				First= round(First, Second, SBlocks, Keys32b, j);
			}
			for (int j = 31; j >= 24; j--) {
				Second = First;
				First = round(First, Second, SBlocks, Keys32b, j);
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
		*/

		int t = size(result);
		int t2 = size(text);

		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		GOST2814789::Head::SecondTextBox->Text = marshal_as<String^>(result);


		ofstream f(ResultFilePath.c_str(), ios::binary);
		for (char c : result) {
			f.write(&c, sizeof(c));
		}
		f.close();

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
		std::string text;
		FILE* p = fopen(TextFilePath.c_str(), "rb");
		char c;
		while (fread(&c, sizeof(char), 1, p) == 1) {
			text += c;
		}
		fclose(p);
		while (text.size() % 8 != 0) {
			text.append(" ");
		}

		// Форматирую ключ под 256 бит
		string key = marshal_as<string>(GOST2814789::Head::KeyTextBox->Text);
		if (key.size() < 32) {
			int counter = 0;
			for (int i = key.size(); i < 32; i++) {
				key.push_back(key[counter % key.size()]);
				counter++;
			}
		}
		else if (key.size() > 32) {
			key = key.substr(0, 32); // Обрезаем строку до 32 символов
		}

		// Подготавливаю ключ для работы с битами
		uint32_t Keys32b[8];
		for (int i = 0; i < 8; i++) {
			// Преобразуем каждые 4 байта ключа в одно 32-битное число
			Keys32b[i] = (static_cast<uint8_t>(key[i * 4]) << 24) |
				(static_cast<uint8_t>(key[i * 4 + 1]) << 16) |
				(static_cast<uint8_t>(key[i * 4 + 2]) << 8) |
				static_cast<uint8_t>(key[i * 4 + 3]);
		}

		/*
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
		*/

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
			Second = (Second << (i * 8)) | static_cast<uint8_t>(text[i + 4]);
		}

		string result = "";

		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < text.size(); i += 8) {
			// Загружаем по 4 байта в First и Second (зашифрованные блоки)
			uint32_t First = 0, Second = 0;
			for (int j = 0; j < 4; j++) {
				First |= (static_cast<uint8_t>(text[i + j]) << (8 * j));
				Second |= (static_cast<uint8_t>(text[i + 4 + j]) << (8 * j));
			}

			// 8 раундов с ключами в прямом порядке
			for (int j = 24; j < 32; j++) {
				uint32_t temp = Second;
				Second = First;
				First = round(First, temp, SBlocks, Keys32b, j);
			}

			// 24 раунда с ключами в обратном порядке
			for (int j = 23; j >= 0; j--) {
				uint32_t temp = Second;
				Second = First;
				First = round(First, temp, SBlocks, Keys32b, j);
			}

			// Собираем результат
			uint64_t Result = ((uint64_t)First << 32) | Second;

			// Разбиваем результат на массив из 8 символов (байт)
			char c = 0;
			unsigned char resultBytes[8] = { c,c,c,c,c,c,c,c };
			for (int j = 7; j >= 0; j--) {
				resultBytes[j] = static_cast<unsigned char>((Result >> (8 * j)) & 0xFF);
			}

			// Копируем символы в итоговый результат
			for (int j = 0; j < 8; j++) {
				result.push_back(resultBytes[j]);
			}
		}

		/*
		for (int i = 0; i < text.size(); i += 8) {
			for (int j = 24; j <= 31; j++) {
				Second = First;
				First = round(First, Second, SBlocks, Keys32b, j);
			}
			for (int j = 23; j >= 0; j--) {
				Second = First;
				First = round(First, Second, SBlocks, Keys32b, j);
			}

			uint64_t Result;
			Result = First;
			Result = (Result << 32) | Second;
			for (int j = 1; j < 9; j++) {
				result.push_back(static_cast<char>((uint8_t)(Result << (i * 8))));
			}

			if (i > 1) {
				for (int j = 0; j < 4; j++) {
					First = (First << (j * 8)) | static_cast<uint8_t>(text[i]);
					Second = (Second << (j * 8)) | static_cast<uint8_t>(text[i + 4]);
				}
			}
		}
		*/
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		int t = result.size();
		int t2 = text.size();

		GOST2814789::Head::SecondTextBox->Text = marshal_as<String^>(result);

		ofstream f(ResultFilePath.c_str(), ios::binary);
		for (char c : result) {
			f.write(&c, sizeof(c));
		}
		f.close();

		stringstream hexString;

		for (size_t i = 0; i < result.length(); ++i) {
			hexString << hex << (int)result[i];
			if (i < result.length() - 1) {
				hexString << " ";
			}
		}

		GOST2814789::Head::SecondHexBox->Text = marshal_as<String^>(hexString.str());
		GOST2814789::Head::StatusLabel->Text = "Расшифрование успешно!";
		GOST2814789::Head::TimeLabel->Text = "Время расшифрования: " + Convert::ToString(duration.count()) + " секунд.";
	}
}