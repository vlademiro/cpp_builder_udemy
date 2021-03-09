//---------------------------------------------------------------------------

#ifndef UnitClienteH
#define UnitClienteH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TFormCliente : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TBitBtn *btIncluir;
	TBitBtn *btAlterar;
	TBitBtn *btExcluir;
	TBitBtn *btCancelar;
	TBitBtn *btGravar;
	TBitBtn *btSair;
	TPageControl *Pagina1;
	TTabSheet *TabArquivo;
	TTabSheet *TabDados;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EdtID;
	TEdit *EdtNome;
	TEdit *EdtEndereco;
	TEdit *EdtCidade;
	TComboBox *CBEstado;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall btSairClick(TObject *Sender);
	void __fastcall Hab_Botoes();
	void __fastcall Desab_Botoes();
	void __fastcall Habilitar_Campos( bool valor );
    void __fastcall Limpar_Campos();
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall btIncluirClick(TObject *Sender);
	void __fastcall btGravarClick(TObject *Sender);
	void __fastcall TabArquivoShow(TObject *Sender);
	void __fastcall BancoParaInterface();
	void __fastcall btAlterarClick(TObject *Sender);
	void __fastcall btCancelarClick(TObject *Sender);
	void __fastcall btExcluirClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormCliente(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormCliente *FormCliente;
//---------------------------------------------------------------------------
#endif
