//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"



TForm1 *Form1;
int maxlkey,cl=0,co=0;
bool vo=true;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
struct Tree{
 AnsiString info ;
 Tree *left ,*right ;


}*root,*rot;

void Add_List(Tree*, int);
void View_Tree (Tree*, int);
void NextEdit(void);
Tree* Del_Info(Tree*, AnsiString);
void Del_Tree(Tree*);
Tree* List(AnsiString);
void Count(Tree*, int,AnsiString);

Tree* List(AnsiString inf) {
	Tree *t = new Tree;
t -> info = inf;
	t -> left = t -> right = NULL;
return t;
}


 void Del_Tree(Tree *t) {
  	if ( t != NULL)  {
    		Del_Tree ( t -> left);
    		Del_Tree ( t -> right);
      	delete t;
   	}
}

Tree* Del_Info(Tree *root, AnsiString key)  {
	Tree *Del, *Prev_Del, *R, *Prev_R;

	Del = root;
	Prev_Del = NULL;

while (Del != NULL && Del -> info != key) {
		Prev_Del = Del;
		if (Del->info > key)  Del = Del->left;
			else Del = Del->right;
		}
	if (Del == NULL)	{
   	ShowMessage ( "NOT Key!");
			return root;
	}

	if (Del -> right == NULL) R = Del->left;
	else
		if (Del -> left == NULL) R = Del->right;
		else {

			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
//----------------  -------------------
			if( Prev_R == Del)  R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
	 }
	if (Del== root) root = R;
	else
//---------------  ----------------
	if (Del->info < Prev_Del->info)
			Prev_Del->left = R;
		else	Prev_Del->right = R;
	delete Del;
	return root;

 }

void Add_List(Tree *root, AnsiString key)	  {
if (cl==1){
rot=root;
}
      	Tree *prev, *t;
 bool find = true;
	    	t = root;
		while ( t && find) {
		  	prev = t;
		  	if( key == t->info) {
                                find = false;
                                ShowMessage("Ключ уже есть!");
			}
		   	else
				if ( rand()%2==0 ) t = t -> left;
				else   t = t -> right;
		}
		if (find) {
			t = List(key);
			if ( key < prev -> info ) prev -> left = t;
			else    prev -> right = t;
		}
      }


void View_Tree(Tree *p, int level )	{
       String str;
	if ( p )	  {
	   	View_Tree (p -> right , level+1);
	   	for ( int i=0; i<level; i++) str = str + "    ";
				Form1->Memo1->Lines->Add(str + p->info);
	   	View_Tree(p -> left , level+1);
	   }
	}




void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if(root != NULL) Del_Tree(root);

      root = List (Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
 if(root == NULL) root = List (Edit1->Text);
      else Add_List (root, Edit1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
 if( rot == NULL ) ShowMessage(" Создайте дерево!!");
     else {
          Memo1->Lines->Add("---------- View -----------");
          View_Tree(rot, 0);
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
      AnsiString b = Form1->Edit1->Text;
		    root = Del_Info(root, b);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Form1->Memo1->Clear();
   Del_Tree(root);
	      	ShowMessage(" дерево удалено!");
        root = NULL;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{

if(Key==13){
      if(vo==true){
  if(cl==0){
    cl++;
    TForm1::Button1Click(Button1);
    NextEdit();
     }
   else{
     TForm1::Button2Click(Button2) ;
     NextEdit();
       }
     }
     else{TForm1::Button6Click(Button6) ;NextEdit();}
 }

 if(Key==46){
  TForm1::Button4Click(Button4) ;
   NextEdit();
 }
}

void NextEdit(){
Form1->Edit1->Text="";
}
//---------------------------------------------------------------------------

void Count(Tree *p, int level,AnsiString t )	{
       String str;
	if ( p ){
        AnsiString r=p->info;
                if(r[1]==t[1])co++;
	   	Count(p -> right , level+1 ,t);
	   	for ( int i=0; i<level; i++) str = str + "    ";
				Form1->Memo1->Lines->Add(str + p->info);
	   	Count(p -> left , level+1,t);
	   }
	}







void __fastcall TForm1::Button6Click(TObject *Sender)
{
  if(vo){
   ShowMessage("Теперь в поле введите символ");
   Form1->Edit1->SetFocus();
   vo=false;
        }
        else{
         Count(rot , 0,Form1->Edit1->Text);
          vo=true;
          ShowMessage("Я выполнілся");
          Form1->Memo1->Lines->Add("Кол-во слов с начинающимся символом="+IntToStr(co));
   }

}
//---------------------------------------------------------------------------


