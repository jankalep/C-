//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
struct Stack {
	char info;
        Stack *next;
} *begin;

int Prior (char);
Stack* InStack(Stack*, char);
Stack* OutStack(Stack*, char*);
double Rezult(String);
double mas[201];
Set  <char, 0, 255> znak;
int Kol = 6;
bool sg = true, ed1 = true, ed4 = true;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Text = "(a+b)*(c-d)/e";
        Edit2->Text = "";
        Edit3->Text = "";
        Edit4->Text = "5";
        char a = 'a';
        StringGrid1->Cells[0][0] ="���";
        StringGrid1->Cells[1][0] ="����.";
        for(int i=1; i<Kol; i++)   StringGrid1->Cells[0][i] = a++;
        StringGrid1->Cells[1][1] = 0.8;
        StringGrid1->Cells[1][2] = 4.1;
        StringGrid1->Cells[1][3] = 7.9;
        StringGrid1->Cells[1][4] = 6.2;
        StringGrid1->Cells[1][5] = 3.5;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(Edit1->Text == ""){
                ShowMessage("������� ���������!");
                return;
        }
        Stack *t;
	begin = NULL;
	char ss, a;
        String InStr, OutStr;
        OutStr = "";
        Edit2->Text = "";
        InStr = Edit1->Text;
        znak << '*' << '/' << '+' << '-' << '^';
        int skob = 0;
        for(int i=1; i<=InStr.Length(); i++){
                if(InStr[i] == '(') skob++;
                if(InStr[i] == ')') skob--;
                if(skob<0) break;
        }
        if(skob != 0){
                ShowMessage("�������� ����������� ������!");
                return;
        }
        for(int i=1; i<=InStr.Length(); i++){
                if(znak.Contains(InStr[i])){
                        if(i == 1){
                                ShowMessage("��������� �� ������ ���������� � ��������������� �����!");
                                return;
                        }
                        if(znak.Contains(InStr[i+1])){
                                ShowMessage("��� �������������� ����� �� ����� ������ ������!");
                                return;
                        }
                        if(i == InStr.Length()){
                                ShowMessage("��������� �� ������ ������������� �������������� ������!");
                                return;
                        }
                        if(InStr[i-1] == '(' || InStr[i+1] == ')'){
                                ShowMessage("�������������� ���� �� ����� ������ ����� ����������� � ����� ����������� �������!");
                                return;
                        }
                }
                if(i != InStr.Length()){
                        if((InStr[i] >= 'a' && InStr[i] <= 'z') && (InStr[i+1] >= 'a' && InStr[i+1] <= 'z')){
                                ShowMessage("������������ ���������. ��� ����� ����� �����������!");
                                return;
                        }
                        if(InStr[i] == ')' && InStr[i+1] == '('){
                                ShowMessage("������������ ������: ')('");
                                return;
                        }
                }
        }
        int len = InStr.Length(), k;
	for (k=1; k<=len; k++){
		ss = InStr[k];

		if (ss == '(') begin = InStack(begin, ss);
		if (ss == ')'){

                        while ((begin->info) != '('){
                                begin = OutStack(begin,&a);
                                OutStr += a;
                        }
                        begin = OutStack(begin,&a);
	        }

	        if (ss >= 'a'  &&  ss <= 'z') OutStr += ss;

                if (znak.Contains(ss)){
                        while (begin != NULL && Prior(begin->info) >= Prior(ss)){
                                begin = OutStack(begin, &a);
                                OutStr += a;
                        }
                        begin = InStack(begin, ss);
                }
        }

	while(begin != NULL){
                begin = OutStack(begin, &a);
                OutStr += a;
        }
        Edit2->Text = OutStr;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(Edit2->Text == ""){
                ShowMessage("���������� ��������� � ��� ���!");
                return;
        }
        char ch;
        String OutStr = Edit2->Text;
        for (int i=1; i<Kol; i++){
                if(StringGrid1->Cells[1][i] != ""){
                        ch = StringGrid1->Cells[0][i][1];
                        mas[int(ch)] = StrToFloat(StringGrid1->Cells[1][i]);
                }
        }

        char x;
        String IshodnayaStr, BezZnacheniyStr;
        BezZnacheniyStr = "";
        IshodnayaStr = Edit1->Text;
        int len = IshodnayaStr.Length(), k;
	for (k=1; k<=len; k++){
		x = IshodnayaStr[k];
                for(int j=1; j<Kol; j++)
	        if (StringGrid1->Cells[0][j] == x && StringGrid1->Cells [1][j] == "") BezZnacheniyStr = BezZnacheniyStr + " " + x;
        }
        if(BezZnacheniyStr != ""){
                ShowMessage("������������ ������! �������� �� ��������� ��������� ����������:"+BezZnacheniyStr);
                return;
        }
        double rez = Rezult(OutStr);
        if(Kol == 0){
                Kol = StringGrid1->RowCount;
                return;
        }
        Edit3->Text = FloatToStrF(rez,ffFixed,7,3);
}


