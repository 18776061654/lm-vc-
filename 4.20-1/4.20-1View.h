
// 4.20-1View.h : CMy4201View ��Ľӿ�
//

#pragma once


class CMy4201View : public CView
{
protected: // �������л�����
	CMy4201View();
	DECLARE_DYNCREATE(CMy4201View)

// ����
public:
	CMy4201Doc* GetDocument() const;

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
	virtual ~CMy4201View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 4.20-1View.cpp �еĵ��԰汾
inline CMy4201Doc* CMy4201View::GetDocument() const
   { return reinterpret_cast<CMy4201Doc*>(m_pDocument); }
#endif

