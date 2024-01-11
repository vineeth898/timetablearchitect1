#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<Windows.h>
#include<msclr\marshal_cppstd.h>
namespace timetablearchitect {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for addname
	/// </summary>
	public ref class addname : public System::Windows::Forms::Form
	{
	public:
		addname(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		vector<vector<string>> ReadCSVFile(const string& filename) {
			ifstream file(filename);
			vector<vector<string>> data;
			string line;

			while (getline(file, line)) {
				stringstream lineStream(line);
				vector<string> row;
				string cell;

				while (getline(lineStream, cell, ',')) {
					row.push_back(cell);
				}

				data.push_back(row);
			}

			return data;
		}
		void DisplayCSVInComboBox(const string& filename, ComboBox^ comboBox) {
			vector<vector<string>> data = ReadCSVFile(filename);

			for (const auto& row : data) {
				string rowString;
				for (const auto& cell : row) {
					rowString += cell + "\t"; // Use tab as delimiter for ComboBox
				}
				String^ rowStringManaged = msclr::interop::marshal_as<String^>(rowString);
				comboBox->Items->Add(rowStringManaged);
			}
		}
		void change(Button^ button)
		{
			if (button->Text == "free") {
				button->Text = "occupied";
			}
			else {
				button->Text = "free";
			}

		}
		


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~addname()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;






	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button19;
	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button21;
	private: System::Windows::Forms::Button^ button22;
	private: System::Windows::Forms::Button^ button23;
	private: System::Windows::Forms::Button^ button24;
	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Button^ button29;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Button^ button33;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;

private: System::Windows::Forms::Button^ button38;
private: System::Windows::Forms::Button^ button39;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::Button^ button37;






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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Location = System::Drawing::Point(2, -55);
			this->panel1->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(287, 2111);
			this->panel1->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(3, 67);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(20, 2500);
			this->panel5->TabIndex = 48;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Black;
			this->panel2->Location = System::Drawing::Point(2912, -25);
			this->panel2->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(524, 2208);
			this->panel2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(352, 45);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(264, 38);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter teacher name";
			this->label1->Click += gcnew System::EventHandler(this, &addname::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(356, 94);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(413, 38);
			this->textBox1->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Location = System::Drawing::Point(359, 131);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(416, 1);
			this->panel3->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(349, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(291, 38);
			this->label2->TabIndex = 5;
			this->label2->Text = L"enter the department";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Black;
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Location = System::Drawing::Point(356, 261);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(485, 1);
			this->panel4->TabIndex = 5;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(353, 216);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(413, 46);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &addname::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(348, 308);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(232, 38);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Teacher schedule";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(359, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 36);
			this->button1->TabIndex = 8;
			this->button1->Text = L"free";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &addname::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(363, 600);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 36);
			this->button2->TabIndex = 9;
			this->button2->Text = L"free";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &addname::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(363, 545);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 36);
			this->button3->TabIndex = 10;
			this->button3->Text = L"free";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &addname::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(359, 488);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 36);
			this->button4->TabIndex = 11;
			this->button4->Text = L"free";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &addname::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(359, 429);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 36);
			this->button5->TabIndex = 12;
			this->button5->Text = L"free";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &addname::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(363, 651);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(112, 36);
			this->button6->TabIndex = 13;
			this->button6->Text = L"free";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &addname::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(505, 376);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(112, 36);
			this->button7->TabIndex = 14;
			this->button7->Text = L"free";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &addname::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(505, 429);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(112, 36);
			this->button8->TabIndex = 15;
			this->button8->Text = L"free";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &addname::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(505, 488);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(112, 36);
			this->button9->TabIndex = 16;
			this->button9->Text = L"free";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &addname::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(505, 545);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(112, 36);
			this->button10->TabIndex = 17;
			this->button10->Text = L"free";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &addname::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(505, 600);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(112, 36);
			this->button11->TabIndex = 18;
			this->button11->Text = L"free";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &addname::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(505, 651);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(112, 36);
			this->button12->TabIndex = 19;
			this->button12->Text = L"free";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &addname::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(652, 651);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(112, 36);
			this->button13->TabIndex = 20;
			this->button13->Text = L"free";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &addname::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(652, 600);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(112, 36);
			this->button14->TabIndex = 21;
			this->button14->Text = L"free";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &addname::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(652, 545);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(112, 36);
			this->button15->TabIndex = 22;
			this->button15->Text = L"free";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &addname::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(652, 488);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(112, 36);
			this->button16->TabIndex = 23;
			this->button16->Text = L"free";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &addname::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(652, 429);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(112, 36);
			this->button17->TabIndex = 24;
			this->button17->Text = L"free";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &addname::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(652, 376);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(112, 36);
			this->button18->TabIndex = 25;
			this->button18->Text = L"free";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &addname::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(794, 651);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(112, 36);
			this->button19->TabIndex = 26;
			this->button19->Text = L"fee";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &addname::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(794, 600);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(112, 36);
			this->button20->TabIndex = 27;
			this->button20->Text = L"free";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &addname::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(794, 545);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(112, 36);
			this->button21->TabIndex = 28;
			this->button21->Text = L"free";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &addname::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(794, 488);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(112, 36);
			this->button22->TabIndex = 29;
			this->button22->Text = L"free";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &addname::button22_Click);
			// 
			// button23
			// 
			this->button23->Location = System::Drawing::Point(794, 429);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(112, 36);
			this->button23->TabIndex = 30;
			this->button23->Text = L"free";
			this->button23->UseVisualStyleBackColor = true;
			this->button23->Click += gcnew System::EventHandler(this, &addname::button23_Click);
			// 
			// button24
			// 
			this->button24->Location = System::Drawing::Point(794, 376);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(112, 36);
			this->button24->TabIndex = 31;
			this->button24->Text = L"free";
			this->button24->UseVisualStyleBackColor = true;
			this->button24->Click += gcnew System::EventHandler(this, &addname::button24_Click);
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(931, 651);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(112, 36);
			this->button25->TabIndex = 32;
			this->button25->Text = L"free";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &addname::button25_Click);
			// 
			// button26
			// 
			this->button26->Location = System::Drawing::Point(931, 600);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(112, 36);
			this->button26->TabIndex = 33;
			this->button26->Text = L"free";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &addname::button26_Click);
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(931, 545);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(112, 36);
			this->button27->TabIndex = 34;
			this->button27->Text = L"free";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &addname::button27_Click);
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(931, 488);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(112, 36);
			this->button28->TabIndex = 35;
			this->button28->Text = L"free";
			this->button28->UseVisualStyleBackColor = true;
			this->button28->Click += gcnew System::EventHandler(this, &addname::button28_Click);
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(931, 429);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(112, 36);
			this->button29->TabIndex = 36;
			this->button29->Text = L"free";
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &addname::button29_Click);
			// 
			// button30
			// 
			this->button30->Location = System::Drawing::Point(931, 376);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(112, 36);
			this->button30->TabIndex = 37;
			this->button30->Text = L"free";
			this->button30->UseVisualStyleBackColor = true;
			this->button30->Click += gcnew System::EventHandler(this, &addname::button30_Click);
			// 
			// button31
			// 
			this->button31->Location = System::Drawing::Point(1073, 651);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(112, 36);
			this->button31->TabIndex = 38;
			this->button31->Text = L"free";
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &addname::button31_Click);
			// 
			// button32
			// 
			this->button32->Location = System::Drawing::Point(1073, 600);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(112, 36);
			this->button32->TabIndex = 39;
			this->button32->Text = L"free";
			this->button32->UseVisualStyleBackColor = true;
			this->button32->Click += gcnew System::EventHandler(this, &addname::button32_Click);
			// 
			// button33
			// 
			this->button33->Location = System::Drawing::Point(1073, 545);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(112, 36);
			this->button33->TabIndex = 40;
			this->button33->Text = L"free";
			this->button33->UseVisualStyleBackColor = true;
			this->button33->Click += gcnew System::EventHandler(this, &addname::button33_Click);
			// 
			// button34
			// 
			this->button34->Location = System::Drawing::Point(1073, 488);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(112, 36);
			this->button34->TabIndex = 41;
			this->button34->Text = L"free";
			this->button34->UseVisualStyleBackColor = true;
			this->button34->Click += gcnew System::EventHandler(this, &addname::button34_Click);
			// 
			// button35
			// 
			this->button35->Location = System::Drawing::Point(1073, 429);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(112, 36);
			this->button35->TabIndex = 42;
			this->button35->Text = L"free";
			this->button35->UseVisualStyleBackColor = true;
			this->button35->Click += gcnew System::EventHandler(this, &addname::button35_Click);
			// 
			// button36
			// 
			this->button36->Location = System::Drawing::Point(1073, 376);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(112, 36);
			this->button36->TabIndex = 43;
			this->button36->Text = L"free";
			this->button36->UseVisualStyleBackColor = true;
			this->button36->Click += gcnew System::EventHandler(this, &addname::button36_Click);
			// 
			// button38
			// 
			this->button38->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button38->Location = System::Drawing::Point(1038, 858);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(138, 53);
			this->button38->TabIndex = 45;
			this->button38->Text = L"Exit";
			this->button38->UseVisualStyleBackColor = true;
			this->button38->Click += gcnew System::EventHandler(this, &addname::button38_Click);
			// 
			// button39
			// 
			this->button39->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button39->Location = System::Drawing::Point(878, 858);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(138, 53);
			this->button39->TabIndex = 46;
			this->button39->Text = L"Back";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &addname::button39_Click);
			// 
			// button37
			// 
			this->button37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button37->Location = System::Drawing::Point(718, 858);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(138, 53);
			this->button37->TabIndex = 47;
			this->button37->Text = L"Save";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &addname::button37_Click);
			// 
			// addname
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 38);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->ClientSize = System::Drawing::Size(1924, 1050);
			this->Controls->Add(this->button37);
			this->Controls->Add(this->button39);
			this->Controls->Add(this->button38);
			this->Controls->Add(this->button36);
			this->Controls->Add(this->button35);
			this->Controls->Add(this->button34);
			this->Controls->Add(this->button33);
			this->Controls->Add(this->button32);
			this->Controls->Add(this->button31);
			this->Controls->Add(this->button30);
			this->Controls->Add(this->button29);
			this->Controls->Add(this->button28);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->button24);
			this->Controls->Add(this->button23);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"addname";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Teacher schedule";
			this->Load += gcnew System::EventHandler(this, &addname::addname_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void addname_Load(System::Object^ sender, System::EventArgs^ e) {
		string filePath = "dept_file.csv";

		DisplayCSVInComboBox(filePath,comboBox1);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button13);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button1);

}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button7);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button5);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button4);
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button3);
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button2);
}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		change(button6);
	}
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
	Form::Close();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button8);
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button9);
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button10);
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button11);
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button12);
}
private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button18);
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button17);
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button16);
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button15);
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button14);
}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button24);
}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button23);
}
private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button22);
}
private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button21);
}
private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button20);
}
private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button19);
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button30);
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button29);
}
private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button28);
}
private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button27);
}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button26);
}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button25);
}
private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button36);
}
private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button35);
}
private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button34);
}
private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button33);
}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button32);
}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	change(button31);
}
private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	//important
}
};
}
