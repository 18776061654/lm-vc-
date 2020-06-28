#pragma once
#include "afxwin.h"


// mydlg dialog

class mydlg : public CDialogEx
{
	DECLARE_DYNAMIC(mydlg)

public:
	mydlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~mydlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListBox cbox;
	CString s;
	CString a[10];
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
	CEdit edit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
