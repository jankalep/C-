//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int s ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Button2->Enabled=false ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Button2->Enabled=true ;
  s= StrToInt(Edit1->Text);
  StringGrid1->ColCount=s;
  StringGrid1->RowCount=s ;
  StringGrid2->ColCount=s;
  if (s<=1)
  {
  ShowMessage("Задайте размер матрицы>1");
  Edit1->Clear();
  Button2->Enabled=false ;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int maxs, mins=0, t=0 ;

int **a=new int* [s] ;
 for (int i=0 ; i<s ; i++)
     a[i]= new int [s] ;





   for ( int i=0 ; i<s; i++ ) {
        for ( int  j=0 ; j<s ; j++) {

          a[i][j]= StrToInt(StringGrid1->Cells[i][j]);}
           }

       int min=a[0][0] , max=a[0][0];

  for (int i=0 ; i<s ;i++)
    { for (int j=0; j<s ; j++)
    {
     if ( a[i][j]<min){
     min=a[i][j];

     mins=j;

     }
     if (a[i][j]>max)
     {
     max=a[i][j];
     maxs=j ;

       }
     if (mins==maxs)
         t++;
                   }
                     if (t>0)
      ShowMessage("Минимальный и максимальный элементы в одной строке");
   }
   Label2->Caption="Мін="+IntToStr(min)+"  "+"MAx="+IntToStr(max);
   int sum=0 ;
      for (int i=0; i<s ;i++)
      {
      int s1 ,s2 ;
      s1=a[i][maxs];
      s2=a[i][mins];
      StringGrid2->Cells[i][1]=IntToStr(s1);
     StringGrid2->Cells[i][0]=IntToStr(s2);
       sum+=s1*s2;
      }


 Label3->Caption="Скалярное произведение двух строк="+IntToStr(sum);
    for (int i=0;i<s; i++)
    {
   delete[]a[i]; }

   delete []a;
 t=0;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{

 Button2->Enabled=false ;
 for ( int i=0 ; i<s; i++ ) {
        for ( int  j=0 ; j<s ; j++) {
        StringGrid2->Cells[j][0]="";
        StringGrid2->Cells[j][1]="";
        StringGrid1->Cells[i][j]="";}
           }
     StringGrid1->ColCount=1;
     StringGrid1->RowCount=1;
     StringGrid2->ColCount=0;
    Label2->Caption="";
    Label3->Caption="Скалярное произведение двух строк";
     Edit1->Clear();
}
//---------------------------------------------------------------------------

