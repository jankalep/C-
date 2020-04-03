//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *StringGrid1;
        TEdit *Edit1;
        TLabel *Label1;
        TEdit *Edit2;
        TLabel *Label2;
        TEdit *Edit3;
        TLabel *Label3;
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit4;
        TLabel *Label4;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall StringGrid1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4Change(TObject *Sender);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
