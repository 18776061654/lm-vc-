
// 4.7-1View.h : CMy471View ��Ľӿ�
//

#pragma once


class CMy471View : public CView
{
protected: // �������л�����
	CMy471View();
	DECLARE_DYNCREATE(CMy471View)

// ����
public:
	CMy471Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int top, right, left, bottom,M;
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
	virtual ~CMy471View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.7-1View.cpp �еĵ��԰汾
inline CMy471Doc* CMy471View::GetDocument() const
   { return reinterpret_cast<CMy471Doc*>(m_pDocument); }
#endif

