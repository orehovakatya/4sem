#pragma once
#include <vector>
#include"Header.h"
#include<list>



namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Panel^  panel2;






	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(998, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(312, 56);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Координаты прямоугольника\r\n(по порядку)";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(1002, 96);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(259, 105);
			this->dataGridView1->TabIndex = 1;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"X";
			this->Column1->MinimumWidth = 100;
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Y";
			this->Column2->MinimumWidth = 100;
			this->Column2->Name = L"Column2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(998, 204);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 22);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Множество точек";
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column3,
					this->Column4
			});
			this->dataGridView2->Location = System::Drawing::Point(1002, 249);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 28;
			this->dataGridView2->Size = System::Drawing::Size(259, 111);
			this->dataGridView2->TabIndex = 3;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"X";
			this->Column3->MinimumWidth = 100;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Y";
			this->Column4->MinimumWidth = 100;
			this->Column4->Name = L"Column4";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1054, 366);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 45);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Нарисовать";
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Location = System::Drawing::Point(24, 18);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(900, 600);
			this->panel1->TabIndex = 5;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(965, 417);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(205, 24);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Показать координаты";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(965, 469);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(358, 231);
			this->panel2->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1344, 712);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MaximumSize = System::Drawing::Size(1366, 768);
			this->MinimumSize = System::Drawing::Size(1366, 768);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Лабораторная работа по КГ №1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
