//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCliente.h"
#include "UnitDM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCliente *Cliente;
int situacao=-1;
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

void __fastcall TCliente::FormCreate(TObject *Sender)
{
    Pagina1->ActivePage=(TabArquivo);
}
//---------------------------------------------------------------------------

void __fastcall TCliente::FormActivate(TObject *Sender)
{
    Hab_Botoes(Cliente);
}
//---------------------------------------------------------------------------

void __fastcall TCliente::btIncluirClick(TObject *Sender)
{
	TabArquivo->TabVisible=false;
	TabDados->TabVisible=true;
	Pagina1->ActivePage=(TabDados);
	situacao=1;
	Limpar_Campos();
	Habilitar_Campos(true);
	Desab_Botoes( Cliente );
	EditNome->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TCliente::btGravarClick(TObject *Sender)
{
	if (Application->MessageBox(L"Confirma a opera??o ?",
		L"Grava??o de registro",
		MB_YESNO + MB_ICONINFORMATION )==IDYES)
	{
		switch (situacao) {
		case 1:
			DM->FDQueryIncluir->Close();
			DM->FDQueryIncluir->ParamByName("NOME")->AsString = EditNome->Text;
			DM->FDQueryIncluir->ParamByName("ENDERECO")->AsString = EditEndereco->Text;
			DM->FDQueryIncluir->ParamByName("CIDADE")->AsString = EditCidade->Text;
			DM->FDQueryIncluir->ParamByName("ESTADO")->AsString = CBEstado->Text;
			DM->FDQueryIncluir->ExecSQL();
			break;
		case 2:
			DM->FDQueryAlterar->Close();
			DM->FDQueryAlterar->ParamByName("NOME")->AsString = EditNome->Text;
			DM->FDQueryAlterar->ParamByName("ENDERECO")->AsString = EditEndereco->Text;
			DM->FDQueryAlterar->ParamByName("CIDADE")->AsString = EditCidade->Text;
			DM->FDQueryAlterar->ParamByName("ESTADO")->AsString = CBEstado->Text;
			DM->FDQueryAlterar->ParamByName("ID")->AsInteger = EditID->Text.ToInt();
			DM->FDQueryAlterar->ExecSQL();
			break;
		default:
			;
		}

		TabDados->TabVisible = true;
		TabArquivo->TabVisible = true;
		Pagina1->ActivePage=(TabArquivo);
		TabArquivo->SetFocus();
		Hab_Botoes(Cliente);
		Habilitar_Campos(false);
		situacao=-1;

	}
}
//---------------------------------------------------------------------------

void __fastcall TCliente::TabArquivoShow(TObject *Sender)
{
	DM->FDQueryExibir->Close();
	DM->FDQueryExibir->Open();
}
//---------------------------------------------------------------------------

void __fastcall TCliente::DSClienteDataChange(TObject *Sender, TField *Field)
{
	EditID->Text = DM->FDQueryExibir->FieldByName("ID")->AsString;
	EditNome->Text = DM->FDQueryExibir->FieldByName("NOME")->AsString;
	EditEndereco->Text = DM->FDQueryExibir->FieldByName("ENDERECO")->AsString;
	EditCidade->Text = DM->FDQueryExibir->FieldByName("CIDADE")->AsString;
	CBEstado->Text = DM->FDQueryExibir->FieldByName("ESTADO")->AsString;


}
//---------------------------------------------------------------------------

void __fastcall TCliente::btAlterarClick(TObject *Sender)
{
	TabArquivo->TabVisible=false;
	TabDados->TabVisible=true;
	Pagina1->ActivePage=(TabDados);
	situacao=2;
//	Limpar_Campos();
	Habilitar_Campos(true);
	Desab_Botoes( Cliente );
	EditNome->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TCliente::btCancelarClick(TObject *Sender)
{
	TabArquivo->TabVisible = true;
	Pagina1->ActivePage = (TabArquivo);
	TabArquivo->SetFocus();
	Hab_Botoes(Cliente);
	Habilitar_Campos(false);
}
//---------------------------------------------------------------------------

void __fastcall TCliente::btExcluirClick(TObject *Sender)
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

