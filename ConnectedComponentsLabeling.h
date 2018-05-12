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

	using namespace cv;

	/// <summary>
	/// Summary for ConnectedComponentsLabeling
	/// </summary>
	public ref class ConnectedComponentsLabeling : public System::Windows::Forms::Form
	{
	public:
		ConnectedComponentsLabeling(void)
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
		~ConnectedComponentsLabeling()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Crimson;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(7, 119);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(323, 48);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ConnectedComponentsLabeling::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(7, 191);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(323, 173);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(7, 372);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(323, 176);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Crimson;
			this->label1->Location = System::Drawing::Point(1, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 73);
			this->label1->TabIndex = 37;
			this->label1->Text = L"Connected Components                Labeling";
			// 
			// ConnectedComponentsLabeling
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->ClientSize = System::Drawing::Size(342, 578);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button2);
			this->Name = L"ConnectedComponentsLabeling";
			this->Text = L"   ConnectedComponents         Labeling";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat src;
		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "Image(*.bmp; *.jpg; *.png)|*.bmp;*.jpg|All files (*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		Bitmap^ bmpSrc = gcnew Bitmap(dgOpen->FileName);
		pictureBox1->Image = bmpSrc;
		pictureBox1->Refresh();

		Mat img;

		src = imread(ConvertString2Char(dgOpen->FileName));

		cvtColor(src, img, CV_BGR2GRAY);

		cv::Mat output = cv::Mat::zeros(img.size(), CV_8UC3);

		cv::Mat binary;
		std::vector < std::vector<cv::Point2i > > blobs;

		cv::threshold(img, binary, 0.0, 1.0, cv::THRESH_BINARY);

		FindBlobs(binary, blobs);

		// Randomy color the blobs
		for (size_t i = 0; i < blobs.size(); i++) {
			unsigned char r = 255 * (rand() / (1.0 + RAND_MAX));
			unsigned char g = 255 * (rand() / (1.0 + RAND_MAX));
			unsigned char b = 255 * (rand() / (1.0 + RAND_MAX));

			for (size_t j = 0; j < blobs[i].size(); j++) {
				int x = blobs[i][j].x;
				int y = blobs[i][j].y;

				output.at<cv::Vec3b>(y, x)[0] = b;
				output.at<cv::Vec3b>(y, x)[1] = g;
				output.at<cv::Vec3b>(y, x)[2] = r;
			}
		}

		imwrite("connected_component.png", output);

		Bitmap^ bmpSrc2 = gcnew Bitmap("connected_component.png");
		pictureBox2->Image = bmpSrc2;
		pictureBox2->Refresh();

	}

			 void FindBlobs(const cv::Mat &binary, std::vector < std::vector<cv::Point2i> > &blobs)
			 {
				 blobs.clear();

				 // Fill the label_image with the blobs
				 // 0  - background
				 // 1  - unlabelled foreground
				 // 2+ - labelled foreground

				 cv::Mat label_image;
				 binary.convertTo(label_image, CV_32SC1);

				 int label_count = 2; // starts at 2 because 0,1 are used already

				 for (int y = 0; y < label_image.rows; y++) {
					 int *row = (int*)label_image.ptr(y);
					 for (int x = 0; x < label_image.cols; x++) {
						 if (row[x] != 1) {
							 continue;
						 }

						 cv::Rect rect;
						 cv::floodFill(label_image, cv::Point(x, y), label_count, &rect, 0, 0, 4);

						 std::vector <cv::Point2i> blob;

						 for (int i = rect.y; i < (rect.y + rect.height); i++) {
							 int *row2 = (int*)label_image.ptr(i);
							 for (int j = rect.x; j < (rect.x + rect.width); j++) {
								 if (row2[j] != label_count) {
									 continue;
								 }

								 blob.push_back(cv::Point2i(j, i));
							 }
						 }

						 blobs.push_back(blob);

						 label_count++;
					 }
				 }
			 }

			 private: char* ConvertString2Char(System::String^ str) {
				 char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
				 return str2;
			 }
	};
}
