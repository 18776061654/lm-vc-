
// 4.7-2View.h : CMy472View ��Ľӿ�
//

#pragma once


class CMy472View : public CView
{
protected: // �������л�����
	CMy472View();
	DECLARE_DYNCREATE(CMy472View)

// ����
public:
	CMy472Doc* GetDocument() const;

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
	virtual ~CMy472View();
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

#ifndef _DEBUG  // 4.7-2View.cpp �еĵ��԰汾
inline CMy472Doc* CMy472View::GetDocument() const
   { return reinterpret_cast<CMy472Doc*>(m_pDocument); }
#endif

