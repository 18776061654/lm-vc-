// mydlg.cpp : implementation file
//

#include "stdafx.h"
#include "4.21-1.h"
#include "mydlg.h"
#include "afxdialogex.h"


// mydlg dialog

IMPLEMENT_DYNAMIC(mydlg, CDialogEx)

mydlg::mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydlg::IDD, pParent)
	, s(_T(""))
{

}

mydlg::~mydlg()
{

}

void mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, cbox);
	DDX_Text(pDX, IDC_EDIT1, s);
	DDX_Control(pDX, IDC_EDIT1, edit);
}


BEGIN_MESSAGE_MAP(mydlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &mydlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &mydlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &mydlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// mydlg message handlers


BOOL mydlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	for (int i = 0; i < 10; i++)
	{
		cbox.AddString(a[i]);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void mydlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	int n = cbox.GetCurSel();
	cbox.GetText(n, s);
	edit.SetWindowTextW(s);
}


void mydlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	int n = cbox.GetCurSel();
	edit.GetWindowTextW(s);
	cbox.DeleteString(n);
	cbox.InsertString(n, s);
}


void mydlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	BOOL isOpen = FALSE;		//是否打开(否则为保存)
	CFileDialog openFileDlg(isOpen);
	int result = openFileDlg.DoModal();
}
