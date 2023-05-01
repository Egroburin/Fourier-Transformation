#pragma once

namespace FT1d {

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::PictureBox^ pictureBox1;




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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea28 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend28 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series37 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series38 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea29 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend29 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series39 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea30 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend30 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series40 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea28->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea28);
			legend28->Name = L"Legend1";
			this->chart1->Legends->Add(legend28);
			this->chart1->Location = System::Drawing::Point(2, 1);
			this->chart1->Name = L"chart1";
			series37->ChartArea = L"ChartArea1";
			series37->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series37->Legend = L"Legend1";
			series37->Name = L"Series1";
			series38->ChartArea = L"ChartArea1";
			series38->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series38->LabelBorderWidth = 3;
			series38->Legend = L"Legend1";
			series38->MarkerBorderWidth = 3;
			series38->Name = L"Series2";
			this->chart1->Series->Add(series37);
			this->chart1->Series->Add(series38);
			this->chart1->Size = System::Drawing::Size(343, 244);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(688, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 55);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Построить окружность";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(688, 73);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(149, 55);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Обернуть окружность ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(688, 164);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(149, 55);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Построить изначальную функцию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// chart2
			// 
			chartArea29->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea29);
			legend29->Name = L"Legend1";
			this->chart2->Legends->Add(legend29);
			this->chart2->Location = System::Drawing::Point(339, 1);
			this->chart2->Name = L"chart2";
			series39->ChartArea = L"ChartArea1";
			series39->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series39->Legend = L"Legend1";
			series39->Name = L"Series1";
			this->chart2->Series->Add(series39);
			this->chart2->Size = System::Drawing::Size(343, 244);
			this->chart2->TabIndex = 4;
			this->chart2->Text = L"chart2";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(701, 134);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(116, 20);
			this->textBox1->TabIndex = 5;
			// 
			// chart3
			// 
			chartArea30->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea30);
			legend30->Name = L"Legend1";
			this->chart3->Legends->Add(legend30);
			this->chart3->Location = System::Drawing::Point(2, 251);
			this->chart3->Name = L"chart3";
			series40->ChartArea = L"ChartArea1";
			series40->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series40->Legend = L"Legend1";
			series40->Name = L"Series1";
			this->chart3->Series->Add(series40);
			this->chart3->Size = System::Drawing::Size(680, 364);
			this->chart3->TabIndex = 6;
			this->chart3->Text = L"chart3";
			this->chart3->Click += gcnew System::EventHandler(this, &MyForm::chart3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(688, 225);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(149, 55);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Фурье преобразование";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(717, 353);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(192, 56);
			this->button5->TabIndex = 8;
			this->button5->Text = L"imgtest";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(717, 415);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(375, 355);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1354, 755);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void chart3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
};
}
