
// 413-1View.h : CMy4131View ��Ľӿ�
//

#pragma once


class CMy4131View : public CView
{
protected: // �������л�����
	CMy4131View();
	DECLARE_DYNCREATE(CMy4131View)

// ����
public:
	CMy4131Doc* GetDocument() const;

// ����
public:
	CString s1;
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
	virtual ~CMy4131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void On32771();
};

#ifndef _DEBUG  // 413-1View.cpp �еĵ��԰汾
inline CMy4131Doc* CMy4131View::GetDocument() const
   { return reinterpret_cast<CMy4131Doc*>(m_pDocument); }
#endif
