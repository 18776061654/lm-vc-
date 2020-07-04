#pragma once


// pic dialog

class pic : public CDialogEx
{
	DECLARE_DYNAMIC(pic)

public:
	pic(CWnd* pParent = NULL);   // standard constructor
	virtual ~pic();
	void draw_pic(CString s);
	CString s;
// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
