//
//  MyForm.hpp
//  MarketData
//
//  Created by 汪念怡 on 23/04/16.
//  Copyright (c) 2016 汪念怡. All rights reserved.
//


#include "FetchData.h"
#include "StockGroup.h"
#include "Stock.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <direct.h>
#include "gnuplot_i.hpp"
#include "Handler.h"

namespace FinalProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  buttonGroup1;


	private: array<ProgressBar^>^ pb = gcnew array< ProgressBar^ >(120);
	private: array<BackgroundWorker^>^ threads = gcnew array< BackgroundWorker^ >(120);
	private: System::Windows::Forms::Label^  labelTicker;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		StockGroup *g;
		std::vector<Stock> *sVector;
		int processFinishedCount{ 0 };
		Bitmap^ myImage;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  labalName;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  labelDate;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  labelEPSEstimated;
	private: System::Windows::Forms::Label^  labelEPSReal;
	private: System::Windows::Forms::Panel^  panel2;


	private: System::Windows::Forms::Button^  buttonMenu1;
	private: System::Windows::Forms::Button^  buttonMenu2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  buttonGroup2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  buttonGroup3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  labelEPSSurprise;




	private: System::Windows::Forms::PictureBox^  pictureBox1;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
				 this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
				 this->panel3 = (gcnew System::Windows::Forms::Panel());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->buttonGroup1 = (gcnew System::Windows::Forms::Button());
				 this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
				 this->panel4 = (gcnew System::Windows::Forms::Panel());
				 this->buttonGroup2 = (gcnew System::Windows::Forms::Button());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
				 this->panel5 = (gcnew System::Windows::Forms::Panel());
				 this->buttonGroup3 = (gcnew System::Windows::Forms::Button());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->labelTicker = (gcnew System::Windows::Forms::Label());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->labalName = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->labelDate = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->labelEPSEstimated = (gcnew System::Windows::Forms::Label());
				 this->labelEPSReal = (gcnew System::Windows::Forms::Label());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->labelEPSSurprise = (gcnew System::Windows::Forms::Label());
				 this->buttonMenu1 = (gcnew System::Windows::Forms::Button());
				 this->buttonMenu2 = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 this->tabControl1->SuspendLayout();
				 this->tabPage1->SuspendLayout();
				 this->panel3->SuspendLayout();
				 this->tabPage2->SuspendLayout();
				 this->panel4->SuspendLayout();
				 this->tabPage3->SuspendLayout();
				 this->panel5->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->panel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
				 this->panel2->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Top;
				 this->pictureBox2->Location = System::Drawing::Point(0, 0);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(1184, 97);
				 this->pictureBox2->TabIndex = 5;
				 this->pictureBox2->TabStop = false;
				 // 
				 // tabControl1
				 // 
				 this->tabControl1->Controls->Add(this->tabPage1);
				 this->tabControl1->Controls->Add(this->tabPage2);
				 this->tabControl1->Controls->Add(this->tabPage3);
				 this->tabControl1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->tabControl1->Location = System::Drawing::Point(576, 127);
				 this->tabControl1->Multiline = true;
				 this->tabControl1->Name = L"tabControl1";
				 this->tabControl1->SelectedIndex = 0;
				 this->tabControl1->Size = System::Drawing::Size(608, 634);
				 this->tabControl1->TabIndex = 1;
				 // 
				 // tabPage1
				 // 
				 this->tabPage1->Controls->Add(this->panel3);
				 this->tabPage1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->tabPage1->Location = System::Drawing::Point(4, 30);
				 this->tabPage1->Name = L"tabPage1";
				 this->tabPage1->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage1->Size = System::Drawing::Size(600, 600);
				 this->tabPage1->TabIndex = 0;
				 this->tabPage1->Text = L"Group 1";
				 this->tabPage1->UseVisualStyleBackColor = true;
				 // 
				 // panel3
				 // 
				 this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
					 static_cast<System::Int32>(static_cast<System::Byte>(177)));
				 this->panel3->Controls->Add(this->label7);
				 this->panel3->Controls->Add(this->buttonGroup1);
				 this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
				 this->panel3->Location = System::Drawing::Point(3, 3);
				 this->panel3->Name = L"panel3";
				 this->panel3->Size = System::Drawing::Size(594, 80);
				 this->panel3->TabIndex = 4;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label7->ForeColor = System::Drawing::Color::White;
				 this->label7->Location = System::Drawing::Point(21, 21);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(334, 33);
				 this->label7->TabIndex = 3;
				 this->label7->Text = L"Real EPS > Estimated EPS";
				 // 
				 // buttonGroup1
				 // 
				 this->buttonGroup1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGroup1.BackgroundImage")));
				 this->buttonGroup1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->buttonGroup1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
					 static_cast<System::Int32>(static_cast<System::Byte>(188)), static_cast<System::Int32>(static_cast<System::Byte>(177)));
				 this->buttonGroup1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->buttonGroup1->Location = System::Drawing::Point(398, 5);
				 this->buttonGroup1->Name = L"buttonGroup1";
				 this->buttonGroup1->Size = System::Drawing::Size(160, 70);
				 this->buttonGroup1->TabIndex = 2;
				 this->buttonGroup1->Tag = L"1";
				 this->buttonGroup1->UseVisualStyleBackColor = true;
				 this->buttonGroup1->Click += gcnew System::EventHandler(this, &MyForm::GroupPlot);
				 // 
				 // tabPage2
				 // 
				 this->tabPage2->Controls->Add(this->panel4);
				 this->tabPage2->Location = System::Drawing::Point(4, 30);
				 this->tabPage2->Name = L"tabPage2";
				 this->tabPage2->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage2->Size = System::Drawing::Size(600, 600);
				 this->tabPage2->TabIndex = 1;
				 this->tabPage2->Text = L"Group 2";
				 this->tabPage2->UseVisualStyleBackColor = true;
				 // 
				 // panel4
				 // 
				 this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(167)),
					 static_cast<System::Int32>(static_cast<System::Byte>(85)));
				 this->panel4->Controls->Add(this->buttonGroup2);
				 this->panel4->Controls->Add(this->label8);
				 this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
				 this->panel4->Location = System::Drawing::Point(3, 3);
				 this->panel4->Name = L"panel4";
				 this->panel4->Size = System::Drawing::Size(594, 80);
				 this->panel4->TabIndex = 0;
				 // 
				 // buttonGroup2
				 // 
				 this->buttonGroup2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGroup2.BackgroundImage")));
				 this->buttonGroup2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->buttonGroup2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
					 static_cast<System::Int32>(static_cast<System::Byte>(167)), static_cast<System::Int32>(static_cast<System::Byte>(85)));
				 this->buttonGroup2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->buttonGroup2->Location = System::Drawing::Point(398, 5);
				 this->buttonGroup2->Name = L"buttonGroup2";
				 this->buttonGroup2->Size = System::Drawing::Size(160, 70);
				 this->buttonGroup2->TabIndex = 4;
				 this->buttonGroup2->Tag = L"2";
				 this->buttonGroup2->UseVisualStyleBackColor = true;
				 this->buttonGroup2->Click += gcnew System::EventHandler(this, &MyForm::GroupPlot);
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label8->ForeColor = System::Drawing::Color::White;
				 this->label8->Location = System::Drawing::Point(21, 21);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(334, 33);
				 this->label8->TabIndex = 3;
				 this->label8->Text = L"Real EPS = Estimated EPS";
				 // 
				 // tabPage3
				 // 
				 this->tabPage3->Controls->Add(this->panel5);
				 this->tabPage3->Location = System::Drawing::Point(4, 30);
				 this->tabPage3->Name = L"tabPage3";
				 this->tabPage3->Size = System::Drawing::Size(600, 600);
				 this->tabPage3->TabIndex = 2;
				 this->tabPage3->Text = L"Group 3";
				 this->tabPage3->UseVisualStyleBackColor = true;
				 // 
				 // panel5
				 // 
				 this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
					 static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->panel5->Controls->Add(this->buttonGroup3);
				 this->panel5->Controls->Add(this->label9);
				 this->panel5->Location = System::Drawing::Point(3, 3);
				 this->panel5->Name = L"panel5";
				 this->panel5->Size = System::Drawing::Size(594, 80);
				 this->panel5->TabIndex = 0;
				 // 
				 // buttonGroup3
				 // 
				 this->buttonGroup3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonGroup3.BackgroundImage")));
				 this->buttonGroup3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->buttonGroup3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)),
					 static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(49)));
				 this->buttonGroup3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->buttonGroup3->Location = System::Drawing::Point(398, 5);
				 this->buttonGroup3->Name = L"buttonGroup3";
				 this->buttonGroup3->Size = System::Drawing::Size(160, 70);
				 this->buttonGroup3->TabIndex = 4;
				 this->buttonGroup3->Tag = L"3";
				 this->buttonGroup3->UseVisualStyleBackColor = true;
				 this->buttonGroup3->Click += gcnew System::EventHandler(this, &MyForm::GroupPlot);
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(234)), static_cast<System::Int32>(static_cast<System::Byte>(67)),
					 static_cast<System::Int32>(static_cast<System::Byte>(95)));
				 this->label9->Location = System::Drawing::Point(21, 21);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(334, 33);
				 this->label9->TabIndex = 3;
				 this->label9->Text = L"Real EPS < Estimated EPS";
				 // 
				 // labelTicker
				 // 
				 this->labelTicker->BackColor = System::Drawing::Color::Transparent;
				 this->labelTicker->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->labelTicker->Font = (gcnew System::Drawing::Font(L"Century Gothic", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelTicker->ForeColor = System::Drawing::Color::Black;
				 this->labelTicker->Location = System::Drawing::Point(0, 0);
				 this->labelTicker->Name = L"labelTicker";
				 this->labelTicker->Size = System::Drawing::Size(129, 36);
				 this->labelTicker->TabIndex = 3;
				 this->labelTicker->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pictureBox1->Location = System::Drawing::Point(15, 174);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(545, 371);
				 this->pictureBox1->TabIndex = 4;
				 this->pictureBox1->TabStop = false;
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->labelTicker);
				 this->panel1->Location = System::Drawing::Point(223, 116);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(129, 36);
				 this->panel1->TabIndex = 7;
				 // 
				 // pictureBox4
				 // 
				 this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->pictureBox4->Location = System::Drawing::Point(358, 131);
				 this->pictureBox4->Name = L"pictureBox4";
				 this->pictureBox4->Size = System::Drawing::Size(190, 10);
				 this->pictureBox4->TabIndex = 6;
				 this->pictureBox4->TabStop = false;
				 // 
				 // pictureBox3
				 // 
				 this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->pictureBox3->Location = System::Drawing::Point(27, 131);
				 this->pictureBox3->Name = L"pictureBox3";
				 this->pictureBox3->Size = System::Drawing::Size(190, 10);
				 this->pictureBox3->TabIndex = 6;
				 this->pictureBox3->TabStop = false;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label2->ForeColor = System::Drawing::Color::White;
				 this->label2->Location = System::Drawing::Point(75, 18);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(293, 58);
				 this->label2->TabIndex = 8;
				 this->label2->Text = L"C++ Project";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label3->ForeColor = System::Drawing::Color::White;
				 this->label3->Location = System::Drawing::Point(28, 29);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(71, 22);
				 this->label3->TabIndex = 9;
				 this->label3->Text = L"Name:";
				 // 
				 // labalName
				 // 
				 this->labalName->AutoSize = true;
				 this->labalName->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labalName->ForeColor = System::Drawing::Color::White;
				 this->labalName->Location = System::Drawing::Point(99, 27);
				 this->labalName->Name = L"labalName";
				 this->labalName->Size = System::Drawing::Size(0, 24);
				 this->labalName->TabIndex = 10;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label4->ForeColor = System::Drawing::Color::White;
				 this->label4->Location = System::Drawing::Point(28, 66);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(224, 22);
				 this->label4->TabIndex = 11;
				 this->label4->Text = L"Earning Released Date:";
				 // 
				 // labelDate
				 // 
				 this->labelDate->AutoSize = true;
				 this->labelDate->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelDate->ForeColor = System::Drawing::Color::White;
				 this->labelDate->Location = System::Drawing::Point(255, 64);
				 this->labelDate->Name = L"labelDate";
				 this->labelDate->Size = System::Drawing::Size(0, 24);
				 this->labelDate->TabIndex = 12;
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label5->ForeColor = System::Drawing::Color::White;
				 this->label5->Location = System::Drawing::Point(255, 104);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(139, 22);
				 this->label5->TabIndex = 13;
				 this->label5->Text = L"Estimated EPS:";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label6->ForeColor = System::Drawing::Color::White;
				 this->label6->Location = System::Drawing::Point(28, 104);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(90, 22);
				 this->label6->TabIndex = 14;
				 this->label6->Text = L"Real EPS:";
				 // 
				 // labelEPSEstimated
				 // 
				 this->labelEPSEstimated->AutoSize = true;
				 this->labelEPSEstimated->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelEPSEstimated->ForeColor = System::Drawing::Color::White;
				 this->labelEPSEstimated->Location = System::Drawing::Point(400, 102);
				 this->labelEPSEstimated->Name = L"labelEPSEstimated";
				 this->labelEPSEstimated->Size = System::Drawing::Size(0, 24);
				 this->labelEPSEstimated->TabIndex = 15;
				 // 
				 // labelEPSReal
				 // 
				 this->labelEPSReal->AutoSize = true;
				 this->labelEPSReal->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelEPSReal->ForeColor = System::Drawing::Color::White;
				 this->labelEPSReal->Location = System::Drawing::Point(124, 102);
				 this->labelEPSReal->Name = L"labelEPSReal";
				 this->labelEPSReal->Size = System::Drawing::Size(0, 24);
				 this->labelEPSReal->TabIndex = 16;
				 // 
				 // panel2
				 // 
				 this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->panel2->Controls->Add(this->label10);
				 this->panel2->Controls->Add(this->label3);
				 this->panel2->Controls->Add(this->labelEPSReal);
				 this->panel2->Controls->Add(this->labalName);
				 this->panel2->Controls->Add(this->labelEPSSurprise);
				 this->panel2->Controls->Add(this->labelEPSEstimated);
				 this->panel2->Controls->Add(this->label4);
				 this->panel2->Controls->Add(this->label6);
				 this->panel2->Controls->Add(this->labelDate);
				 this->panel2->Controls->Add(this->label5);
				 this->panel2->Location = System::Drawing::Point(15, 561);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(545, 188);
				 this->panel2->TabIndex = 17;
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label10->ForeColor = System::Drawing::Color::White;
				 this->label10->Location = System::Drawing::Point(28, 141);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(164, 22);
				 this->label10->TabIndex = 17;
				 this->label10->Text = L"Earnings Surprise:";
				 // 
				 // labelEPSSurprise
				 // 
				 this->labelEPSSurprise->AutoSize = true;
				 this->labelEPSSurprise->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->labelEPSSurprise->ForeColor = System::Drawing::Color::White;
				 this->labelEPSSurprise->Location = System::Drawing::Point(201, 139);
				 this->labelEPSSurprise->Name = L"labelEPSSurprise";
				 this->labelEPSSurprise->Size = System::Drawing::Size(0, 24);
				 this->labelEPSSurprise->TabIndex = 15;
				 // 
				 // buttonMenu1
				 // 
				 this->buttonMenu1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->buttonMenu1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonMenu1.BackgroundImage")));
				 this->buttonMenu1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->buttonMenu1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
					 static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->buttonMenu1->FlatAppearance->BorderSize = 0;
				 this->buttonMenu1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->buttonMenu1->Location = System::Drawing::Point(638, 12);
				 this->buttonMenu1->Name = L"buttonMenu1";
				 this->buttonMenu1->Size = System::Drawing::Size(270, 73);
				 this->buttonMenu1->TabIndex = 0;
				 this->buttonMenu1->UseVisualStyleBackColor = false;
				 this->buttonMenu1->Click += gcnew System::EventHandler(this, &MyForm::buttonMenu1_Click);
				 // 
				 // buttonMenu2
				 // 
				 this->buttonMenu2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)), static_cast<System::Int32>(static_cast<System::Byte>(6)),
					 static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->buttonMenu2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonMenu2.BackgroundImage")));
				 this->buttonMenu2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->buttonMenu2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(87)),
					 static_cast<System::Int32>(static_cast<System::Byte>(6)), static_cast<System::Int32>(static_cast<System::Byte>(140)));
				 this->buttonMenu2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				 this->buttonMenu2->Location = System::Drawing::Point(929, 9);
				 this->buttonMenu2->Name = L"buttonMenu2";
				 this->buttonMenu2->Size = System::Drawing::Size(187, 73);
				 this->buttonMenu2->TabIndex = 18;
				 this->buttonMenu2->UseVisualStyleBackColor = false;
				 this->buttonMenu2->Click += gcnew System::EventHandler(this, &MyForm::plotAllCAAR);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::Color::White;
				 this->ClientSize = System::Drawing::Size(1184, 761);
				 this->Controls->Add(this->buttonMenu2);
				 this->Controls->Add(this->buttonMenu1);
				 this->Controls->Add(this->panel2);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->pictureBox4);
				 this->Controls->Add(this->pictureBox3);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->tabControl1);
				 this->Controls->Add(this->pictureBox2);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Name = L"MyForm";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"MyForm";
				 this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 this->tabControl1->ResumeLayout(false);
				 this->tabPage1->ResumeLayout(false);
				 this->panel3->ResumeLayout(false);
				 this->panel3->PerformLayout();
				 this->tabPage2->ResumeLayout(false);
				 this->panel4->ResumeLayout(false);
				 this->panel4->PerformLayout();
				 this->tabPage3->ResumeLayout(false);
				 this->panel5->ResumeLayout(false);
				 this->panel5->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->panel1->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
				 this->panel2->ResumeLayout(false);
				 this->panel2->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	private:void backgroundWorker_DoWork(Object^ sender, DoWorkEventArgs^ e) {
		int index = (int)e->Argument;
		Handler::fillStock(g->getGroup(index / 40 + 1), (*sVector)[index].getTicker());
		e->Result = e->Argument;
	}

	private:void backgroundWorker_RunWorkerCompleted(Object^ sender, RunWorkerCompletedEventArgs^ e) {
		int index = (int)e->Result;
		pb[index]->Value = 100;
		System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;
		myTimer->Tag = index;
		myTimer->Tick += gcnew EventHandler(this, &MyForm::TimerEventProcessor);
		myTimer->Interval = 400;
		myTimer->Start();
		processFinishedCount += 1;

		// Calculate AAR for all groups
		int MAX_STOCK = 120;
		if (processFinishedCount == MAX_STOCK) {
			calculateAAR();
		}
	}

	private: System::Void TimerEventProcessor(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::Timer^ myTimer = safe_cast<System::Windows::Forms::Timer^>(sender);
		myTimer->Stop();
		int tag = safe_cast<int>(myTimer->Tag);
		if (tag < 40) {
			tabPage1->Controls->Remove(pb[tag]);
		}
		else if (tag >= 40 && tag < 80) {
			tabPage2->Controls->Remove(pb[tag]);
		}
		else {
			tabPage3->Controls->Remove(pb[tag]);
		}

	}

	private:void calculateAAR() {
		buttonMenu1->Enabled = TRUE;
		processFinishedCount = 0;

		for (int groupNumber = 1; groupNumber <= 3; groupNumber++) {
			std::vector<double> AARVector(0);
			Stock& s = g->getGroup(groupNumber)[(*sVector)[(groupNumber - 1) * 40].getTicker()];

			while (!s.getAR().empty()) {
				double total{ 0.0 };
				for (int i = 40 * (groupNumber - 1); i < 40 + 40 * (groupNumber - 1); i++)
				{
					Stock& sTemp = g->getGroup(groupNumber)[(*sVector)[i].getTicker()];
					total += sTemp.getAR().top();
					sTemp.getAR().pop();
				}
				AARVector.push_back(total / 40);
			}
			std::reverse(AARVector.begin(), AARVector.end());
			// calculate CAAR
			AARVector.push_back(AARVector[0]);
			for (int i = 1; i < 60; i++)
			{
				AARVector.push_back(AARVector[i + 60 - 1] + AARVector[i]);
			}
			g->matrix.push_back(AARVector);
		}
	}

	private: System::Void buttonMenu1_Click(System::Object^  sender, System::EventArgs^  e) {
		buttonMenu1->Enabled = FALSE;
		for (int i = 0; i < 120; i++)
		{
			int location = i % 40;
			pb[i] = gcnew ProgressBar();
			int x = 150 * (location / 10);
			int y = 100 + 50 * (location % 10);
			pb[i]->Size = System::Drawing::Size(150, 50);
			pb[i]->Location = System::Drawing::Point(x, y);

			Button^ b = gcnew Button;
			b->Tag = i;
			b->Font = gcnew System::Drawing::Font("Century Gothic", 16);
			b->Size = System::Drawing::Size(150, 50);
			b->Location = System::Drawing::Point(x, y);
			b->Text = gcnew String((*sVector)[i].getTicker().c_str());
			b->FlatStyle = FlatStyle::Flat;
			b->Click += gcnew EventHandler(this, &MyForm::b_Click);

			if (i < 40) {
				b->BackColor = Color::FromArgb(255, 42, 188, 177);
				b->ForeColor = Color::White;
				tabPage1->Controls->Add(pb[i]);
				tabPage1->Controls->Add(b);
			}
			else if (i >= 40 && i < 80) {
				b->BackColor = Color::FromArgb(255, 255, 167, 85);
				b->ForeColor = Color::White;
				tabPage2->Controls->Add(pb[i]);
				tabPage2->Controls->Add(b);
			}
			else {
				b->BackColor = Color::FromArgb(255, 5, 20, 49);
				b->ForeColor = Color::FromArgb(255, 234, 67, 95);
				tabPage3->Controls->Add(pb[i]);
				tabPage3->Controls->Add(b);
			}

		}

		for (int i = 0; i < 120; i++)
		{
			threads[i] = gcnew BackgroundWorker;
			threads[i]->DoWork += gcnew DoWorkEventHandler(this, &MyForm::backgroundWorker_DoWork);
			threads[i]->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker_RunWorkerCompleted);
			threads[i]->RunWorkerAsync(i);
		}
	}

	private: System::Void b_Click(System::Object^  sender, System::EventArgs^  e) {
		int index = (int)(safe_cast<Button^>(sender)->Tag);
		Stock stock = (*sVector)[index];
		std::string ticker = stock.getTicker();
		labelTicker->Text = safe_cast<Button^>(sender)->Text;

		if (myImage != nullptr)
		{
			delete myImage;
		}
		std::string filePath = fullPath() + "TempData\\" + ticker + ".png";
		std::ifstream ifile(filePath);
		if (!ifile) {

			std::stack<double> s = g->getGroup(index / 40 + 1)[ticker].getPrice();
			std::vector<double> v;
			while (s.size() != 0) {
				v.push_back(s.top());
				s.pop();
			}
			std::reverse(v.begin(), v.end());
			Gnuplot g1("lines");
			g1.set_title(ticker + " Prices");
			g1.cmd("set terminal png\n");
			g1.cmd("set output '" + fullPath() + "TempData\\" + ticker + ".png'\n");
			g1.plot_x(v);
			g1.reset_all();
			Sleep(400);
		}

		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		myImage = gcnew Bitmap(gcnew String(filePath.c_str()));
		pictureBox1->Image = myImage;

		labalName->Text = gcnew String(stock.getName().c_str());
		labelDate->Text = gcnew String(stock.getDate().c_str());
		labelEPSEstimated->Text = stock.getEPSEstimated().ToString();
		labelEPSReal->Text = stock.getEPSReal().ToString();
		double surprise = (stock.getEPSReal() - stock.getEPSEstimated()) / abs(stock.getEPSEstimated());
		surprise *= 100;
		std::string strSurprise = std::to_string(surprise);
		strSurprise = strSurprise.substr(0, strSurprise.find(".") + 3);
		labelEPSSurprise->Text = gcnew String((strSurprise + " %").c_str());
	}

	private: System::Void GroupPlot(System::Object^  sender, System::EventArgs^  e) {
		int groupNumber = Convert::ToInt32(safe_cast<Button^>(sender)->Tag);
		plotGroupCAAR(groupNumber);
	}

	private:void plotGroupCAAR(int groupNumber) {
		if (g->matrix.size() < 3) {
			MessageBox::Show("Data is not ready! Please hit the download button to download all data required first and wait until the download is finished.");
			return;
		}

		if (myImage != nullptr)
		{
			delete myImage;
		}
		std::string filePath = fullPath() + "TempData\\group" + std::to_string(groupNumber) + ".png";
		std::ifstream ifile(filePath);
		if (!ifile) {
			std::vector<double> vAAR(0);
			std::vector<double> vCAAR(0);
			for (int i = 0; i < 60; i++) {
				vAAR.push_back(g->matrix[groupNumber - 1][i]);
			}
			for (int i = 60; i < 120; i++) {
				vCAAR.push_back(g->matrix[groupNumber - 1][i]);
			}

			std::ofstream outputFile;
			outputFile.open("temp.dat");
			for (int i = 0; i < 60; i++) {
				outputFile << i << "\t" << vAAR[i] << "\t" << vCAAR[i] << std::endl;
			}
			outputFile.close();

			Gnuplot g1("lines");
			g1.remove_tmpfiles();
			g1.set_title("Group" + std::to_string(groupNumber) + "'s AAR & CAAR");
			g1.cmd("set terminal png\n");
			g1.cmd("set output '" + filePath + "'\n");
			g1.cmd("plot 'temp.dat' using 1:2 with lines title 'AAR', 'temp.dat' using 1:3 with lines title 'CAAR''\n");
			g1.reset_all();
			Sleep(400);
		}

		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		myImage = gcnew Bitmap(gcnew String(filePath.c_str()));
		pictureBox1->Image = myImage;

		labelTicker->Text = "Group" + groupNumber.ToString();
		labalName->Text = "";
		labelDate->Text = "";
		labelEPSEstimated->Text = "";
		labelEPSReal->Text = "";
		labelEPSSurprise->Text = "";
	}

	private: System::Void plotAllCAAR(System::Object^  sender, System::EventArgs^  e) {
		if (g->matrix.size() < 3) {
			MessageBox::Show("Data is not ready! Please hit the download button to download all data required first and wait until the download is finished.");
			return;
		}

		if (myImage != nullptr)
		{
			delete myImage;
		}
		std::string filePath = fullPath() + "TempData\\CAAR.png";
		std::ifstream ifile(filePath);
		if (!ifile) {
			std::vector<double> vCAAR1(0);
			std::vector<double> vCAAR2(0);
			std::vector<double> vCAAR3(0);

			for (int i = 60; i < 120; i++) {
				vCAAR1.push_back(g->matrix[0][i]);
			}
			for (int i = 60; i < 120; i++) {
				vCAAR2.push_back(g->matrix[1][i]);
			}
			for (int i = 60; i < 120; i++) {
				vCAAR3.push_back(g->matrix[2][i]);
			}

			std::ofstream outputFile;
			outputFile.open("temp.dat");
			for (int i = 0; i < 60; i++) {
				outputFile << i << "\t" << vCAAR1[i] << "\t" << vCAAR2[i] << "\t" << vCAAR3[i] << std::endl;
			}
			outputFile.close();

			Gnuplot g1("lines");
			g1.remove_tmpfiles();
			g1.set_title("All Group's CAARs");
			g1.cmd("set terminal png\n");
			g1.cmd("set output '" + filePath + "'\n");
			g1.cmd("plot 'temp.dat' using 1:2 with lines title \"Group1's CAAR\", 'temp.dat' using 1:3 with lines title \"Group2's CAAR\", 'temp.dat' using 1:4 with lines title \"Group3's CAAR\"\n");
			g1.reset_all();
			Sleep(400);
		}

		pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		myImage = gcnew Bitmap(gcnew String(filePath.c_str()));
		pictureBox1->Image = myImage;

		labelTicker->Text = "CAAR";
		labalName->Text = "";
		labelDate->Text = "";
		labelEPSEstimated->Text = "";
		labelEPSReal->Text = "";
		labelEPSSurprise->Text = "";
	}

	private:std::string fullPath() {
		char full[_MAX_PATH];
		_fullpath(full, ".\\", _MAX_PATH);
		return full;
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		// Make folder Data to store temporary files
		std::string filePath = fullPath() + "TempData";
		mkdir(filePath.c_str());
		////////////////////////////////////////////

		g = new StockGroup;
		sVector = new std::vector<Stock>;

		Handler::fetchDataFromDatabase(g);

		for (int i = 1; i <= 3; i++) {
			for (auto i : g->getGroup(i)) {
				Stock& s = i.second;
				sVector->push_back(s);
			}
		}
	}

	private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
		delete this->pictureBox1->Image;
		std::string filePath;
		for (auto i : *sVector) {
			filePath = fullPath() + "TempData\\" + i.getTicker() + ".png";
			std::remove(filePath.c_str());
		}
		for (int i = 1; i <= 3; i++) {
			filePath = fullPath() + "TempData\\group" + std::to_string(i) + ".png";
			std::remove(filePath.c_str());
		}
		filePath = fullPath() + "TempData\\CAAR.png";
		std::remove(filePath.c_str());

		delete g;
		delete sVector;
	}


	};
}
