
// starView.h : CstarView ��Ľӿ�
//

#pragma once


class CstarView : public CView
{
protected: // �������л�����
	CstarView();
	DECLARE_DYNCREATE(CstarView)

// ����
public:
	CstarDoc* GetDocument() const;

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
	virtual ~CstarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // starView.cpp �еĵ��԰汾
inline CstarDoc* CstarView::GetDocument() const
   { return reinterpret_cast<CstarDoc*>(m_pDocument); }
#endif

