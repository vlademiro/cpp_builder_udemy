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
	CBEstado->ItemIndex = 0;

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
			DM->FDQueryIncluir->Close();
			DM->FDQueryIncluir->ParamByName("NOME")->AsString = EdtNome->Text;
			DM->FDQueryIncluir->ParamByName("ENDERECO")->AsString = EdtEndereco->Text;
			DM->FDQueryIncluir->ParamByName("CIDADE")->AsString = EdtCidade->Text;
			DM->FDQueryIncluir->ParamByName("ESTADO")->AsString = CBEstado->Text;
			DM->FDQueryIncluir->ExecSQL();
		case 2:
			DM->FDQueryAlterar->Close();
			DM->FDQueryAlterar->ParamByName("NOME")->AsString = EdtNome->Text;
			DM->FDQueryAlterar->ParamByName("ENDERECO")->AsString = EdtEndereco->Text;
			DM->FDQueryAlterar->ParamByName("CIDADE")->AsString = EdtCidade->Text;
			DM->FDQueryAlterar->ParamByName("ESTADO")->AsString = CBEstado->Text;
			DM->FDQueryAlterar->ParamByName("ID")->AsInteger = EdtID->Text.ToInt();
			DM->FDQueryAlterar->ExecSQL();
			break;
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

void __fastcall TFormCliente::TabArquivoShow(TObject *Sender)
{
	DM->FDQueryExibir->Close();
	DM->FDQueryExibir->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::BancoParaInterface()
{
	EdtID->Text = DM->FDQueryExibir->FieldByName("ID")->AsString;
	EdtNome->Text = DM->FDQueryExibir->FieldByName("NOME")->AsString;
	EdtEndereco->Text = DM->FDQueryExibir->FieldByName("ENDERECO")->AsString;
	EdtCidade->Text = DM->FDQueryExibir->FieldByName("CIDADE")->AsString;
	CBEstado->Text = DM->FDQueryExibir->FieldByName("ESTADO")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btAlterarClick(TObject *Sender)
{
	TabArquivo->TabVisible = false;
	TabDados->TabVisible = true;
	Pagina1->ActivePage = (TabDados);
	situacao=2;
	Habilitar_Campos(true);
	Desab_Botoes();
	EdtNome->SetFocus();
	BancoParaInterface();
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btCancelarClick(TObject *Sender)
{
	TabArquivo->TabVisible = true;
	Pagina1->ActivePage = (TabArquivo);
	TabArquivo->SetFocus();
	Hab_Botoes();
	Habilitar_Campos(false);
}
//---------------------------------------------------------------------------

void __fastcall TFormCliente::btExcluirClick(TObject *Sender)
{
    if (Application->MessageBox(L"Confirma a exclus?o ?",
	L"Exclus?o de registro",
	MB_YESNO + MB_ICONINFORMATION )==IDYES)
	{
		DM->FDQueryExcluir->Close();
		DM->FDQueryExcluir->ParamByName("ID")->AsInteger = DM->FDQueryExibir->FieldByName("ID")->AsInteger;
		DM->FDQueryExcluir->ExecSQL();

		DM->FDQueryExibir->Close();
		DM->FDQueryExibir->Open();

	}

	TabDados->TabVisible = true;
	TabArquivo->TabVisible = true;

    Pagina1->ActivePage = (TabArquivo);
}
//---------------------------------------------------------------------------

