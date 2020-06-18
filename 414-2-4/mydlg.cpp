// mydlg.cpp : implementation file
//

#include "stdafx.h"
#include "414-2-4.h"
#include "mydlg.h"
#include "afxdialogex.h"


// mydlg dialog

IMPLEMENT_DYNAMIC(mydlg, CDialogEx)

mydlg::mydlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(mydlg::IDD, pParent)
	, x(0)
	, y(0)
	, z(0)
{

}

mydlg::~mydlg()
{
}

void mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, z);
}


BEGIN_MESSAGE_MAP(mydlg, CDialogEx)
END_MESSAGE_MAP()


// mydlg message handlers
