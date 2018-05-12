#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <algorithm>
#include<opencv2/opencv.hpp>

namespace Project4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	using namespace std;
	using namespace cv;

	/// <summary>
	/// Summary for NoiseCanceling
	/// </summary>
	public ref class NoiseCanceling : public System::Windows::Forms::Form
	{
	public:
		NoiseCanceling(void)
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
		~NoiseCanceling()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pictureBox13;
	private: System::Windows::Forms::PictureBox^  pictureBox14;
	private: System::Windows::Forms::Label^  label1;
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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Crimson;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(4, 92);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(373, 48);
			this->button4->TabIndex = 33;
			this->button4->Text = L"Browse";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &NoiseCanceling::button4_Click);
			// 
			// pictureBox13
			// 
			this->pictureBox13->Location = System::Drawing::Point(4, 166);
			this->pictureBox13->Name = L"pictureBox13";
			this->pictureBox13->Size = System::Drawing::Size(369, 173);
			this->pictureBox13->TabIndex = 34;
			this->pictureBox13->TabStop = false;
			// 
			// pictureBox14
			// 
			this->pictureBox14->Location = System::Drawing::Point(4, 347);
			this->pictureBox14->Name = L"pictureBox14";
			this->pictureBox14->Size = System::Drawing::Size(369, 173);
			this->pictureBox14->TabIndex = 35;
			this->pictureBox14->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(15, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(358, 31);
			this->label1->TabIndex = 36;
			this->label1->Text = L"Noise Canceling Algorithm";
			// 
			// NoiseCanceling
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(385, 567);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox13);
			this->Controls->Add(this->pictureBox14);
			this->Controls->Add(this->button4);
			this->Name = L"NoiseCanceling";
			this->Text = L"NoiseCanceling";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat src;

		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "Image(*.bmp; *.jpg; *.png)|*.bmp;*.jpg|All files (*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		src = imread(ConvertString2Char(dgOpen->FileName), IMREAD_COLOR);

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileName);
		pictureBox13->Image = bmpSrc;
		pictureBox13->Refresh();

		Mat dst;
		fastNlMeansDenoisingColored(src, dst, 30, 30, 7, 21);

		imwrite("noise_canceling.png", dst);
		Bitmap^ bmpSrc2 = gcnew Bitmap("noise_canceling.png");
		pictureBox14->Image = bmpSrc2;
		pictureBox14->Refresh();
	}

			 private: char* ConvertString2Char(System::String^ str) {
				 char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
				 return str2;
			 }
	};
}
