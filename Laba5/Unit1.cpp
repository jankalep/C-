//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <io.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString s2,FileName,sf,sr;
FILE *Fz;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{

AnsiString s1,si;
s1="";
s2="";
   if( Key==13){
   s1=Edit1->Text;
   int b=1;
       for ( int  i=1 ;i<s1.Length()+2 ;){
         si=s1.SubString(i ,2);
          if (si=="��" ) {

            s2.Insert("���",i+b);

               i+=2;
            si="";
            b++;
             }

             else{
              if (si=="��" ) {

              //i+=1;
            s2.Insert("���",i+b);

              i+=2;
            si="";
             b++;}
          else {    if (si=="��" ) {


            s2.Insert("���",i+b);

              i+=2;
            si="";
             b++;}

         { s2.Insert(s1.SubString(i ,1),i+b);
          i++;}
            }
           }

        }
        Label2->Caption=s2;
         sf=s2;
         s1="";
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{

if ( SaveDialog1->Execute()){
FileName+=SaveDialog1->FileName;
 if ((Fz=fopen(FileName.c_str(),"wb"))==NULL)
 {ShowMessage("������ �������� �����");
 fclose(Fz);
    return;
    }
  Fz=fopen(FileName.c_str(),"ab");

    fprintf(Fz,sf.c_str());

    }
 Label3->Caption="������� ����:"+FileName;
 fclose(Fz);
 FileName="";
 //FcloseAll();
 s2="";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  if (OpenDialog1->Execute()){
   FileName=OpenDialog1->FileName;
     if ((Fz=fopen(FileName.c_str(),"rb"))==NULL)
     { ShowMessage("������ �������� �����");
       return;
      }
      else{
       int n=filelength(fileno(Fz));
        char *so= new char[n];
        if(fgets( so,n+1 ,Fz)!=NULL){
         sr=AnsiString(so);
         Memo1->Lines->Add("---------------------------������ �� �����----------------------");
         Memo1->Lines->Add(sr);
         Label3->Caption="������ ����:"+FileName;

         }

          }
          fclose(Fz);

  }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
Edit1->Text="";
Label2->Caption="";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
  AnsiString FileRes;
  FILE *fo;

if ( SaveDialog1->Execute()){
FileRes=SaveDialog1->FileName;
Memo1->Lines->SaveToFile(FileRes);
 }
 else {
  ShowMessage("�� �� ��������� ����������");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
int b=1;
AnsiString s1=sr,si;
       for ( int  i=1 ;i<s1.Length()+1 ;){
         si=s1.SubString(i ,3);
          if (si=="���" ) {

            s2.Insert("��",i);

               i+=3;
            si="";
            b++;
             }

             else{
              if (si=="���" ) {

            s2.Insert("��",i);

              i+=3;
            si="";
             b++;}
          else {    if (si=="���" ) {


            s2.Insert("��",i);

              i+=3;
            si="";
             b++;}

         { s2.Insert(s1.SubString(i ,1),i);
          i++;}
            }
           }

        }
        Memo1->Lines->Add("-----------------------�������������� �����-------------");
        Memo1->Lines->Add(s2);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1Click(TObject *Sender)
{
 Edit1->Text="";
 Memo1->Clear();
 Label2->Caption="";
 Label3->Caption="";
}
//---------------------------------------------------------------------------

