
// �ۺ�ʵ��View.h : C�ۺ�ʵ��View ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ��Set;

class C�ۺ�ʵ��View : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ��View();
	DECLARE_DYNCREATE(C�ۺ�ʵ��View)

public:
	enum{ IDD = IDD_MY_FORM };
	C�ۺ�ʵ��Set* m_pSet;
	CString path;
// ����
public:
	C�ۺ�ʵ��Doc* GetDocument() const;
	void draw_pic(CString s);
// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�ۺ�ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString id;
	CString name;
	CString xuehao;
	CString xiangce;
	CString zye;
	CString sex;
	CString year;
	CString phone;
	CString home;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

#ifndef _DEBUG  // �ۺ�ʵ��View.cpp �еĵ��԰汾
inline C�ۺ�ʵ��Doc* C�ۺ�ʵ��View::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ��Doc*>(m_pDocument); }
#endif

