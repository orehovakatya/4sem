#pragma once
#include "Model.h"
#include "Drawing.h"
#include "Processor.h"
namespace ооп {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(27, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(764, 569);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(897, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 94);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Загрузить модель";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1027, 191);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Повернуть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(797, 195);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(45, 26);
			this->textBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(868, 195);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(45, 26);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(934, 195);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(45, 26);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(934, 280);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(45, 26);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(868, 280);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(45, 26);
			this->textBox5->TabIndex = 8;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(797, 280);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(45, 26);
			this->textBox6->TabIndex = 7;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1027, 276);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(139, 35);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Переместить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(797, 361);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(45, 26);
			this->textBox7->TabIndex = 11;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(868, 352);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 35);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Масштб";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(810, 172);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 20);
			this->label2->TabIndex = 13;
			this->label2->Text = L"x";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(881, 172);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 20);
			this->label3->TabIndex = 14;
			this->label3->Text = L"y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(947, 172);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 20);
			this->label4->TabIndex = 15;
			this->label4->Text = L"z";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(947, 255);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 20);
			this->label5->TabIndex = 18;
			this->label5->Text = L"z";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(881, 255);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(16, 20);
			this->label6->TabIndex = 17;
			this->label6->Text = L"y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(810, 255);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 20);
			this->label7->TabIndex = 16;
			this->label7->Text = L"x";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1178, 594);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->MaximumSize = System::Drawing::Size(1200, 650);
			this->MinimumSize = System::Drawing::Size(1200, 650);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Graphics^ g;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		argument arg;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			arg.load_act = (char*)(void*)Marshal::StringToHGlobalAnsi(openFileDialog1->FileName);
			processor(arg, LOAD, g);
			processor(arg, DRAW, g);
		}
	}
	private: System::Void MyForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		g = pictureBox1->CreateGraphics();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		double x = Convert::ToDouble(textBox1->Text);
		double y = Convert::ToDouble(textBox2->Text);
		double z = Convert::ToDouble(textBox3->Text);
		argument arg;
		action_values act;
		clean_action(act);
		act.angleOX = x;
		act.angleOY = y;
		act.angleOZ = z;
		arg.modify_act = act;
		processor(arg, CHANGE, g);
		processor(arg, DRAW, g);
	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	double x = Convert::ToDouble(textBox6->Text);
	double y = Convert::ToDouble(textBox5->Text);
	double z = Convert::ToDouble(textBox4->Text);
	argument arg;
	action_values act;
	clean_action(act);
	act.moveOX = x;
	act.moveOY = y;
	act.moveOZ = z;
	arg.modify_act = act;
	processor(arg, CHANGE, g);
	processor(arg, DRAW, g);
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	//double x = Convert::ToInt32(textBox7->Text);
	double x = Convert::ToDouble(textBox7->Text);
	argument arg;
	action_values act;
	clean_action(act);
	act.scale = x;
	arg.modify_act = act;
	processor(arg, CHANGE, g);
	processor(arg, DRAW, g);
}
};
}
