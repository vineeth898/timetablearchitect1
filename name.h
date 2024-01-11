#pragma once
#include "addname.h"
namespace timetablearchitect {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for name
	/// </summary>
	public ref class name : public System::Windows::Forms::Form
	{
	public:
		name(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~name()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(267, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(681, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"add teacher details";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &name::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(267, 294);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(681, 73);
			this->button2->TabIndex = 1;
			this->button2->Text = L"edit teacher deatails";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(267, 461);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(681, 73);
			this->button3->TabIndex = 2;
			this->button3->Text = L"delete teacher deatails";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// name
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"name";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"name";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &name::name_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timetablearchitect::addname^ addname = gcnew timetablearchitect::addname;
		addname->Show();
	}
	private: System::Void name_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
