
// 4.14-2-2View.h : CMy41422View ��Ľӿ�
//

#pragma once


class CMy41422View : public CView
{
protected: // �������л�����
	CMy41422View();
	DECLARE_DYNCREATE(CMy41422View)

// ����
public:
	CMy41422Doc* GetDocument() const;

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
	virtual ~CMy41422View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void On32771();
};

#ifndef _DEBUG  // 4.14-2-2View.cpp �еĵ��԰汾
inline CMy41422Doc* CMy41422View::GetDocument() const
   { return reinterpret_cast<CMy41422Doc*>(m_pDocument); }
#endif

