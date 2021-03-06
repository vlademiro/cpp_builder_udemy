#include <vcl.h>
#pragma hdrstop

#include "UnitCliente.h"
#include "UnitDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
int situacao=-1;
TFormCliente *FormCliente;
//---------------------------------------------------------------------------
__fastcall TFormCliente::TFormCliente(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormCliente::FormClose(TObject *Sender, TCloseAction &Action)
{
    Action = TCloseAction::caFree;
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btSairClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::Hab_Botoes()
{
	btIncluir->Enabled = true;
	btAlterar->Enabled = true;
	btExcluir->Enabled = true;
	btCancelar->Enabled = false;
	btGravar->Enabled = false;
	btSair->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormCliente::Desab_Botoes()
{
	btIncluir->Enabled = false;
	btAlterar->Enabled = false;
	btExcluir->Enabled = false;
	btCancelar->Enabled = true;
	btGravar->Enabled = true;
	btSair->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TFormCliente::Habilitar_Campos( bool valor )
{

	EdtID->Enabled = valor;
	EdtNome->Enabled = valor;
	EdtEndereco->Enabled = valor;
	EdtCidade->Enabled = valor;
	CBEstado->Enabled = valor;

}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::Limpar_Campos()
{

	EdtID->Text = "";
	EdtNome->Text = "";
	EdtEndereco->Text = "";
	EdtCidade->Text = "";
	CBEstado->Text = "";

}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::FormCreate(TObject *Sender)
{
    Pagina1->ActivePage = (TabArquivo);
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::FormActivate(TObject *Sender)
{
    Hab_Botoes();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btIncluirClick(TObject *Sender)
{
	TabArquivo->TabVisible = false;
	TabDados->TabVisible = true;
    Limpar_Campos();
	Pagina1->ActivePage = (TabDados);
	situacao=1;
	Habilitar_Campos(true);
	Desab_Botoes();
    EdtNome->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btGravarClick(TObject *Sender)
{
	if (Application->MessageBox(L"Confirma a opera??o ?",
		L"Grava??o de registro",
		MB_YESNO + MB_ICONINFORMATION )==IDYES)
	{
		switch ( situacao ) {
		case 1:
			DM->FDQueryIncluir->Close;
			/*
			DM->FDQueryIncluir->ParamByName("NOME")->AsString = EdtNome->Text;
			DM->FDQueryIncluir->ExecSQL();
            */
		default:
			;
		}
	}

	TabDados->TabVisible=true;
	TabArquivo->TabVisible=true;
	Pagina1->ActivePage=(TabArquivo);
	TabArquivo->SetFocus();
	Hab_Botoes();
	Habilitar_Campos(false);
    situacao=-1;
}
//---------------------------------------------------------------------------

