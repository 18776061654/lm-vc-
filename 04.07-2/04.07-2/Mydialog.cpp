// Mydialog.cpp : implementation file
//

#include "stdafx.h"
#include "04.07-2.h"
#include "Mydialog.h"
#include "afxdialogex.h"


// Mydialog dialog

IMPLEMENT_DYNAMIC(Mydialog, CDialogEx)

Mydialog::Mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(Mydialog::IDD, pParent)
	, x(_T(""))
	, y(_T(""))
{

}

Mydialog::~Mydialog()
{
}

void Mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
}


BEGIN_MESSAGE_MAP(Mydialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydialog message handlers


void Mydialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(true);
	CString s;
	s = x;
	x = y;
	y = s;
	UpdateData(false);
}
