
// 3.17-2View.h : CMy3172View ��Ľӿ�
//

#pragma once


class CMy3172View : public CView
{
protected: // �������л�����
	CMy3172View();
	DECLARE_DYNCREATE(CMy3172View)

// ����
public:
	CMy3172Doc* GetDocument() const;

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
	virtual ~CMy3172View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.17-2View.cpp �еĵ��԰汾
inline CMy3172Doc* CMy3172View::GetDocument() const
   { return reinterpret_cast<CMy3172Doc*>(m_pDocument); }
#endif

