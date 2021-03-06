//---------------------------------------------------------------------------

#ifndef FormClienteH
#define FormClienteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TCliente : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TBitBtn *BitBtn6;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabDados;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TComboBox *ComboBox1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BitBtn6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCliente *Cliente;
//---------------------------------------------------------------------------
#endif
