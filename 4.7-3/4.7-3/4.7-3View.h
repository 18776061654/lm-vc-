
// 4.7-3View.h : CMy473View ��Ľӿ�
//

#pragma once


class CMy473View : public CView
{
protected: // �������л�����
	CMy473View();
	DECLARE_DYNCREATE(CMy473View)

// ����
public:
	CMy473Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set;
	int m;
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
	virtual ~CMy473View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.7-3View.cpp �еĵ��԰汾
inline CMy473Doc* CMy473View::GetDocument() const
   { return reinterpret_cast<CMy473Doc*>(m_pDocument); }
#endif

