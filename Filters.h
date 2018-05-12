#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>  // we need add one more lib file imgproc

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
	/// Summary for Filters
	/// </summary>
	public ref class Filters : public System::Windows::Forms::Form
	{
	public:
		Filters(void)
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
		~Filters()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::PictureBox^  pictureBox11;
	private: System::Windows::Forms::PictureBox^  pictureBox12;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label1;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Crimson;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(490, 23);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(373, 48);
			this->button3->TabIndex = 33;
			this->button3->Text = L"Browse";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Filters::button3_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(14, 113);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(315, 399);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 34;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(335, 113);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(368, 399);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 35;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(711, 113);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(320, 399);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 36;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(1039, 113);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(375, 399);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox6->TabIndex = 37;
			this->pictureBox6->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::DarkRed;
			this->label6->Location = System::Drawing::Point(81, 97);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 13);
			this->label6->TabIndex = 41;
			this->label6->Text = L"Original";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::DarkRed;
			this->label5->Location = System::Drawing::Point(1173, 97);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(58, 13);
			this->label5->TabIndex = 40;
			this->label5->Text = L"Band Pass";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::DarkRed;
			this->label4->Location = System::Drawing::Point(830, 97);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 13);
			this->label4->TabIndex = 39;
			this->label4->Text = L"High Pass";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::DarkRed;
			this->label3->Location = System::Drawing::Point(453, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 13);
			this->label3->TabIndex = 38;
			this->label3->Text = L"Low Pass";
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(12, 536);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(315, 311);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox7->TabIndex = 42;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Location = System::Drawing::Point(335, 536);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(368, 311);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 43;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Location = System::Drawing::Point(711, 536);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(320, 311);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 44;
			this->pictureBox9->TabStop = false;
			// 
			// pictureBox10
			// 
			this->pictureBox10->Location = System::Drawing::Point(1039, 536);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(375, 311);
			this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox10->TabIndex = 45;
			this->pictureBox10->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->ForeColor = System::Drawing::Color::DarkRed;
			this->label10->Location = System::Drawing::Point(119, 520);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 13);
			this->label10->TabIndex = 49;
			this->label10->Text = L"Gaussian";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->ForeColor = System::Drawing::Color::DarkRed;
			this->label9->Location = System::Drawing::Point(1202, 517);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 13);
			this->label9->TabIndex = 48;
			this->label9->Text = L"Band Pass Mask";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->ForeColor = System::Drawing::Color::DarkRed;
			this->label8->Location = System::Drawing::Point(830, 517);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 13);
			this->label8->TabIndex = 47;
			this->label8->Text = L"High Pass Mask";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::DarkRed;
			this->label7->Location = System::Drawing::Point(468, 517);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(82, 13);
			this->label7->TabIndex = 46;
			this->label7->Text = L"Low Pass Mask";
			// 
			// pictureBox11
			// 
			this->pictureBox11->Location = System::Drawing::Point(14, 874);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(677, 286);
			this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox11->TabIndex = 50;
			this->pictureBox11->TabStop = false;
			// 
			// pictureBox12
			// 
			this->pictureBox12->Location = System::Drawing::Point(728, 874);
			this->pictureBox12->Name = L"pictureBox12";
			this->pictureBox12->Size = System::Drawing::Size(678, 286);
			this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox12->TabIndex = 51;
			this->pictureBox12->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->ForeColor = System::Drawing::Color::DarkRed;
			this->label12->Location = System::Drawing::Point(1020, 858);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 13);
			this->label12->TabIndex = 53;
			this->label12->Text = L"Spectrum";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->ForeColor = System::Drawing::Color::DarkRed;
			this->label11->Location = System::Drawing::Point(280, 855);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(80, 13);
			this->label11->TabIndex = 52;
			this->label11->Text = L"Gaussian Mask";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(151, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 31);
			this->label1->TabIndex = 54;
			this->label1->Text = L"Filters";
			// 
			// Filters
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(1440, 1061);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox12);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->button3);
			this->Name = L"Filters";
			this->Text = L"Filters";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat src;

		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "Image(*.bmp; *.jpg; *.png)|*.bmp;*.jpg|All files (*.*)|*.*||";

		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileName);
		pictureBox3->Image = bmpSrc;
		pictureBox3->Refresh();

		src = imread(ConvertString2Char(dgOpen->FileName), CV_LOAD_IMAGE_GRAYSCALE);


		Mat padded;                            //expand input image to optimal size
		int m = getOptimalDFTSize(src.rows);
		int n = getOptimalDFTSize(src.cols); // on the border add zero values
		copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, BORDER_CONSTANT, Scalar::all(0));

		Mat planes[] = { Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F) };
		Mat complexI;

		merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

		dft(complexI, complexI);            // this way the result may fit in the source matrix



		split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
		magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
		Mat magI = planes[0];

		magI += Scalar::all(1);                    // switch to logarithmic scale
		log(magI, magI);

		shift(magI);

		normalize(magI, magI, 0, 1, CV_MINMAX); // Transform the matrix with float values into a
												// viewable image form (float between values 0 and 1).



		Mat1b save_0b;
		normalize(magI, save_0b, 255, 0, NORM_MINMAX);
		imwrite("spectrum magnitude.png", save_0b);
		Bitmap^ bmpSrc0 = gcnew Bitmap("spectrum magnitude.png");
		pictureBox12->Image = bmpSrc0;
		pictureBox12->Refresh();


		/*    Generating Filter Masks, Multiplying with DFT's of image with DFT of mask and then calculating IDFT and displaying   */
		Mat complexILowPass = complexI.clone();
		Mat complexIHighPass = complexI.clone();
		Mat complexIBandPass = complexI.clone();
		Mat complexGaussFilter = complexI.clone();

		Mat LowPassFilterMask = generateLowPassFilterMask(complexILowPass, 45);
		Mat highPassFilterMask = generatehighPassFilterMask(complexIHighPass, 10);
		Mat bandPassFilterMask = generateBandPassFilterMask(complexIBandPass, 35, 85);
		Mat gaussMask = gaussianMask(complexI, -1, 200);

		Mat lowPassKernel = getFilterKernel(LowPassFilterMask);
		Mat highPassKernel = getFilterKernel(highPassFilterMask);
		Mat bandPassKernel = getFilterKernel(bandPassFilterMask);
		Mat gaussFilterKernel = getFilterKernel(gaussMask);

		Mat lowPassDFTproduct = multiplyDFT(complexILowPass, lowPassKernel);
		Mat highPassDFTproduct = multiplyDFT(complexIHighPass, highPassKernel);
		Mat bandPassDFTproduct = multiplyDFT(complexIBandPass, bandPassKernel);
		Mat gaussDFTproduct = multiplyDFT(complexGaussFilter, gaussFilterKernel);

		Mat LowPassIDFT = calculateIDFT(lowPassDFTproduct);
		Mat highPassIDFT = calculateIDFT(highPassDFTproduct);
		Mat bandPassIDFT = calculateIDFT(bandPassDFTproduct);
		Mat gaussFilterIDFT = calculateIDFT(gaussDFTproduct);


		Mat1b save_4b;
		normalize(bandPassIDFT, save_4b, 255, 0, NORM_MINMAX);
		imwrite("low_pass_filter.png", save_4b);
		Bitmap^ bmpSrc3 = gcnew Bitmap("low_pass_filter.png");
		pictureBox4->Image = bmpSrc3;
		pictureBox4->Refresh();




		Mat1b save_3b;
		normalize(bandPassIDFT, save_3b, 255, 0, NORM_MINMAX);
		imwrite("high_pass_filtered.png", save_3b);
		Bitmap^ bmpSrc4 = gcnew Bitmap("high_pass_filtered.png");
		pictureBox5->Image = bmpSrc4;
		pictureBox5->Refresh();




		Mat1b save_2b;
		normalize(bandPassIDFT, save_2b, 255, 0, NORM_MINMAX);
		imwrite("band_pass_filtered.png", save_2b);
		Bitmap^ bmpSrc5 = gcnew Bitmap("band_pass_filtered.png");
		pictureBox6->Image = bmpSrc5;
		pictureBox6->Refresh();


		Mat1b save_1b;
		normalize(gaussFilterIDFT, save_1b, 255, 0, NORM_MINMAX);
		imwrite("gaussian_filtered.png", save_1b);
		Bitmap^ bmpSrc6 = gcnew Bitmap("gaussian_filtered.png");
		pictureBox7->Image = bmpSrc6;
		pictureBox7->Refresh();

	}


	void shift(Mat magI) {
		// crop if it has an odd number of rows or columns
		magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));

		int cx = magI.cols / 2;
		int cy = magI.rows / 2;

		Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
		Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
		Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
		Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right

		Mat tmp;                            // swap quadrants (Top-Left with Bottom-Right)
		q0.copyTo(tmp);
		q3.copyTo(q0);
		tmp.copyTo(q3);
		q1.copyTo(tmp);                     // swap quadrant (Top-Right with Bottom-Left)
		q2.copyTo(q1);
		tmp.copyTo(q2);
	}

	Mat multiplyDFT(Mat complexI, Mat kernel_spec)
	{
		shift(complexI);
		//Multiplying the DFT of image with DFT of the filter 
		mulSpectrums(complexI, kernel_spec, complexI, DFT_ROWS);

		return complexI;
	}
	Mat calculateIDFT(Mat complexI)
	{
		shift(complexI);
		Mat work;

		idft(complexI, work);
		//  dft(complex, work, DFT_INVERSE + DFT_SCALE);
		Mat planes1[] = { Mat::zeros(complexI.size(), CV_32F), Mat::zeros(complexI.size(), CV_32F) };
		split(work, planes1);                // planes[0] = Re(DFT(I)), planes[1] = Im(DFT(I))

		magnitude(planes1[0], planes1[1], work);    // === sqrt(Re(DFT(I))^2 + Im(DFT(I))^2)
		normalize(work, work, 0, 1, NORM_MINMAX);
		//cvtColor(work, work, CV_GRAY2BGR);
		// imshow("result", work);

		return work;
	}

	Mat getFilterKernel(Mat FilterMask)
	{

		Mat planes2[] = { Mat_<float>(FilterMask), Mat::zeros(FilterMask.size(), CV_32F) };
		Mat kernel_spec;
		merge(planes2, 2, kernel_spec);

		return kernel_spec;
	}


	Mat generateLowPassFilterMask(Mat complexI, int radius)
	{
		//Create a circular mask -- Low Pass
		//Mat img = Mat::zeros(complexI.rows, complexI.cols, CV_32F);
		Mat lowPassFilterMask = Mat::zeros(complexI.rows, complexI.cols, CV_32F);
		circle(lowPassFilterMask, cv::Point(lowPassFilterMask.cols / 2, lowPassFilterMask.rows / 2), radius, Scalar(1), -1, 8);

		//imshow("Low Pass Filter Mask", lowPassFilterMask);
		Mat1b save_1b;
		normalize(lowPassFilterMask, save_1b, 255, 0, NORM_MINMAX);
		imwrite("Low Pass Filter Mask.png", save_1b);
		Bitmap^ bmpSrc6 = gcnew Bitmap("Low Pass Filter Mask.png");
		pictureBox8->Image = bmpSrc6;
		pictureBox8->Refresh();

		return lowPassFilterMask;
	}


	Mat generatehighPassFilterMask(Mat complexI, int radius)
	{
		//Create a circular mask -- High Pass
		Mat highPassFilterMask = Mat::ones(complexI.rows, complexI.cols, CV_32F);
		circle(highPassFilterMask, cv::Point(highPassFilterMask.cols / 2, highPassFilterMask.rows / 2), radius, Scalar(0), -1, 8);

		//imshow("High Pass Filter Mask", highPassFilterMask);
		Mat1b save_1b;
		normalize(highPassFilterMask, save_1b, 255, 0, NORM_MINMAX);
		imwrite("High Pass Filter Mask.png", save_1b);
		Bitmap^ bmpSrc6 = gcnew Bitmap("High Pass Filter Mask.png");
		pictureBox9->Image = bmpSrc6;
		pictureBox9->Refresh();
		return highPassFilterMask;
	}


	Mat generateBandPassFilterMask(Mat complexI, int radius, int radius2)
	{
		//Create a circular mask -- Band Pass
		Mat bandPassFilterMask = generateLowPassFilterMask(complexI, radius2) - generateLowPassFilterMask(complexI, radius);

		//imshow("Band Pass Filter Mask", bandPassFilterMask);
		Mat1b save_1b;
		normalize(bandPassFilterMask, save_1b, 255, 0, NORM_MINMAX);
		imwrite("Band Pass Filter Mask.png", save_1b);
		Bitmap^ bmpSrc6 = gcnew Bitmap("Band Pass Filter Mask.png");
		pictureBox10->Image = bmpSrc6;
		pictureBox10->Refresh();
		return bandPassFilterMask;

	}

	Mat gaussianMask(Mat complexI, double sigma, int ksize)
	{

		int x = complexI.cols / 2;
		int y = complexI.rows / 2;
		// call openCV gaussian kernel generator
		//double sigma = -1;
		cv::Size mask_size = complexI.size();

		Mat kernelX = getGaussianKernel(ksize, sigma, CV_32F);
		Mat kernelY = getGaussianKernel(ksize, sigma, CV_32F);
		// create 2d gaus
		Mat kernel = kernelX * kernelY.t();
		// create empty mask
		Mat mask = Mat::zeros(mask_size, CV_32F);
		Mat maski = Mat::zeros(mask_size, CV_32F);

		// copy kernel to mask on x,y
		Mat pos(mask, Rect(x - ksize / 2, y - ksize / 2, ksize, ksize));
		kernel.copyTo(pos);

		// create mirrored mask
		Mat posi(maski, Rect((mask_size.width - x) - ksize / 2, (mask_size.height - y) - ksize / 2, ksize, ksize));
		kernel.copyTo(posi);
		// add mirrored to mask
		add(mask, maski, mask);

		// transform mask to range 0..1

		normalize(mask, mask, 0, 1, NORM_MINMAX);

		// imshow("Gaussian Filter Mask", mask);
		Mat1b save_1b;
		normalize(mask, save_1b, 255, 0, NORM_MINMAX);
		imwrite("Gaussian Filter Mask.png", save_1b);
		Bitmap^ bmpSrc6 = gcnew Bitmap("Gaussian Filter Mask.png");
		pictureBox11->Image = bmpSrc6;
		pictureBox11->Refresh();

		return mask;

	}

	private: char* ConvertString2Char(System::String^ str) {
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}


};
}
