// mydialog.cpp : implementation file
//

#include "stdafx.h"
#include "04.07.h"
#include "mydialog.h"
#include "afxdialogex.h"


// mydialog dialog

IMPLEMENT_DYNAMIC(mydialog, CDialogEx)

mydialog::mydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydialog::IDD, pParent)
{

}

mydialog::~mydialog()
{
}

void mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mydialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &mydialog::OnBnClickedOk)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// mydialog message handlers


void mydialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void mydialog::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	
}
