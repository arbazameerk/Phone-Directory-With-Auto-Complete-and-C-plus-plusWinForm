#pragma once
#include"SEARCHER.h"
#include <string>
#include <chrono>
#include <msclr\marshal_cppstd.h>

namespace WINDOWSFORM1 {

	using namespace std::chrono;
	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		searcher* obj = new searcher();
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			obj->READ_AVL();
			obj->READ_DLL();
			obj->READ_SEARCHER();
		}

		bool search_AVL(node* root, string key)
		{
			if (root == NULL)
				return false;
			else if (root->NAMEAVL == key)
			{
				String^ dataNA = gcnew String(root->NAMEAVL.c_str());
				String^ dataPH = gcnew String(root->PHONENUMBERAVL.c_str());
				dataGrid->Rows->Add(dataNA, dataPH);
				return true;
			}
			else if (root->NAMEAVL > key)
			{
				bool val = search_AVL(root->left, key);
				return val;
			}
			else
			{
				bool val = search_AVL(root->right, key);
				return val;
			}
		}

		void getMatch(node* root, string text)
		{
			for (int i = 0; i < obj->dict.size(); i++)
			{
				if (obj->contains(obj->dict[i], text))
				{
					search_AVL(root, obj->dict[i]);
				}
			}
		}

		void WRITE_NEW(string writePH,string writeNAME)
		{
			ofstream write;
			write.open("DATA.csv", ios::out | ios::app);
			if (!write.is_open())
			{
				//cout << "\n\nCONTACTS FILE NOT FOUND\n\n";
			}
			write << "\n" << writePH << "," << writeNAME;
			write.close();
		}

		void loadGrif()
		{
			string ph, name;
			String^ dataNA;
			String^ dataPH;
			ifstream read;
			read.open("DATA.csv", ios::in);
			string line;
			if (!read.is_open())
			{
				(MessageBox::Show("File open failed\n", "Error in file opening", MessageBoxButtons::OK,
					MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
			}
			while (getline(read, line))
			{
				stringstream ss(line);
				getline(ss, ph, ',');
				getline(ss, name, ',');
				String^ dataNA = gcnew String(name.c_str());
				String^ dataPH = gcnew String(ph.c_str());
				dataGrid->Rows->Add(dataNA, dataPH);
			}
		}

	protected:
		// Clean up any resources being used.
	    ~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ Insert;
	private: System::Windows::Forms::TextBox^ InsertNAME;
	private: System::Windows::Forms::TextBox^ InsertPHNUM;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ DEL_NAME;

	private: System::Windows::Forms::Button^ DELETE_BUTTON;


	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ UpdatePhoneNum;
	private: System::Windows::Forms::TextBox^ UpdateSearch;
	private: System::Windows::Forms::Button^ UpdateButton;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::TextBox^ UpdateName;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ SearchNum;
	private: System::Windows::Forms::Button^ SearchButton;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::DataGridView^ dataGrid;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PhoneNumber;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
private: System::Windows::Forms::Label^ label6;



	protected:



	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Insert = (gcnew System::Windows::Forms::Button());
			this->InsertNAME = (gcnew System::Windows::Forms::TextBox());
			this->InsertPHNUM = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DEL_NAME = (gcnew System::Windows::Forms::TextBox());
			this->DELETE_BUTTON = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->UpdatePhoneNum = (gcnew System::Windows::Forms::TextBox());
			this->UpdateSearch = (gcnew System::Windows::Forms::TextBox());
			this->UpdateButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->UpdateName = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SearchNum = (gcnew System::Windows::Forms::TextBox());
			this->SearchButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PhoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 134);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(29, 36);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 176);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(29, 37);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// Insert
			// 
			this->Insert->BackColor = System::Drawing::Color::DimGray;
			this->Insert->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->Insert->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Insert->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->Insert->Location = System::Drawing::Point(12, 219);
			this->Insert->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Insert->Name = L"Insert";
			this->Insert->Size = System::Drawing::Size(105, 42);
			this->Insert->TabIndex = 2;
			this->Insert->Text = L"Insert";
			this->Insert->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->Insert->UseVisualStyleBackColor = false;
			this->Insert->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click_1);
			// 
			// InsertNAME
			// 
			this->InsertNAME->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InsertNAME->Location = System::Drawing::Point(47, 134);
			this->InsertNAME->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InsertNAME->Name = L"InsertNAME";
			this->InsertNAME->Size = System::Drawing::Size(249, 36);
			this->InsertNAME->TabIndex = 3;
			this->InsertNAME->Text = L"Add Name";
			this->InsertNAME->TextChanged += gcnew System::EventHandler(this, &MyForm::InsertNAME_TextChanged);
			// 
			// InsertPHNUM
			// 
			this->InsertPHNUM->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InsertPHNUM->Location = System::Drawing::Point(47, 176);
			this->InsertPHNUM->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->InsertPHNUM->Name = L"InsertPHNUM";
			this->InsertPHNUM->Size = System::Drawing::Size(249, 36);
			this->InsertPHNUM->TabIndex = 4;
			this->InsertPHNUM->Text = L"Add PhoneNumber";
			this->InsertPHNUM->TextChanged += gcnew System::EventHandler(this, &MyForm::InsertPHNUM_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monoid", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(12, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Add a new contact";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monoid", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(13, 294);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 22);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Delete a existing contact";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// DEL_NAME
			// 
			this->DEL_NAME->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DEL_NAME->Location = System::Drawing::Point(48, 328);
			this->DEL_NAME->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DEL_NAME->Name = L"DEL_NAME";
			this->DEL_NAME->Size = System::Drawing::Size(249, 36);
			this->DEL_NAME->TabIndex = 9;
			this->DEL_NAME->Text = L"Enter name to delete";
			// 
			// DELETE_BUTTON
			// 
			this->DELETE_BUTTON->BackColor = System::Drawing::Color::DimGray;
			this->DELETE_BUTTON->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->DELETE_BUTTON->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DELETE_BUTTON->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->DELETE_BUTTON->Location = System::Drawing::Point(13, 369);
			this->DELETE_BUTTON->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->DELETE_BUTTON->Name = L"DELETE_BUTTON";
			this->DELETE_BUTTON->Size = System::Drawing::Size(105, 42);
			this->DELETE_BUTTON->TabIndex = 8;
			this->DELETE_BUTTON->Text = L"Delete";
			this->DELETE_BUTTON->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->DELETE_BUTTON->UseVisualStyleBackColor = false;
			this->DELETE_BUTTON->Click += gcnew System::EventHandler(this, &MyForm::DELETE_BUTTON_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(13, 328);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(29, 36);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monoid", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(12, 475);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(285, 22);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Update a existing contact";
			// 
			// UpdatePhoneNum
			// 
			this->UpdatePhoneNum->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdatePhoneNum->Location = System::Drawing::Point(47, 593);
			this->UpdatePhoneNum->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UpdatePhoneNum->Name = L"UpdatePhoneNum";
			this->UpdatePhoneNum->Size = System::Drawing::Size(249, 36);
			this->UpdatePhoneNum->TabIndex = 16;
			this->UpdatePhoneNum->Text = L"New PhoneNumber";
			// 
			// UpdateSearch
			// 
			this->UpdateSearch->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdateSearch->Location = System::Drawing::Point(47, 509);
			this->UpdateSearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UpdateSearch->Name = L"UpdateSearch";
			this->UpdateSearch->Size = System::Drawing::Size(249, 36);
			this->UpdateSearch->TabIndex = 15;
			this->UpdateSearch->Text = L"Enter previous name";
			// 
			// UpdateButton
			// 
			this->UpdateButton->BackColor = System::Drawing::Color::DimGray;
			this->UpdateButton->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->UpdateButton->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdateButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->UpdateButton->Location = System::Drawing::Point(12, 636);
			this->UpdateButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UpdateButton->Name = L"UpdateButton";
			this->UpdateButton->Size = System::Drawing::Size(105, 42);
			this->UpdateButton->TabIndex = 14;
			this->UpdateButton->Text = L"Update";
			this->UpdateButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->UpdateButton->UseVisualStyleBackColor = false;
			this->UpdateButton->Click += gcnew System::EventHandler(this, &MyForm::UpdateButton_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 593);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(29, 37);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 13;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(12, 509);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(29, 36);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 12;
			this->pictureBox5->TabStop = false;
			// 
			// UpdateName
			// 
			this->UpdateName->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpdateName->Location = System::Drawing::Point(47, 551);
			this->UpdateName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->UpdateName->Name = L"UpdateName";
			this->UpdateName->Size = System::Drawing::Size(249, 36);
			this->UpdateName->TabIndex = 19;
			this->UpdateName->Text = L"New Name";
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(12, 551);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(29, 36);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 18;
			this->pictureBox6->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Monoid", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(639, 100);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(285, 22);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Search a existing contact";
			// 
			// SearchNum
			// 
			this->SearchNum->Font = (gcnew System::Drawing::Font(L"Segoe Script", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchNum->Location = System::Drawing::Point(674, 134);
			this->SearchNum->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchNum->Name = L"SearchNum";
			this->SearchNum->Size = System::Drawing::Size(249, 36);
			this->SearchNum->TabIndex = 22;
			this->SearchNum->Text = L"Enter name to search";
			// 
			// SearchButton
			// 
			this->SearchButton->BackColor = System::Drawing::Color::DimGray;
			this->SearchButton->Cursor = System::Windows::Forms::Cursors::UpArrow;
			this->SearchButton->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchButton->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->SearchButton->Location = System::Drawing::Point(639, 176);
			this->SearchButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->SearchButton->Name = L"SearchButton";
			this->SearchButton->Size = System::Drawing::Size(105, 42);
			this->SearchButton->TabIndex = 21;
			this->SearchButton->Text = L"Search";
			this->SearchButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageAboveText;
			this->SearchButton->UseVisualStyleBackColor = false;
			this->SearchButton->Click += gcnew System::EventHandler(this, &MyForm::SearchButton_Click);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(639, 134);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(29, 36);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 20;
			this->pictureBox7->TabStop = false;
			// 
			// dataGrid
			// 
			this->dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->Name, this->PhoneNumber });
			this->dataGrid->Location = System::Drawing::Point(639, 219);
			this->dataGrid->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->RowHeadersWidth = 51;
			this->dataGrid->RowTemplate->Height = 24;
			this->dataGrid->Size = System::Drawing::Size(396, 459);
			this->dataGrid->TabIndex = 24;
			// 
			// Name
			// 
			this->Name->HeaderText = L"Name";
			this->Name->MinimumWidth = 6;
			this->Name->Name = L"Name";
			// 
			// PhoneNumber
			// 
			this->PhoneNumber->HeaderText = L"PhoneNumber";
			this->PhoneNumber->MinimumWidth = 6;
			this->PhoneNumber->Name = L"PhoneNumber";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Impact", 28.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(62, 3);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(382, 60);
			this->label5->TabIndex = 25;
			this->label5->Text = L"PHONE DIRECTORY";
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(3, -3);
			this->pictureBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(53, 66);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox8->TabIndex = 26;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Click += gcnew System::EventHandler(this, &MyForm::pictureBox8_Click);
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(750, 179);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(39, 39);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox9->TabIndex = 27;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Click += gcnew System::EventHandler(this, &MyForm::pictureBox9_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Monoid", 7.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(9, 686);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(539, 17);
			this->label6->TabIndex = 28;
			this->label6->Text = L"Created by Arbaz Ameer(20F-0270) and Hammad Afzal(20F-0150)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1083, 712);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->SearchNum);
			this->Controls->Add(this->SearchButton);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->UpdateName);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->UpdatePhoneNum);
			this->Controls->Add(this->UpdateSearch);
			this->Controls->Add(this->UpdateButton);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->DEL_NAME);
			this->Controls->Add(this->DELETE_BUTTON);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->InsertPHNUM);
			this->Controls->Add(this->InsertNAME);
			this->Controls->Add(this->Insert);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			//this->Name = L"MyForm";
			this->Text = L"Phone Directory";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Insert_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void saveFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void DELETE_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
	bool check = false;
	std::string name = marshal_as<std::string>(DEL_NAME->Text);
	if ((name == ""))
	{
		DEL_NAME->Focus();
		(MessageBox::Show("Deletion Failed\nName is missing!\a", "Error in deletion", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else
	{
		auto start = high_resolution_clock::now();
		obj->DEL_SEARCH_AVL(name, obj->root);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "\nTime to delete a single the element in the AVL: " << duration.count() << " microseconds\n" << endl;

		auto start1 = high_resolution_clock::now();
		check=obj->DELETE_DLL(name);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << "\nTime to delete a single the element in the DLL: " << duration1.count() << " microseconds\n" << endl;

		if (obj->search==true && check == true)
		{
			DEL_NAME->Text = "Enter Name to delete";
			(MessageBox::Show("Deletion Succesfull\nContact deleted\a", "Successfull deletion", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
			obj->reWRITE_FILE();
			dataGrid->Rows->Clear();
			dataGrid->Refresh();
			loadGrif();
			obj->search = false;
		}
		else
		{
			(MessageBox::Show("Deletion Failed\nName not found\a", "Error in deletion", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
		}
	}
}
private: System::Void Insert_Click_1(System::Object^ sender, System::EventArgs^ e) {	
	bool check1 = false, check2 = false;
	std::string name = marshal_as<std::string>(InsertNAME->Text);
	std::string phone = marshal_as<std::string>(InsertPHNUM->Text);
	if ((name == "") && (phone == ""))
	{
		InsertNAME->Focus();
		(MessageBox::Show("Insertion Failed\nName and Phone Number are missing!\a", "Error in Insertion", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if ((name == ""))
	{
		InsertNAME->Focus();
		(MessageBox::Show("Insertion Failed\nName is missing!\a", "Error in Insertion", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if((phone == ""))
	{
		InsertPHNUM->Focus();
		(MessageBox::Show("Insertion Failed\nPhone Number is missing!\a", "Error in Insertion", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if (obj->isNumber(phone) == false)
	{
		InsertPHNUM->Focus();
		(MessageBox::Show("Insertion Failed\nPhone Number should be in digits!\a", "Error in Insertion", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else
	{
		auto start = high_resolution_clock::now();
		check1=obj->INSERT_AVL(phone, name);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "\nTime to insert a single the element in the AVL: " << duration.count() << " microseconds\n" << endl;

		auto start1 = high_resolution_clock::now();
		check2=obj->INSERT_DLL(phone, name);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << "\nTime to insert a single the element in the DLL: " << duration1.count() << " microseconds\n" << endl;

		if (check1 == true && check2 == true)
		{
			obj->reWRITE_FILE();
			String^ dataNA = gcnew String(name.c_str());
			String^ dataPH = gcnew String(phone.c_str());
			dataGrid->Rows->Add(dataNA, dataPH);
			
			InsertNAME->Text = "Add Name";
			InsertPHNUM->Text = "Add PhoneNumber";
			obj->dict.push_back(name);
			(MessageBox::Show("Insertion was successfull\a", "Successfully Inserted in AVL && DLL", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
		}
		else
		{
			InsertNAME->Focus();
			(MessageBox::Show("Insertion Failed\nKindly please check again\a", "Error in Insertion", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
		}
	}
}
private: System::Void InsertNAME_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void InsertPHNUM_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	
	auto start = high_resolution_clock::now();
	loadGrif();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "\nTime to insert all the elements in the data grid: " << duration.count() << " microseconds\n" << endl;
}
private: System::Void UpdateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	bool check1 = false, check2 = false;
	std::string Prev_name = marshal_as<std::string>(UpdateSearch->Text);
	std::string name = marshal_as<std::string>(UpdateName->Text);
	std::string phone = marshal_as<std::string>(UpdatePhoneNum->Text);
	if ((name == "") && (phone == "") && Prev_name == "")
	{
		UpdateSearch->Focus();
		(MessageBox::Show("Editing Failed\nPrevious Name, New Name and Phone Number are missing!\a", "Error in updating the contact", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if ((Prev_name == ""))
	{
		UpdateSearch->Focus();
		(MessageBox::Show("Editing Failed\nPrevious Name is missing!\a", "Error in Editing", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if ((name == ""))
	{
		UpdateName->Focus();
		(MessageBox::Show("Editing Failed\nNew Name is missing!\a", "Error in Editing", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if ((phone == ""))
	{
		UpdatePhoneNum->Focus();
		(MessageBox::Show("Editing Failed\nNew Phone Number is missing!\a", "Error in Editing", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else if (obj->isNumber(phone) == false)
	{
		UpdatePhoneNum->Focus();
		(MessageBox::Show("Editing Failed\nPhone Number should be in digits!\a", "Error in Editing", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else
	{
		auto start1 = high_resolution_clock::now();
		check1 = obj->UPDATE_DLL(Prev_name, name, phone);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		
		
		
		auto start = high_resolution_clock::now();
		obj->DEL_SEARCH_AVL(Prev_name, obj->root);
		//check2 = obj->search;
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
	
		
		if (check1 == true)
		{
			obj->INSERT_AVL(phone, name);
			cout << "\nTime to update a single the element in the DLL: " << duration1.count() << " microseconds\n" << endl;
			cout << "\nTime to update a single the element in the AVL: " << duration.count() << " microseconds\n" << endl;
			(MessageBox::Show("Editing Successful\a", "Successfully Updated", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
			obj->reWRITE_FILE();
			dataGrid->Rows->Clear();
			dataGrid->Refresh();
			loadGrif();
			UpdateSearch->Text = "Enter previous name";
			UpdateName->Text = "Enter Name";
			UpdatePhoneNum->Text = "Enter PhoneNumber";
			obj->dict.push_back(name);
			obj->search = false;
		}
		else
		{
			(MessageBox::Show("Editing Failed\nPrevious contact not found\a", "Error in Editing", MessageBoxButtons::OK,
				MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
		}
	}
}
private: System::Void SearchButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string name = marshal_as<std::string>(SearchNum->Text);
	if (name == "")
	{
		SearchNum->Focus();
		(MessageBox::Show("Search Failed\nName should not be empty!\a", "Error in Searching", MessageBoxButtons::OK,
			MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::OK);
	}
	else
	{
		SearchNum->Text = "Enter name to search";
		dataGrid->Rows->Clear();
		dataGrid->Refresh();
		auto start1 = high_resolution_clock::now();
		getMatch(obj->root, name);
		auto stop1 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>(stop1 - start1);
		cout << "\nTime to search a single the element in the AVL: " << duration1.count() << " microseconds\n" << endl;
	}
}
private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) {
	//obj->reWRITE_FILE();
	dataGrid->Rows->Clear();
	dataGrid->Refresh();
	loadGrif();
}
};
}
