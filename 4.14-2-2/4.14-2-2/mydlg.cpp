// mydlg.cpp : implementation file
//

#include "stdafx.h"
#include "4.14-2-2.h"
#include "mydlg.h"
#include "afxdialogex.h"


// mydlg dialog

IMPLEMENT_DYNAMIC(mydlg, CDialogEx)

mydlg::mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydlg::IDD, pParent)
	, left(0)
	, right(0)
	, top(0)
	, bottom(0)
{

}

mydlg::~mydlg()
{
}

void mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, left);
	DDX_Text(pDX, IDC_EDIT2, right);
	DDX_Text(pDX, IDC_EDIT3, top);
	DDX_Text(pDX, IDC_EDIT4, bottom);
}


BEGIN_MESSAGE_MAP(mydlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &mydlg::OnEnChangeEdit1)

END_MESSAGE_MAP()


// mydlg message handlers


void mydlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

}

