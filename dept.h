#pragma once
#include <msclr\marshal_cppstd.h>
#include<vector>
#include<list>
#include<string>
namespace timetablearchitect {
	using namespace std;
	using namespace System;
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
		std::vector<std::vector<std::string>> ConvertDataGridViewToVector(DataGridView^ dataGridView) {
			std::vector<std::vector<std::string>> dataVector;

			// Iterate through DataGridView rows
			for (int i = 0; i < dataGridView->RowCount; i++) {
				std::vector<std::string> rowVector;

				// Iterate through DataGridView columns
				for (int j = 0; j < dataGridView->ColumnCount; j++) {
					// Get cell value as System::Object^
					System::Object^ cellValue = dataGridView->Rows[i]->Cells[j]->Value;

					// Convert System::Object^ to std::string using msclr::interop::marshal_as
					if (cellValue != nullptr) {
						std::string cellStr = msclr::interop::marshal_as<std::string>(cellValue->ToString());
						rowVector.push_back(cellStr);
					}
					else {
						// If cell value is nullptr, push an empty string to vector
						rowVector.push_back("");
					}
				}

				// Push the row vector to the data vector
				dataVector.push_back(rowVector);
			}

			return dataVector;
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ department;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->department });
			this->dataGridView1->Location = System::Drawing::Point(228, 180);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(278, 254);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &dept::dataGridView1_CellContentClick);
			// 
			// department
			// 
			this->department->HeaderText = L"department";
			this->department->MinimumWidth = 8;
			this->department->Name = L"department";
			this->department->Width = 200;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(585, 473);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(130, 38);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Back";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &dept::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(222, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(294, 32);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Enter the departments";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(416, 473);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 38);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &dept::button1_Click);
			// 
			// dept
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(750, 550);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"dept";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"dept";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Form::Close();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	std::vector<std::vector<std::string>> data = ConvertDataGridViewToVector(dataGridView1);

}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
