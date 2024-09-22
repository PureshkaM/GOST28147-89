#pragma once
#include <iostream>
#include "msclr/marshal_cppstd.h"


std::string ResultFilePath = "";
std::string TextFilePath = "";


namespace GOST2814789 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text;

	/// <summary>
	/// Сводка для Head
	/// </summary>
	public ref class Head : public System::Windows::Forms::Form
	{
	public:
		Head(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Head()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;





	private: System::Windows::Forms::Button^ SelectedFile;




	private: System::Windows::Forms::Button^ ResultFile;

	private: System::Windows::Forms::OpenFileDialog^ OpenFile;
	private: System::Windows::Forms::Button^ KeyFile;



	private: System::Windows::Forms::RadioButton^ EncryptValue;
	private: System::Windows::Forms::RadioButton^ DecryptValue;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RichTextBox^ SecondHexBox;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ FirstTextBox;

	private: System::Windows::Forms::RichTextBox^ FirstHexBox;
	private: System::Windows::Forms::RichTextBox^ KeyTextBox;


	private: System::Windows::Forms::RichTextBox^ KeyHexBox;
	private: System::Windows::Forms::RichTextBox^ SecondTextBox;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ Encrypt;
	private: System::Windows::Forms::Button^ Decrypt;
	private: System::Windows::Forms::SaveFileDialog^ SaveFolder;
	private: System::Windows::Forms::StatusStrip^ Status;
	private: System::Windows::Forms::ToolStripStatusLabel^ StatusLabel;

	private: System::Windows::Forms::ToolStripStatusLabel^ TimeLabel;
	private: System::Windows::Forms::OpenFileDialog^ OpenKeyFile;










	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SelectedFile = (gcnew System::Windows::Forms::Button());
			this->ResultFile = (gcnew System::Windows::Forms::Button());
			this->OpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->KeyFile = (gcnew System::Windows::Forms::Button());
			this->EncryptValue = (gcnew System::Windows::Forms::RadioButton());
			this->DecryptValue = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FirstTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->FirstHexBox = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->KeyTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->KeyHexBox = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SecondTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SecondHexBox = (gcnew System::Windows::Forms::RichTextBox());
			this->Encrypt = (gcnew System::Windows::Forms::Button());
			this->Decrypt = (gcnew System::Windows::Forms::Button());
			this->SaveFolder = (gcnew System::Windows::Forms::SaveFileDialog());
			this->Status = (gcnew System::Windows::Forms::StatusStrip());
			this->StatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->TimeLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->OpenKeyFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->Status->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выберите, что сделать с информацией:";
			// 
			// SelectedFile
			// 
			this->SelectedFile->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->SelectedFile->Location = System::Drawing::Point(6, 46);
			this->SelectedFile->Name = L"SelectedFile";
			this->SelectedFile->Size = System::Drawing::Size(76, 47);
			this->SelectedFile->TabIndex = 6;
			this->SelectedFile->Text = L"Выберите файл";
			this->SelectedFile->UseVisualStyleBackColor = false;
			this->SelectedFile->Click += gcnew System::EventHandler(this, &Head::SelectedFile_Click);
			// 
			// ResultFile
			// 
			this->ResultFile->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ResultFile->Location = System::Drawing::Point(6, 55);
			this->ResultFile->Name = L"ResultFile";
			this->ResultFile->Size = System::Drawing::Size(76, 47);
			this->ResultFile->TabIndex = 9;
			this->ResultFile->Text = L"Выберите путь";
			this->ResultFile->UseVisualStyleBackColor = false;
			this->ResultFile->Click += gcnew System::EventHandler(this, &Head::ResultFile_Click);
			// 
			// OpenFile
			// 
			this->OpenFile->Filter = L"Текстовый документ (*.txt)|*.txt|Зашифрованный текст (*.chip)|*.chip";
			// 
			// KeyFile
			// 
			this->KeyFile->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->KeyFile->Location = System::Drawing::Point(6, 44);
			this->KeyFile->Name = L"KeyFile";
			this->KeyFile->Size = System::Drawing::Size(76, 44);
			this->KeyFile->TabIndex = 11;
			this->KeyFile->Text = L"Выберите файл";
			this->KeyFile->UseVisualStyleBackColor = false;
			this->KeyFile->Click += gcnew System::EventHandler(this, &Head::KeyFile_Click);
			// 
			// EncryptValue
			// 
			this->EncryptValue->AutoSize = true;
			this->EncryptValue->Location = System::Drawing::Point(268, 9);
			this->EncryptValue->Name = L"EncryptValue";
			this->EncryptValue->Size = System::Drawing::Size(95, 17);
			this->EncryptValue->TabIndex = 15;
			this->EncryptValue->Text = L"Зашифровать";
			this->EncryptValue->UseVisualStyleBackColor = true;
			this->EncryptValue->CheckedChanged += gcnew System::EventHandler(this, &Head::EncryptValue_CheckedChanged);
			// 
			// DecryptValue
			// 
			this->DecryptValue->AutoSize = true;
			this->DecryptValue->Location = System::Drawing::Point(369, 9);
			this->DecryptValue->Name = L"DecryptValue";
			this->DecryptValue->Size = System::Drawing::Size(101, 17);
			this->DecryptValue->TabIndex = 16;
			this->DecryptValue->Text = L"Расшифровать";
			this->DecryptValue->UseVisualStyleBackColor = true;
			this->DecryptValue->CheckedChanged += gcnew System::EventHandler(this, &Head::DecryptValue_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->FirstTextBox);
			this->groupBox1->Controls->Add(this->FirstHexBox);
			this->groupBox1->Controls->Add(this->SelectedFile);
			this->groupBox1->Enabled = false;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(15, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(374, 148);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Исходный текст/шифротекст";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(247, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 17);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Text:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(141, 26);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 17);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Hex:";
			// 
			// FirstTextBox
			// 
			this->FirstTextBox->AcceptsTab = true;
			this->FirstTextBox->Location = System::Drawing::Point(250, 46);
			this->FirstTextBox->Name = L"FirstTextBox";
			this->FirstTextBox->Size = System::Drawing::Size(100, 96);
			this->FirstTextBox->TabIndex = 12;
			this->FirstTextBox->Text = L"";
			this->FirstTextBox->TextChanged += gcnew System::EventHandler(this, &Head::FirstTextBox_TextChanged);
			// 
			// FirstHexBox
			// 
			this->FirstHexBox->AcceptsTab = true;
			this->FirstHexBox->Location = System::Drawing::Point(144, 46);
			this->FirstHexBox->Name = L"FirstHexBox";
			this->FirstHexBox->ReadOnly = true;
			this->FirstHexBox->Size = System::Drawing::Size(100, 96);
			this->FirstHexBox->TabIndex = 11;
			this->FirstHexBox->Text = L"";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->KeyTextBox);
			this->groupBox2->Controls->Add(this->KeyHexBox);
			this->groupBox2->Controls->Add(this->KeyFile);
			this->groupBox2->Enabled = false;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(395, 34);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(374, 146);
			this->groupBox2->TabIndex = 18;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ключ";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(247, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 17);
			this->label7->TabIndex = 15;
			this->label7->Text = L"Text:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(141, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(33, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Hex:";
			// 
			// KeyTextBox
			// 
			this->KeyTextBox->AcceptsTab = true;
			this->KeyTextBox->Location = System::Drawing::Point(250, 44);
			this->KeyTextBox->Name = L"KeyTextBox";
			this->KeyTextBox->Size = System::Drawing::Size(100, 96);
			this->KeyTextBox->TabIndex = 13;
			this->KeyTextBox->Text = L"";
			this->KeyTextBox->TextChanged += gcnew System::EventHandler(this, &Head::KeyTextBox_TextChanged);
			// 
			// KeyHexBox
			// 
			this->KeyHexBox->AcceptsTab = true;
			this->KeyHexBox->Location = System::Drawing::Point(144, 44);
			this->KeyHexBox->Name = L"KeyHexBox";
			this->KeyHexBox->ReadOnly = true;
			this->KeyHexBox->Size = System::Drawing::Size(100, 96);
			this->KeyHexBox->TabIndex = 12;
			this->KeyHexBox->Text = L"";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->SecondTextBox);
			this->groupBox3->Controls->Add(this->SecondHexBox);
			this->groupBox3->Controls->Add(this->ResultFile);
			this->groupBox3->Enabled = false;
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(15, 186);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(374, 157);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Сохранение результата";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(247, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 17);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Text:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(141, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 17);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Hex:";
			// 
			// SecondTextBox
			// 
			this->SecondTextBox->AcceptsTab = true;
			this->SecondTextBox->Location = System::Drawing::Point(250, 55);
			this->SecondTextBox->Name = L"SecondTextBox";
			this->SecondTextBox->ReadOnly = true;
			this->SecondTextBox->Size = System::Drawing::Size(100, 96);
			this->SecondTextBox->TabIndex = 11;
			this->SecondTextBox->Text = L"";
			// 
			// SecondHexBox
			// 
			this->SecondHexBox->AcceptsTab = true;
			this->SecondHexBox->Location = System::Drawing::Point(144, 55);
			this->SecondHexBox->Name = L"SecondHexBox";
			this->SecondHexBox->ReadOnly = true;
			this->SecondHexBox->Size = System::Drawing::Size(100, 96);
			this->SecondHexBox->TabIndex = 10;
			this->SecondHexBox->Text = L"";
			// 
			// Encrypt
			// 
			this->Encrypt->Enabled = false;
			this->Encrypt->Location = System::Drawing::Point(395, 186);
			this->Encrypt->Name = L"Encrypt";
			this->Encrypt->Size = System::Drawing::Size(180, 46);
			this->Encrypt->TabIndex = 20;
			this->Encrypt->Text = L"Зашифровать";
			this->Encrypt->UseVisualStyleBackColor = true;
			this->Encrypt->Click += gcnew System::EventHandler(this, &Head::Encrypt_Click);
			// 
			// Decrypt
			// 
			this->Decrypt->Enabled = false;
			this->Decrypt->Location = System::Drawing::Point(589, 186);
			this->Decrypt->Name = L"Decrypt";
			this->Decrypt->Size = System::Drawing::Size(180, 46);
			this->Decrypt->TabIndex = 21;
			this->Decrypt->Text = L"Расшифровать";
			this->Decrypt->UseVisualStyleBackColor = true;
			this->Decrypt->Click += gcnew System::EventHandler(this, &Head::Decrypt_Click);
			// 
			// SaveFolder
			// 
			this->SaveFolder->DefaultExt = L"chip";
			this->SaveFolder->Filter = L"Шифротекст GOST 28147-89 (*.chip)|*.chip";
			// 
			// Status
			// 
			this->Status->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->StatusLabel, this->TimeLabel });
			this->Status->Location = System::Drawing::Point(0, 343);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(783, 22);
			this->Status->TabIndex = 22;
			this->Status->Text = L"Готово";
			// 
			// StatusLabel
			// 
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(126, 17);
			this->StatusLabel->Text = L"Ожидание действий...";
			// 
			// TimeLabel
			// 
			this->TimeLabel->Name = L"TimeLabel";
			this->TimeLabel->Size = System::Drawing::Size(0, 17);
			// 
			// OpenKeyFile
			// 
			this->OpenKeyFile->Filter = L"Текстовый документ (*.txt)|*.txt";
			// 
			// Head
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoScroll = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(783, 365);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->Decrypt);
			this->Controls->Add(this->Encrypt);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->DecryptValue);
			this->Controls->Add(this->EncryptValue);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Head";
			this->Text = L"ГОСТ 28147-89";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->Status->ResumeLayout(false);
			this->Status->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void EncryptValue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->EncryptValue->Checked == true) {
			this->Encrypt->Enabled = true;
			this->Decrypt->Enabled = false;
			this->groupBox1->Enabled = true;
			this->groupBox2->Enabled = true;
			this->groupBox3->Enabled = true;
			this->FirstTextBox->ReadOnly = false;
			this->FirstHexBox->ReadOnly = false;
			this->SecondTextBox->ReadOnly = true;
			this->SecondHexBox->ReadOnly = true;
			FirstTextBox->Text = "";
			FirstHexBox->Text = "";
			KeyTextBox->Text = "";
			KeyHexBox->Text = "";
			SecondTextBox->Text = "";
			SecondHexBox->Text = "";
			TimeLabel->Text = "";
			StatusLabel->Text = "";
			ResultFilePath = "";
		}
	}
	private: System::Void DecryptValue_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->DecryptValue->Checked == true) {
			Decrypt->Enabled = true;
			Encrypt->Enabled = false;
			groupBox1->Enabled = true;
			groupBox2->Enabled = true;
			groupBox3->Enabled = true;
			FirstTextBox->ReadOnly = true;
			FirstHexBox->ReadOnly = true;
			SecondTextBox->ReadOnly = false;
			SecondHexBox->ReadOnly = false;
			FirstTextBox->Text = "";
			FirstHexBox->Text = "";
			KeyTextBox->Text = "";
			KeyHexBox->Text = "";
			SecondTextBox->Text = "";
			SecondHexBox->Text = "";
			TimeLabel->Text = "";
			StatusLabel->Text = "";
			ResultFilePath = "";
		}
	}


		   //Выбор файла с текстом
	private: System::Void SelectedFile_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string file;
		this->OpenFile->Title = "Выберите файл с текстом";
		TimeLabel->Text = "";
		StatusLabel->Text = "";

		if (this->OpenFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				file = msclr::interop::marshal_as<std::string>(this->OpenFile->FileName);
				TextFilePath = file;

				std::string text;
				FILE* f = fopen(file.c_str(), "rb");
				char c;
				while (fread(&c, sizeof(char), 1, f) == 1) {
					text += c;
				}
				fclose(f);

				FirstTextBox->Text = msclr::interop::marshal_as<String^>(text);

				String^ input = msclr::interop::marshal_as<String^>(text);
				array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(input);
				StringBuilder^ hexString = gcnew StringBuilder();

				for (int i = 0; i < bytes->Length; i++) {
					hexString->Append(bytes[i].ToString("X2"));
					if (i < bytes->Length - 1) {
						hexString->Append(" ");
					}
				}

				FirstHexBox->Text = hexString->ToString();
				delete hexString;
				StatusLabel->Text = "Файл с текстом открыт";
			}
			catch (Exception^) {
				StatusLabel->Text = "Ошибка при открытии файла";
			}
			finally {
				this->OpenFile->Reset();
			}
		}
	}


		   //Выбор файла с ключом
	private: System::Void KeyFile_Click(System::Object^ sender, System::EventArgs^ e) {
		TimeLabel->Text = "";
		StatusLabel->Text = "";
		std::string key;
		this->OpenKeyFile->Title = "Выберите файл с ключом";

		if (this->OpenKeyFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				key = msclr::interop::marshal_as<std::string>(this->OpenKeyFile->FileName);

				std::string text;
				FILE* f = fopen(key.c_str(), "rb");
				char c;
				while (fread(&c, sizeof(char), 1, f) == 1) {
					text += c;
				}
				fclose(f);

				KeyTextBox->Text = msclr::interop::marshal_as<String^>(text);

				String^ input = msclr::interop::marshal_as<String^>(text);
				array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(input);
				StringBuilder^ hexString = gcnew StringBuilder();

				for (int i = 0; i < bytes->Length; i++) {
					hexString->Append(bytes[i].ToString("X2"));
					if (i < bytes->Length - 1) {
						hexString->Append(" ");
					}
				}

				KeyHexBox->Text = hexString->ToString();
				StatusLabel->Text = "Файл с ключом открыт";
			}
			catch (Exception^) {
				StatusLabel->Text = "Ошибка при открытии файла";
			}
			finally {
				this->OpenKeyFile->Reset();
			}
		}
	}


		   //Выбор места для сохранения результата
	private: System::Void ResultFile_Click(System::Object^ sender, System::EventArgs^ e) {
		TimeLabel->Text = "";
		StatusLabel->Text = "";
		this->SaveFolder->Title = "Выберите место для сохранения файла";

		if (this->EncryptValue->Checked == true) {
			this->SaveFolder->Filter = "Шифротекст GOST 28147-89 (*.chip)|*.chip";
			if (this->SaveFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::Stream^ fileStream = nullptr;
				try {
					std::string FilePath = msclr::interop::marshal_as<std::string>(this->SaveFolder->FileName);
					if (FilePath.find(".chip", size(FilePath) - 6) == std::string::npos) {
						this->SaveFolder->FileName += ".chip";
						FilePath = msclr::interop::marshal_as<std::string>(this->SaveFolder->FileName);
					}
					fileStream = SaveFolder->OpenFile();
					StatusLabel->Text = "Путь к файлу выбран";
					ResultFilePath = FilePath;
				}
				catch (Exception^) {
					StatusLabel->Text = "Ошибка при выборе пути";
				}
				finally {
					if (fileStream != nullptr) {
						fileStream->Close();
					}
					this->SaveFolder->Reset();
				}
			}
		}
		else {
			this->SaveFolder->Filter = "Текстовый документ (*.txt)|*.txt";
			if (this->SaveFolder->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				System::IO::Stream^ fileStream = nullptr;
				try {
					std::string FilePath = msclr::interop::marshal_as<std::string>(this->SaveFolder->FileName);
					if (FilePath.find(".txt", size(FilePath) - 5) == std::string::npos) {
						this->SaveFolder->FileName += ".txt";
						FilePath = msclr::interop::marshal_as<std::string>(this->SaveFolder->FileName);
					}
					fileStream = SaveFolder->OpenFile();
					StatusLabel->Text = "Путь к файлу выбран";
					ResultFilePath = FilePath;
				}
				catch (Exception^) {
					StatusLabel->Text = "Ошибка при выборе пути";
				}
				finally {
					if (fileStream != nullptr) {
						fileStream->Close();
					}
					this->SaveFolder->Reset();
				}
			}
		}
	}


		   //Изменение поля текста в HEX
	private: System::Void FirstTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		TimeLabel->Text = "";
		StatusLabel->Text = "";
		String^ input = FirstTextBox->Text;
		array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(input);
		StringBuilder^ hexString = gcnew StringBuilder();

		for (int i = 0; i < bytes->Length; i++) {
			hexString->Append(bytes[i].ToString("X2"));
			if (i < bytes->Length - 1) {
				hexString->Append(" ");
			}
		}

		FirstHexBox->Text = hexString->ToString();
	}


		   //Изменение поля ключа в HEX
	private: System::Void KeyTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		TimeLabel->Text = "";
		StatusLabel->Text = "";
		String^ input = KeyTextBox->Text;
		array<Byte>^ bytes = System::Text::Encoding::UTF8->GetBytes(input);
		StringBuilder^ hexString = gcnew StringBuilder();

		for (int i = 0; i < bytes->Length; i++) {
			hexString->Append(bytes[i].ToString("X2"));
			if (i < bytes->Length - 1) {
				hexString->Append(" ");
			}
		}

		KeyHexBox->Text = hexString->ToString();
	}



	private: System::Void Encrypt_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Decrypt_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
