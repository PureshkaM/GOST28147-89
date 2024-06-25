#include "Head.h"
#include "msclr/marshal_cppstd.h"
#include <iostream>

using namespace GOST2814789;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GOST2814789::Head form;
	Application::Run(% form);
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