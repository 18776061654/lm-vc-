
// 5.4View.h : CMy54View ��Ľӿ�
//

#pragma once

class CMy54Set;

class CMy54View : public CRecordView
{
protected: // �������л�����
	CMy54View();
	DECLARE_DYNCREATE(CMy54View)

public:
	enum{ IDD = IDD_MY54_FORM };
	CMy54Set* m_pSet;

// ����
public:
	CMy54Doc* GetDocument() const;

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
	virtual void draw_pic(CString s);
// ʵ��
public:
	virtual ~CMy54View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString NAME;
	CString XUEHAO;
	CString PHONE;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // 5.4View.cpp �еĵ��԰汾
inline CMy54Doc* CMy54View::GetDocument() const
   { return reinterpret_cast<CMy54Doc*>(m_pDocument); }
#endif

