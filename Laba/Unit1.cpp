//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int s1,s2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
s1=StrToInt(Edit1->Text);
s2=StrToInt(Edit2->Text);
StringGrid1->ColCount=s1;
StringGrid2->ColCount=s2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

if ( s1==NULL || s2==NULL)
 { ShowMessage ("¬ведите пожалуйста значени€ дл€ массивов");
  }
int *a1=new int[s1];




for ( int i=0; i<s1 ;i++)
{
   a1[i]=StrToInt(StringGrid1->Cells[i][0]);
}
for(int i = s1 - 1; i >= 1; i--)
   for(int j = 0; j < i; j++)
   {
        if(a1[j] > a1[j+1])
        {
             int foo = a1[j];
             a1[j] = a1[j+1];
             a1[j+1] = foo;
        }
   }

 for ( int i=0; i<s1 ;i++)
{
   StringGrid1->Cells[i][0]=IntToStr(a1[i]);
}


int *a2=new int[s2];




for ( int i=0; i<s2 ;i++)
{
   a2[i]=StrToInt(StringGrid2->Cells[i][0]);
}
for(int i = s2 - 1; i >= 1; i--)
   for(int j = 0; j < i; j++)
   {
        if(a2[j] > a2[j+1])
        {
             int foo = a2[j];
             a2[j] = a2[j+1];
             a2[j+1] = foo;
        }
   }

 for ( int i=0; i<s2 ;i++)
{
   StringGrid2->Cells[i][0]=IntToStr(a2[i]);
}

int s3=s1+s2 ;
StringGrid3->ColCount=s3;
int  i,j,k,*a3= new int [s3];
k=i=j=0;
while(i<s1 && j<s2)
{
 if (a1[i]<a2[j]){a3[k]=a1[i];i++;}
             else {a3[k]=a2[j];j++;}
             k++;
             }
while (i<s1)
{
a3[k]=a1[i]; i++;k++;
}
while (j<s2)
 {
  a3[k]=a2[j]; j++; k++;
 }

 for ( i=0 ;i<s3 ; i++){
   StringGrid3->Cells[i][0]=IntToStr(a3[i]);
  }

delete []a1 ;
delete []a2 ;
delete []a3 ;
}
//---------------------------------------------------------------------------

