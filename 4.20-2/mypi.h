#pragma once


// mypi dialog

class mypi : public CDialogEx
{
	DECLARE_DYNAMIC(mypi)

public:
	mypi(CWnd* pParent = NULL);   // standard constructor
	virtual ~mypi();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
