
// 414-2-3View.h : CMy41423View ��Ľӿ�
//

#pragma once


class CMy41423View : public CView
{
protected: // �������л�����
	CMy41423View();
	DECLARE_DYNCREATE(CMy41423View)

// ����
public:
	CMy41423Doc* GetDocument() const;

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
	virtual ~CMy41423View();
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

#ifndef _DEBUG  // 414-2-3View.cpp �еĵ��԰汾
inline CMy41423Doc* CMy41423View::GetDocument() const
   { return reinterpret_cast<CMy41423Doc*>(m_pDocument); }
#endif

