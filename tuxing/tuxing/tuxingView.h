
// tuxingView.h : CtuxingView ��Ľӿ�
//

#pragma once


class CtuxingView : public CView
{
protected: // �������л�����
	CtuxingView();
	DECLARE_DYNCREATE(CtuxingView)

// ����
public:
	CtuxingDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CtuxingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // tuxingView.cpp �еĵ��԰汾
inline CtuxingDoc* CtuxingView::GetDocument() const
   { return reinterpret_cast<CtuxingDoc*>(m_pDocument); }
#endif

