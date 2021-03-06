//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCliente *Cliente;
//---------------------------------------------------------------------------
__fastcall TCliente::TCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCliente::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = TCloseAction::caFree;
}
//---------------------------------------------------------------------------
void __fastcall TCliente::btSairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TCliente::Hab_Botoes(TObject *Sender)
{
	btIncluir->Enabled=true;
	btAlterar->Enabled=true;
	btExcluir->Enabled=true;
	btCancelar->Enabled=false;
	btGravar->Enabled=false;
    btSair->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TCliente::Desab_Botoes(TObject *Sender)
{
	btIncluir->Enabled=false;
	btAlterar->Enabled=false;
	btExcluir->Enabled=false;
	btCancelar->Enabled=true;
	btGravar->Enabled=true;
	btSair->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TCliente::Habilitar_Campos(bool valor)
{
	EditNome->Enabled=valor;
	EditEndereco->Enabled=valor;
	EditCidade->Enabled=valor;
	CBEstado->Enabled=valor;

}
//---------------------------------------------------------------------------
void __fastcall TCliente::Limpar_Campos()
{
	EditNome->Text="";
	EditEndereco->Text="";
	EditCidade->Text="";
	CBEstado->ItemIndex=0;

}
//---------------------------------------------------------------------------

