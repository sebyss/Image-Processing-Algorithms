#pragma once

#include "TraceBoundaryPoints.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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
	/// Summary for ContourTracing
	/// </summary>
	public ref class ContourTracing : public System::Windows::Forms::Form
	{
	public:
		ContourTracing(void)
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
		~ContourTracing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::PictureBox^  pictureBox16;
	private: System::Windows::Forms::PictureBox^  pictureBox15;
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
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Crimson;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::SteelBlue;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(6, 81);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(365, 48);
			this->button5->TabIndex = 35;
			this->button5->Text = L"Browse";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ContourTracing::button5_Click);
			// 
			// pictureBox16
			// 
			this->pictureBox16->Location = System::Drawing::Point(6, 335);
			this->pictureBox16->Name = L"pictureBox16";
			this->pictureBox16->Size = System::Drawing::Size(369, 173);
			this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox16->TabIndex = 37;
			this->pictureBox16->TabStop = false;
			// 
			// pictureBox15
			// 
			this->pictureBox15->Location = System::Drawing::Point(6, 157);
			this->pictureBox15->Name = L"pictureBox15";
			this->pictureBox15->Size = System::Drawing::Size(369, 172);
			this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox15->TabIndex = 36;
			this->pictureBox15->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(17, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(355, 31);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Contour Tracing Algorithm";
			// 
			// ContourTracing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(383, 524);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox16);
			this->Controls->Add(this->pictureBox15);
			this->Controls->Add(this->button5);
			this->Name = L"ContourTracing";
			this->Text = L"ContourTracing";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat src;

		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "Image(*.bmp; *.jpg; *.png)|*.bmp;*.jpg|All files (*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileName);
		pictureBox15->Image = bmpSrc;
		pictureBox15->Refresh();

		src = imread(ConvertString2Char(dgOpen->FileName), 0);
		Mat imgDisplay = imread(ConvertString2Char(dgOpen->FileName), 1);


		unsigned char* pInputImage = src.data;
		TraceBoundaryPoints boundObj;
		vector<Point2D> BoundaryPoints;
		boundObj.GetContinousBoundaryPoints(pInputImage, src.cols, src.rows, BoundaryPoints);
		int Ind = 0;
		for (;Ind < BoundaryPoints.size() - 1; Ind++)
		{
			line(imgDisplay, cv::Point(BoundaryPoints[Ind].X, BoundaryPoints[Ind].Y),
				cv::Point(BoundaryPoints[Ind + 1].X, BoundaryPoints[Ind + 1].Y), Scalar(0, 0, 255), 2);
		}
		line(imgDisplay, cv::Point(BoundaryPoints[Ind].X, BoundaryPoints[Ind].Y),
			cv::Point(BoundaryPoints[0].X, BoundaryPoints[0].Y), Scalar(0, 0, 255), 2);


		imwrite("contour_tracing.png", imgDisplay);

		Bitmap^ bmpSrc2 = gcnew Bitmap("contour_tracing.png");
		pictureBox16->Image = bmpSrc2;
		pictureBox16->Refresh();

	}
			 private: char* ConvertString2Char(System::String^ str) {
				 char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
				 return str2;
			 }
	};
}
