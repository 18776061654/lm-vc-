// mydialog.cpp : implementation file
//

#include "stdafx.h"
#include "413-1.h"
#include "mydialog.h"
#include "afxdialogex.h"


// mydialog dialog

IMPLEMENT_DYNAMIC(mydialog, CDialogEx)

mydialog::mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydialog::IDD, pParent)
	, s2(_T(""))
{

}

mydialog::~mydialog()
{
}

void mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s2);
}


BEGIN_MESSAGE_MAP(mydialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &mydialog::OnEnChangeEdit1)
	ON_COMMAND(ID_32771, &mydialog::On32771)
END_MESSAGE_MAP()


// mydialog message handlers


void mydialog::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Add your control notification handler code here
	

}


void mydialog::On32771()
{

}
