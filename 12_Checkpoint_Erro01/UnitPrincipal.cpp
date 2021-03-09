//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitPrincipal.h"
#include "UnitCliente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::btClienteClick(TObject *Sender)
{
	FormCliente->Show();
}
//---------------------------------------------------------------------------

