#pragma once


// zj dialog

class zj : public CDialogEx
{
	DECLARE_DYNAMIC(zj)

public:
	zj(CWnd* pParent = NULL);   // standard constructor
	virtual ~zj();

// Dialog Data
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString one;
};
