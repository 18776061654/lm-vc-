
// 3.10-2View.h : CMy3102View ��Ľӿ�
//

#pragma once


class CMy3102View : public CView
{
protected: // �������л�����
	CMy3102View();
	DECLARE_DYNCREATE(CMy3102View)

// ����
public:
	CMy3102Doc* GetDocument() const;

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
	virtual ~CMy3102View();
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

#ifndef _DEBUG  // 3.10-2View.cpp �еĵ��԰汾
inline CMy3102Doc* CMy3102View::GetDocument() const
   { return reinterpret_cast<CMy3102Doc*>(m_pDocument); }
#endif

