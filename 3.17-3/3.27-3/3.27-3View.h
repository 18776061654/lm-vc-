
// 3.27-3View.h : CMy3273View ��Ľӿ�
//

#pragma once


class CMy3273View : public CView
{
protected: // �������л�����
	CMy3273View();
	DECLARE_DYNCREATE(CMy3273View)

// ����
public:
	CMy3273Doc* GetDocument() const;

// ����
public:
	int N,m;
	CArray<CRect ,CRect> cr;
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
	virtual ~CMy3273View();
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
};

#ifndef _DEBUG  // 3.27-3View.cpp �еĵ��԰汾
inline CMy3273Doc* CMy3273View::GetDocument() const
   { return reinterpret_cast<CMy3273Doc*>(m_pDocument); }
#endif