private: System::Void dataGridView1_CellContentClick_1(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	panel1->Refresh();
	panel2->Refresh();
	bool flag = checkBox1->Checked;
	//MessageBox::Show(Convert::ToString(flag));
	//Границы
	float left_x;
	float left_y;
	float right_x;
	float right_y;

	//Коэффициенты для масштабирования
	float kx;
	float ky;

	std::vector<PointF*> Rectangle1;//точки прямоугольника
	std::vector<PointF*> Rectangle_draw;//Точки прямоугольника для рисования
	std::vector<PointF*> Points;//Множество точек
	std::vector<PointF*> Points_draw;//Множество точек для рисования

	std::vector<std::vector<int>> Triangle;//Набор треугольников

	PointF Center;//Центр прямоугольника
	PointF Center_draw;

	Graphics^ g = panel1->CreateGraphics();
	Graphics^ otv = panel2->CreateGraphics();
	Pen^ pen1 = gcnew Pen(Color::Black, 1);//Чёрный карандаш в 1 пиксель
	Pen^ pen_red = gcnew Pen(Color::Red, 1);//Красный карандаш в 1 пиксель
	Pen^ pen_beige = gcnew Pen(Color::Yellow, 1);//Бежевый карандаш в 1 пиксель
	Pen^ pen_green = gcnew Pen(Color::Green, 1);

	//Заполнение точек ПРЯМОУГОЛЬНИКА
	for (int i = 0; i < dataGridView1->RowCount-1; i++) {
		double x = Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value);
		double y = (Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value));
		Rectangle1.push_back(new PointF((float)x,(float)y));
	}
	

	//Заполнение МНОЖЕСТВА точек
	for (int i = 0; i < dataGridView2->RowCount - 1; i++) {
		double x = Convert::ToDouble(dataGridView2->Rows[i]->Cells[0]->Value);
		double y = (Convert::ToDouble(dataGridView2->Rows[i]->Cells[1]->Value));
		Points.push_back(new PointF((float)x, (float)y));
	}
	

	//MessageBox::Show(Convert::ToString(Points.size()));

	//Проверки для прямоугольника
	if (Rectangle1.size() != 4) {
		MessageBox::Show("Недопустимое количество вершин для прямоугольника.");
		return;
	}
	if ((((Rectangle1[0]->X != Rectangle1[1]->X) || (Rectangle1[0]->Y != Rectangle1[3]->Y))||
		((Rectangle1[2]->X != Rectangle1[3]->X) || (Rectangle1[2]->Y != Rectangle1[1]->Y)))&& 
		(((Rectangle1[3]->X != Rectangle1[0]->X) || (Rectangle1[3]->Y != Rectangle1[2]->Y)) ||
		((Rectangle1[1]->X != Rectangle1[2]->X) || (Rectangle1[1]->Y != Rectangle1[0]->Y)))) {
		MessageBox::Show("Прямоугольник задан неправильно.");
		return;
	}

	if (((Rectangle1[1]->X == Rectangle1[2]->X) && (Rectangle1[2]->X == Rectangle1[3]->X)) &&
		((Rectangle1[3]->X == Rectangle1[4]->X) && (Rectangle1[4]->X == Rectangle1[1]->X)))
	{
		MessageBox::Show("Прямоугольник задан неправильно");
		return;
	}
	if (Points.size() < 3) {
		MessageBox::Show("Недостаточно точек для постоения треугольника.");
		return;
	}

	found_bourder(Rectangle1, Points, &left_x, &left_y, &right_x, &right_y);
	kx = 850/(right_x - left_x);
	ky = 550/(right_y - left_y);

	Center = found_center(Rectangle1);//Нахождение центра прямоугольника
	
	vector_copy(Rectangle1, Rectangle_draw);
	//Rectangle_draw = Rectangle1;
	vector_copy(Points, Points_draw);
	//Points_draw = Points;


	if (found_triangle(Points, &Triangle) == 0)
	{
		MessageBox::Show("Треугольник построить не удалось");
	}
	min_arc(Triangle, Points, Center, g, left_x, left_y, right_x, right_y,kx, ky, flag, otv);





	//Масштабирование координат
	for (int i = 0; i < Rectangle_draw.size(); i++)
	{
		Rectangle_draw[i]->X = (Rectangle_draw[i]->X - left_x)*kx;
		Rectangle_draw[i]->Y = 550-(Rectangle_draw[i]->Y - left_y)*ky;
	}
	for (int i = 0; i < Points_draw.size(); i++)
	{
		Points_draw[i]->X = (Points_draw[i]->X - left_x)*kx;
		Points_draw[i]->Y = 550-(Points_draw[i]->Y - left_y)*ky;
	}
	Center_draw.X = (Center.X - left_x)*kx;
	Center_draw.Y = 550-(Center.Y - left_y)*ky;

	//Рисование прямоугольника
	g->DrawLine(pen1, *Rectangle_draw[0], *Rectangle_draw[1]);
	g->DrawLine(pen1, *Rectangle_draw[1], *Rectangle_draw[2]);
	g->DrawLine(pen1, *Rectangle_draw[2], *Rectangle_draw[3]);
	g->DrawLine(pen1, *Rectangle_draw[3], *Rectangle_draw[0]);

	System::Drawing::Font^ ft = gcnew System::Drawing::Font("Verdana", 10);
	
	if (flag)
	{
		g->DrawString(Convert::ToString(Rectangle1[0]->X) + ";" + 
			Convert::ToString(Rectangle1[0]->Y), ft, System::Drawing::Brushes::Black,
			Rectangle_draw[0]->X, Rectangle_draw[0]->Y);

		g->DrawString(Convert::ToString(Rectangle1[1]->X) + ";" +
			Convert::ToString(Rectangle1[1]->Y), ft, System::Drawing::Brushes::Black,
			Rectangle_draw[1]->X, Rectangle_draw[1]->Y);

		g->DrawString(Convert::ToString(Rectangle1[2]->X) + ";" +
			Convert::ToString(Rectangle1[2]->Y), ft, System::Drawing::Brushes::Black,
			Rectangle_draw[2]->X, Rectangle_draw[2]->Y);

		g->DrawString(Convert::ToString(Rectangle1[3]->X) + ";" +
			Convert::ToString(Rectangle1[3]->Y), ft, System::Drawing::Brushes::Black,
			Rectangle_draw[3]->X, Rectangle_draw[3]->Y);
	}

	//Рисование диагоналей
	g->DrawLine(pen_beige, *Rectangle_draw[0], *Rectangle_draw[2]);
	g->DrawLine(pen_beige, *Rectangle_draw[1], *Rectangle_draw[3]);

	//Рисование середины прямоугольника
	g->DrawEllipse(pen1, Center_draw.X, Center_draw.Y, 3.0, 3.0);//
	if (flag)
		g->DrawString(Convert::ToString(Center.X) + ";" +
			Convert::ToString(Center.Y), ft, System::Drawing::Brushes::Black,
			Center_draw.X, Center_draw.Y);

	//Рисование точек мн-ва треугольников
	if (flag)
	for (int i = 0; i < Points_draw.size(); i++)
	{
		g->DrawEllipse(pen_green, Points_draw[i]->X, Points_draw[i]->Y, 2.0, 2.0);
		g->DrawString(Convert::ToString(Points[i]->X) + ";" +
			Convert::ToString(Points[i]->Y), ft, System::Drawing::Brushes::Green,
			Points_draw[i]->X, Points_draw[i]->Y);
	}
	else
		for (int i = 0; i < Points_draw.size(); i++)
			g->DrawEllipse(pen_green, Points_draw[i]->X, Points_draw[i]->Y, 2.0, 2.0);
}
};
}
