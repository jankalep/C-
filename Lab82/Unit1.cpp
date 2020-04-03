//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "math.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
typedef double (*type_f)(double);
double fun(double);
double Gauss3(type_f, double, double, int);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Text = "3";
        Edit2->Text = "6";
        Edit3->Text = "0,001";
        Edit4->Text = "20";
        Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double a, b, x, eps, h, Int1, Int2, pogr;
        int n, n1;
        a = StrToFloat(Edit1->Text);
        b = StrToFloat(Edit2->Text);
        eps = StrToFloat(Edit3->Text);
        n = StrToInt(Edit4->Text);
        h = (b - a)/100;	    // Шаг вывода исходной функции
        Chart1->Series[0]->Clear();
        for(x = a-h; x< b+h; x+=h)
                Chart1->Series[0]->AddXY(x,fun(x));
        switch(RadioGroup1->ItemIndex){
        case 0:
                Memo1->Lines->Add("Расчет по разбиению на n = " + IntToStr(n));
                Int1 = Gauss3(fun,a,b,n);
        break;
        case 1:
                n1=2;
                Memo1->Lines->Add("Расчет по точности eps");
                Int1 = Gauss3(fun,a,b,n1);
                do {
                        n1*=2;
                        Int2 = Gauss3(fun,a,b,n1);
                        pogr = fabs(Int2-Int1);
                        Int1 = Int2;
                } while(pogr > eps);
                Memo1->Lines->Add("При n = " +IntToStr(n1));
        break;
        }
        Memo1->Lines->Add("Значение интеграла = " + FloatToStrF(Int1,ffFixed,8,6));
}

//------------------------- Метод Gaussa3 -----------------------------------
double Gauss3(type_f f, double a, double b, int n)
{
        double s = 0, h, x;
        h=(b-a)/n;
        x=a;
        for(int i=1; i<=n; i++){
    	s+=((5/9)*f(x-h/2*0.77)+(8/9)*f(x)+(5/9)*f(x+h/2*0.77))/2;                                                                                                                                                                           s+=(f(x)+f(x+h))/2;
    	        x+=h;
        }
        return h*s;
}

//----------------- Подынтегральная функция f(x) ----------------------------
double fun(double x)
{
        return log(x) - 5*sin(x)*sin(x);   // На интервале [3, 6] значение 0.100
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
        if((Key < '0' || Key >'9') && Key != VK_DELETE && Key != VK_BACK && Key != ',' && Key != '-' || Key == '.'){
                Key = NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
        if((Key < '0' || Key >'9') && Key != VK_DELETE && Key != VK_BACK && Key != ',' && Key != '-' || Key == '.'){
                Key = NULL;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
        if((Key < '0' || Key >'9') && Key != VK_DELETE && Key != VK_BACK && Key != ',' && Key != '-' || Key == '.'){
                Key = NULL;
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
        if((Key < '0' || Key >'9') && Key != VK_DELETE && Key != VK_BACK && Key != ',' && Key != '-' || Key == '.'){
                Key = NULL;
        }
}
//---------------------------------------------------------------------------

