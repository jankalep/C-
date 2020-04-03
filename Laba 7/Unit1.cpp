//---------------------------------------------------------------------------

#include <vcl.h>
 #include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------
void Metod ( float a ,float b ,float e   ) {
     float c=(a+b)/2 ;
   float d=b-a ;
 float    fa,fc, fac;
 while ( d>e) {
  fa=7*sin(a)*sin(b);
  fc=7*sin(c)*sin(c);
 fac=fa*fc;
 if (fac<0 )
 {
  b=c;
  }
  {
   a=c;
  }
  }
  ShowMessage("Мы закончіді");
 Form1->Memo1->Lines->Add("X="+FloatToStr(a)+" минимальное значение функции="+FloatToStr(fa));




















 // Form1->Memo1->Lines->Add(FloatToStr(a+b+e));


}


//---------------------------------------------------------------------------













void __fastcall TForm1::Button1Click(TObject *Sender)
{
float a,b,a1,b1,e ;
e=0.001;
if (CheckBox1->Checked==true)
 e=StrToFloat(Edit3->Text);


  a=StrToFloat(Edit1->Text);
  b=StrToFloat(Edit2->Text);
  if (a>b){
   a1=b;
   b1=a;

   Edit1->Text=FloatToStr(a1);
   Edit2->Text=FloatToStr(b1);
  }
  { a1=a;b1=b;

  }
  Metod ( a1 , b1 ,e )  ;
}

//---------------------------------------------------------------------------

