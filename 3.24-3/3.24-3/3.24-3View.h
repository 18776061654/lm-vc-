
// 3.24-3View.h : CMy3243View ��Ľӿ�
//

#pragma once


class CMy3243View : public CView
{
protected: // �������л�����
	CMy3243View();
	DECLARE_DYNCREATE(CMy3243View)

// ����
public:
	CMy3243Doc* GetDocument() const;

// ����
public:
	CPoint n;
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
	virtual ~CMy3243View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.24-3View.cpp �еĵ��԰汾
inline CMy3243Doc* CMy3243View::GetDocument() const
   { return reinterpret_cast<CMy3243Doc*>(m_pDocument); }
#endif