int Prior(char a){
        switch(a){
                case '^':
                        return 4;
                case '*':
                case '/':
                        return 3;
                case '-':
                case '+':
                        return 2;
                case '(':
                        return 1;
}
	return 0;
}

double Rezult(String Str){
        char ch, ch1, ch2;
        double op1, op2, rez;
        znak << '*' << '/' << '+' << '-' << '^';
        char chr = 'z'+1;
        for (int i=1; i<=Str.Length(); i++){
     	        ch=Str[i];
     	        if(!znak.Contains(ch)) begin = InStack(begin, ch);
     	        else{
                        begin = OutStack(begin,&ch1);
        		begin = OutStack(begin,&ch2);
        		op1 = mas[int(ch1)];
        		op2 = mas[int(ch2)];
                        if(ch == '/' && op1 == 0){
                                ShowMessage("������� �� ����! ��������� ������������ ��������� ����������.");
                                Kol = 0;
                                return NULL;
                        }
        		switch(ch){
                		case '+' : 	rez=op2+op1;  		break;
                		case '-' : 	rez=op2-op1;  		break;
                		case '*' : 	rez=op2*op1;  		break;
                		case '/' : 	rez=op2/op1;   		break;
                		case '^' : 	rez=pow(op2,op1); 	break;
        		}
        	mas[int(chr)] = rez;
        	begin = InStack(begin,chr);
        	chr++;
     	        }
        }

        return rez;
}
//---------------------------------------------------------------------------
Stack* InStack(Stack *p, char in){
        Stack *t = new Stack;
        t -> info = in;
        t -> next = p;
        return t;
}
//---------------------------------------------------------------------------
Stack* OutStack(Stack* p, char *out){
        Stack *t = p;
        *out = p->info;
        p = p->next;
        delete t;
        return p;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
        if((Key < '0' || Key > '9') && Key != VK_BACK && Key != VK_DELETE && Key != 13 && Key != 44 && Key != 45 || Key == 46){
                if(sg) ShowMessage("������������ ������! �������� ���� ����� ��� ������� �����. � ���������� ��� ��������� ������������ �� �����.");
                sg = false;
                Key = NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{                                                     'Enter'        '-'           '/'          '^'          '.'
        if((Key < 97 || Key > 122) && (Key < 40 || Key > 43) && Key != VK_BACK && Key != VK_DELETE && Key != 13 && Key != 45 && Key != 47 && Key != 94 || Key == 46){
                if(ed1) ShowMessage("������������ ������! �������� ���� ��������� ��������� ����, �������������� ������ � ������.");
                ed1 = false;
                Key = NULL;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
        if(Edit4->Text == "") return;
        if(StrToInt(Edit4->Text) < 1){
                Edit4->Text = "1";
                return;
        }
        if(StrToInt(Edit4->Text) > 26){
                Edit4->Text = "26";
                return;
        }
        StringGrid1->RowCount = StrToInt(Edit4->Text) + 1;
        Kol = StringGrid1->RowCount;
        char a = 'a';
        for(int i=1; i<Kol; i++)   StringGrid1->Cells[0][i] = a++;  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{         //
        if((Key < '0' || Key > '9') && Key != VK_BACK && Key != VK_DELETE && Key != 13){
                if(ed4) ShowMessage("������������ ������! �������� ���� ����� ����� �� 1 �� 26. � ���������� ��� ��������� ������������ �� �����.");
                ed4 = false;
                Key = NULL;
        }
}
//---------------------------------------------------------------------------

