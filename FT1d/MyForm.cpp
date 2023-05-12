#include "MyForm.h"
#include "windows.h"
#include "fstream"
#using <system.drawing.dll>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
const double pi = 3.1415;


double FuncX(double argum)
{
    double y;
    y = Math::Sin(2 * pi * argum * 2) + 2 * Math::Sin(2 * pi * 4 * argum) ;
    return y;
}
double* CalculateCirclePoint(double arg, double freq)
{
    double* A = new double[2];
    A[0] = Math::Cos(2 * pi * arg * freq);
    A[1] = Math::Sin(2 * pi * arg * freq);
    return A;
}

double* CalculateCircleFunction(double arg, double* A)
{

    double* Z = new double[2];
    Z[0] = A[0] * FuncX(arg);
    Z[1] = A[1] * FuncX(arg);
    return Z;
}

double* CalculateCircleMatr(int arg, double* A)
{

    double* Z = new double[2];
    Z[0] = A[0] * arg;
    Z[1] = A[1] * arg;
    return Z;
}


[STAThreadAttribute]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    FT1d::MyForm form;
    Application::Run(% form);
}

System::Void FT1d::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
        double t1 = 0;
        double t2 = 5;
        

        double step = 0.001;

        this->chart1->Series[0]->Points->Clear();
        double* Point = new double[2];
        while (t1 <= t2) {
           
            Point = CalculateCirclePoint(t1, 1);
            this->chart1->Series[0]->Points->AddXY(Point[0], Point[1]);
            t1 += step;
        }
    return System::Void();

}

System::Void FT1d::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    double t1 = 0;
    double t2 = 10;

    double l1 = 0;
    double l2 = 10;
    double l;


  
    double IntegralX = 0;
    double IntegralY = 0;

    l = Convert::ToDouble(this->textBox1->Text);
    double lstep = 0.01;
    double step = 0.001;

    this->chart1->Series[0]->Points->Clear();
    this->chart1->Series[1]->Points->Clear();
    double* Point = new double[2];
    double* MassCentre = new double[2];
     
        while (t1 <= t2) {

            Point = CalculateCircleFunction(t1, CalculateCirclePoint(t1,l ));
            this->chart1->Series[0]->Points->AddXY(Point[0], Point[1]);
            IntegralX = IntegralX + Point[0] * step;
            IntegralY = IntegralY + Point[1] * step;

          
            t1 += step;
        }

        this->chart1->Series[1]->Points->AddXY(IntegralX / 5, IntegralY / 5);

   
    return System::Void();
}

System::Void FT1d::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    double t1 = 0;
    double t2 = 5;
    double step = 0.01;
    this->chart2->Series[0]->Points->Clear();
 
        while (t1 <= t2) {
            
            this->chart2->Series[0]->Points->AddXY(t1, FuncX(t1));
            t1 += step;
        }
   
    return System::Void();
}

System::Void FT1d::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    double t1 = 0;
    double t2 = 10;

    double l1 = 0;
    double l2 = 10;



    double IntegralX = 0;
    double IntegralY = 0;

   
    double lstep = 0.01;
    double step = 0.001;
    int FreqLong = l2 / lstep;
 
    double* Point = new double[2];
    double* MassCentre = new double[2];
    double* FourierFunc = new double[FreqLong];
    int i = 0;

       while (l1 <= l2)
{ 
           IntegralX = 0;
           IntegralY = 0;
    while (t1 <= t2) {
        Point = CalculateCircleFunction(t1, CalculateCirclePoint(t1, l1));
        IntegralX = IntegralX + Point[0] * step;
        IntegralY = IntegralY + Point[1] * step;
        t1 += step;
        }

  
    FourierFunc[i] = IntegralY / 5;
    i++;
    l1 = l1 + lstep;
    t1 = 0;
}
       i = 0;
       l1 = 0;
       while (l1 <= l2)
       {
           this->chart3->Series[0]->Points->AddXY(l1, FourierFunc[i]);
           l1 = l1 +  lstep;
           i++;
       }
    return System::Void();
}


