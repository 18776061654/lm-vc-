
// 3.9-2View.h : CMy392View ��Ľӿ�
//

#pragma once


class CMy392View : public CView
{
protected: // �������л�����
	CMy392View();
	DECLARE_DYNCREATE(CMy392View)

// ����
public:
	CMy392Doc* GetDocument() const;

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
	virtual ~CMy392View();
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

#ifndef _DEBUG  // 3.9-2View.cpp �еĵ��԰汾
inline CMy392Doc* CMy392View::GetDocument() const
   { return reinterpret_cast<CMy392Doc*>(m_pDocument); }
#endif

