
// 4.21-1View.h : CMy4211View ��Ľӿ�
//

#pragma once


class CMy4211View : public CView
{
protected: // �������л�����
	CMy4211View();
	DECLARE_DYNCREATE(CMy4211View)

// ����
public:
	CMy4211Doc* GetDocument() const;

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
	virtual ~CMy4211View();
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
};

#ifndef _DEBUG  // 4.21-1View.cpp �еĵ��԰汾
inline CMy4211Doc* CMy4211View::GetDocument() const
   { return reinterpret_cast<CMy4211Doc*>(m_pDocument); }
#endif