int GetImageSize(String^ filename, int cond)
{
    Bitmap^ img = gcnew Bitmap(filename);
    if (cond == 0) {
        return img->Height;
    };
    if (cond == 1) {
        return img->Width;
    };
}
double** LoadImageToArray(String^ filename)
{

    Bitmap^ img = gcnew Bitmap(filename);
    double** arr = new double *[img->Height];
    for (int i = 0; i < img->Height; i++)
    {
        arr[i] = new double[img->Width];
    }
    for (int i = 0; i < img->Height; i++)
    {
        for (int j = 0; j < img->Width; j++)
        {
            Color c = img->GetPixel(j, i);
            int gray = (int)(0.299 * c.R + 0.587 * c.G + 0.114 * c.B); // Вычисление яркости пикселя
            arr[i][j] = gray;
        }
        
    }
    return arr;
}
void SaveAsBitmap(double** data, String^ filename, int m, int n)
{

    int width = m;
    int height = n;
    Bitmap^ bmp = gcnew Bitmap(width, height, Imaging::PixelFormat::Format24bppRgb);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int value = data[x][y];
            Color c = Color::FromArgb(  value,   value, value);
            bmp->SetPixel(x, y, c);
        }
    }
    bmp->RotateFlip(RotateFlipType::Rotate90FlipX);
    
    bmp->Save(filename, Imaging::ImageFormat::Jpeg);
    delete bmp;
}



//double* FuT1d(double* arr, int w)
//{
//    int t1 = 0;
//    int l1 = -w/2;
//    int l2 = w/2-1;
//    double IntegralY = 0;
//    double* Point = new double[2];
//    double* FourierFunc = new double[w];
//    int i = 0;
//
//    while (l1 <= l2)
//    {
//        IntegralY = 0;
//        while (t1 <= w) {
//            Point = CalculateCircleMatr(arr[t1], CalculateCirclePoint(t1, l1));
//            IntegralY = IntegralY + Point[1];
//            t1++;
//        }
//        FourierFunc[i] = Math::Round(IntegralY/ (w * 1.2));
//    
//        i++;
//        l1++;
//        t1 = 0;
//    }
// 
//    return FourierFunc;
//}

double* FuT1d(double* arr, int w)
{
    int t1 = 0;
    int l1 = -w / 2;
    int l2 = w / 2;
    double Integral = 0;
    double* FourierFunc = new double[w];
    int i = 0;

    for (l1 = -w / 2; l1 < l2; l1++)
    {
        
        Integral = 0;
        for (t1 = 0; t1 < w;t1++) {
            Integral = Integral + arr[t1] * Math::Sin(2 * pi * t1 * l1 / w);
        }
        FourierFunc[i] = Math::Abs(Math::Round( Integral/(43))); //Math::Round(Math::Log(Math::Abs(Integral)+1,2));

        i++;
    }

    return FourierFunc;
}
double** FT2d(String^ filename, int h, int w)
{
    double** matr;
    double* B = new double[w];
    
    matr = LoadImageToArray(filename);
    String^ a = nullptr;
   

    for (int i = 0; i < h; i++)
    {
        
        for (int j = 0; j < w; j++)
        {
            B[j] = matr[i][j];

        }
        B = FuT1d(B, w);
        for (int j = 0; j < w; j++)
        {
         //   a = a + " " + B[j];
            matr[i][j] = B[j] ;
          
        }

    }
  
    double* C = new double[h];
    for (int i = 0; i < w; i++)
    {
       
        for (int j = 0; j < h; j++)
        {
            C[j] = matr[j][i];
        }
        C = FuT1d(C, h);
        for (int j = 0; j < h; j++)
        {
            matr[j][i] = C[j] ;
            
        }
    }


    return matr;
}

System::Void FT1d::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    int height = GetImageSize("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg", 0);
    int width = GetImageSize("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg", 1);

    Bitmap^ bmp = gcnew Bitmap(height, width);
    Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
    pictureBox1->Image = bmp; // закрепление к pictureBox
    Bitmap^ image1; // фото загрузки в pictureBox
    image1 = gcnew Bitmap("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg"); // инициализация файл с фото
    pictureBox1->Image = image1;



    double** matr = LoadImageToArray("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg");
    String^ a = nullptr;
    SaveAsBitmap(matr, "E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited.jpg", height,width);

     return System::Void();
}

System::Void FT1d::MyForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    int height = GetImageSize("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg", 0);
    int width = GetImageSize("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg", 1);

    double** matr = FT2d("E:\\AiSHD\\FT1d\\imgs\\SampleImage.jpg", height, width);
    SaveAsBitmap(matr, "E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited.jpg", height, width);

   
 //   int** newmatr = FT2d("E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited.jpg", height, width);
 //   SaveAsBitmap(newmatr, "E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited2.jpg", height, width);
//    SaveAsBitmap(matr, "E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited.jpg", height, width);


    Bitmap^ bmp = gcnew Bitmap(height, width);
    Graphics^ g = Graphics::FromImage(bmp); // холст для рисования
    pictureBox1->Image = bmp; // закрепление к pictureBox
    Bitmap^ image1; // фото загрузки в pictureBox
    image1 = gcnew Bitmap("E:\\AiSHD\\FT1d\\imgs\\SampleImageEdited.jpg"); // инициализация файл с фото
    pictureBox1->Image = image1;
    return System::Void();
}
