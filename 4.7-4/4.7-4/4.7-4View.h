
// 4.7-4View.h : CMy474View ��Ľӿ�
//

#pragma once


class CMy474View : public CView
{
protected: // �������л�����
	CMy474View();
	DECLARE_DYNCREATE(CMy474View)

// ����
public:
	CMy474Doc* GetDocument() const;

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
	virtual ~CMy474View();
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

#ifndef _DEBUG  // 4.7-4View.cpp �еĵ��԰汾
inline CMy474Doc* CMy474View::GetDocument() const
   { return reinterpret_cast<CMy474Doc*>(m_pDocument); }
#endif

