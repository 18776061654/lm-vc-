
// 3.10-3View.h : CMy3103View ��Ľӿ�
//

#pragma once


class CMy3103View : public CView
{
protected: // �������л�����
	CMy3103View();
	DECLARE_DYNCREATE(CMy3103View)

// ����
public:
	CMy3103Doc* GetDocument() const;

// ����
public:

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
	virtual ~CMy3103View();
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
};

#ifndef _DEBUG  // 3.10-3View.cpp �еĵ��԰汾
inline CMy3103Doc* CMy3103View::GetDocument() const
   { return reinterpret_cast<CMy3103Doc*>(m_pDocument); }
#endif

