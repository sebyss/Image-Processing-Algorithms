#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>  // we need add one more lib file imgproc

#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <algorithm>
#include<opencv2/opencv.hpp>

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <vector>

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
	/// Summary for MyForm2
	/// </summary>
	public ref class FloydSteinberg : public System::Windows::Forms::Form
	{
	public:
		FloydSteinberg(void)
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
		~FloydSteinberg()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  ptbSrc2;
	private: System::Windows::Forms::PictureBox^  ptbSource;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ptbSrc2 = (gcnew System::Windows::Forms::PictureBox());
			this->ptbSource = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSrc2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Crimson;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(20, 143);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(299, 48);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FloydSteinberg::button1_Click);
			// 
			// ptbSrc2
			// 
			this->ptbSrc2->Location = System::Drawing::Point(20, 427);
			this->ptbSrc2->Name = L"ptbSrc2";
			this->ptbSrc2->Size = System::Drawing::Size(297, 176);
			this->ptbSrc2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ptbSrc2->TabIndex = 4;
			this->ptbSrc2->TabStop = false;
			// 
			// ptbSource
			// 
			this->ptbSource->Location = System::Drawing::Point(22, 231);
			this->ptbSource->Name = L"ptbSource";
			this->ptbSource->Size = System::Drawing::Size(297, 173);
			this->ptbSource->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ptbSource->TabIndex = 3;
			this->ptbSource->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(4, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(346, 80);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Floyd Steinberg Dithering             Algorithm";
			// 
			// FloydSteinberg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(345, 615);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ptbSrc2);
			this->Controls->Add(this->ptbSource);
			this->Controls->Add(this->button1);
			this->Name = L"FloydSteinberg";
			this->Text = L"FloydSteinberg";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSrc2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbSource))->EndInit();
			this->ResumeLayout(false);

		}



#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		cv::Mat src;

		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "Image(*.bmp; *.jpg)|*.bmp;*.jpg|All files (*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileName);
		ptbSource->Image = bmpSrc;
		ptbSource->Refresh();

		src = imread(ConvertString2Char(dgOpen->FileName));

		cv::Mat dithImg;
		int imgWidth;
		int imgHeight;


		cvtColor(src, dithImg, CV_BGR2GRAY);

		/* Get the size info */
		imgWidth = dithImg.cols;
		imgHeight = dithImg.rows;


		/* Run the 'Floyd-Steinberg' dithering algorithm ... */
		int err;
		int8_t a, b, c, d;

		for (int i = 0; i < imgHeight; i++)
		{
			for (int j = 0; j < imgWidth; j++)
			{
				if (dithImg.at<uint8_t>(i, j) > 127)
				{
					err = dithImg.at<uint8_t>(i, j) - 255;
					dithImg.at<uint8_t>(i, j) = 255;
				}
				else
				{
					err = dithImg.at<uint8_t>(i, j) - 0;
					dithImg.at<uint8_t>(i, j) = 0;
				}

				a = (err * 7) / 16;
				b = (err * 1) / 16;
				c = (err * 5) / 16;
				d = (err * 3) / 16;

				if ((i != (imgHeight - 1)) && (j != 0) && (j != (imgWidth - 1)))
				{
					dithImg.at<uint8_t>(i + 0, j + 1) = saturated_add(dithImg.at<uint8_t>(i + 0, j + 1), a);
					dithImg.at<uint8_t>(i + 1, j + 1) = saturated_add(dithImg.at<uint8_t>(i + 1, j + 1), b);
					dithImg.at<uint8_t>(i + 1, j + 0) = saturated_add(dithImg.at<uint8_t>(i + 1, j + 0), c);
					dithImg.at<uint8_t>(i + 1, j - 1) = saturated_add(dithImg.at<uint8_t>(i + 1, j - 1), d);
				}
			}
		}


		imwrite("test.jpg", dithImg);

		Bitmap^ bmpSrc2 = gcnew Bitmap("test.jpg");
		ptbSrc2->Image = bmpSrc2;
		ptbSrc2->Refresh();
	
			 
	
}

			 private: char* ConvertString2Char(System::String^ str) {
				 char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
				 return str2;
			 }


					  uint8_t saturated_add(uint8_t val1, int8_t val2)
					  {
						  int16_t val1_int = val1;
						  int16_t val2_int = val2;
						  int16_t tmp = val1_int + val2_int;

						  if (tmp > 255)
						  {
							  return 255;
						  }
						  else if (tmp < 0)
						  {
							  return 0;
						  }
						  else
						  {
							  return tmp;
						  }
					  }

	};
}
