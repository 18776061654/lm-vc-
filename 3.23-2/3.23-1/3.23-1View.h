
// 3.23-1View.h : CMy3231View ��Ľӿ�
//

#pragma once


class CMy3231View : public CView
{
protected: // �������л�����
	CMy3231View();
	DECLARE_DYNCREATE(CMy3231View)

// ����
public:
	CMy3231Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&>ca;
	int n,m;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy3231View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32771();
};

#ifndef _DEBUG  // 3.23-1View.cpp �еĵ��԰汾
inline CMy3231Doc* CMy3231View::GetDocument() const
   { return reinterpret_cast<CMy3231Doc*>(m_pDocument); }
#endif

