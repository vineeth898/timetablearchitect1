#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<list>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
namespace timetablearchitect {
	using namespace std;
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for dept
	/// </summary>
	public ref class dept : public System::Windows::Forms::Form
	{
	public:
		dept(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		std::string converter(System::String^ str) {
			std::string result;
			for (int i = 0; i < str->Length; ++i)
			{
				result += static_cast<char>(str[i]);
			}
			return result;
		}
		void CreateCSVFile(String^ filePath)
		{
			try
			{
				// Open or create a new CSV file for writing
				StreamWriter^ writer = gcnew StreamWriter(filePath);
				writer->Close();

			}
			catch (Exception^ e)
			{
				// Handle any exceptions that might occur while writing the file
				Console::WriteLine("Error creating the file: " + e->Message);
			}
		}

		void csvgen(DataGridView^ dataGridView1, System::String^ filePath) {
			std::ofstream outputFile(msclr::interop::marshal_as<std::string>(filePath));
			if (outputFile.is_open())
			{
				for (int i = 0; i < dataGridView1->RowCount; ++i)
				{
					for (int j = 0; j < dataGridView1->ColumnCount; ++j)
					{
						if (dataGridView1->Rows[i]->Cells[j]->Value != nullptr)
						{
							System::String^ cellvalue = dataGridView1->Rows[i]->Cells[j]->Value->ToString();
							std::string CellValue = converter(cellvalue);
							outputFile << CellValue;
							if (j < dataGridView1->ColumnCount - 1)
							{
								outputFile << ",";
							}
						}outputFile << '\n';
					}
				}outputFile.close();
			}
		}

	protected:

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~dept()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ department;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->department = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->department });
			this->dataGridView1->Location = System::Drawing::Point(669, 273);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(8, 5, 5, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(493, 299);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &dept::dataGridView1_CellContentClick);
			// 
			// department
			// 
			this->department->HeaderText = L"department";
			this->department->MinimumWidth = 30;
			this->department->Name = L"department";
			this->department->Width = 200;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(1357, 804);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(138, 53);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Back";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &dept::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(663, 90);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 37);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enter the departments";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(1119, 804);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 53);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &dept::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(-26, -43);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(328, 1257);
			this->panel1->TabIndex = 8;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Black;
			this->flowLayoutPanel1->Location = System::Drawing::Point(1655, -14);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(319, 1183);
			this->flowLayoutPanel1->TabIndex = 9;
			// 
			// dept
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->ClientSize = System::Drawing::Size(1946, 1106);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"dept";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"dept";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &dept::dept_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ filePath = "dept_file.csv";


	CreateCSVFile(filePath);
	csvgen(dataGridView1, filePath);

}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void dept_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
