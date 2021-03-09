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
	TBitBtn *btIncluir;
	TBitBtn *btAlterar;
	TBitBtn *btExcluir;
	TBitBtn *btCancelar;
	TBitBtn *btGravar;
	TBitBtn *btSair;
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
	TEdit *EditNome;
	TEdit *EditEndereco;
	TEdit *EditCidade;
	TComboBox *CBEstado;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btSairClick(TObject *Sender);
	void __fastcall Hab_Botoes(TObject *Sender);
	void __fastcall Desab_Botoes(TObject *Sender);
	void __fastcall Habilitar_Campos(bool valor);
    void __fastcall Limpar_Campos();
private:	// User declarations
public:		// User declarations
	__fastcall TCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCliente *Cliente;
//---------------------------------------------------------------------------
#endif
