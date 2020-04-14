#pragma once


// Mydialog dialog

class Mydialog : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog)

public:
	Mydialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~Mydialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString x;
	CString y;
	afx_msg void OnBnClickedButton1();
};
