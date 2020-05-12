// mydialog.cpp : implementation file
//

#include "stdafx.h"
#include "4.7-4.h"
#include "mydialog.h"
#include "afxdialogex.h"


// mydialog dialog

IMPLEMENT_DYNAMIC(mydialog, CDialogEx)

mydialog::mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydialog::IDD, pParent)
	, x(_T(""))
	, z(_T(""))
	, y(0)
{

}

mydialog::~mydialog()
{
}

void mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT3, z);
	DDX_Text(pDX, IDC_EDIT2, y);
}


BEGIN_MESSAGE_MAP(mydialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &mydialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// mydialog message handlers


void mydialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	this->UpdateData(true);
	z.Format(_T("%s%d"),x, y);
	UpdateData(false);

}
