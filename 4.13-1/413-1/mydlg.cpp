// mydlg.cpp : implementation file
//

#include "stdafx.h"
#include "413-1.h"
#include "mydlg.h"
#include "afxdialogex.h"


// mydlg dialog

IMPLEMENT_DYNAMIC(mydlg, CDialogEx)

mydlg::mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydlg::IDD, pParent)
{

}

mydlg::~mydlg()
{
}

void mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, lbox);
}


BEGIN_MESSAGE_MAP(mydlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &mydlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST2, &mydlg::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// mydlg message handlers


void mydlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int n = lbox.GetCurSel();
	lbox.GetText(n, s);
}


BOOL mydlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	s = "";
	lbox.AddString(_T("Ï´ÒÂ·þ 60Ôª"));
	lbox.AddString(_T("Ã«ÒÂ 1000Ôª"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void mydlg::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
}
