
// 414-2-4View.h : CMy41424View ��Ľӿ�
//

#pragma once


class CMy41424View : public CView
{
protected: // �������л�����
	CMy41424View();
	DECLARE_DYNCREATE(CMy41424View)

// ����
public:
	CMy41424Doc* GetDocument() const;

// ����
public:
	int x, y, z;
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
	virtual ~CMy41424View();
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

#ifndef _DEBUG  // 414-2-4View.cpp �еĵ��԰汾
inline CMy41424Doc* CMy41424View::GetDocument() const
   { return reinterpret_cast<CMy41424Doc*>(m_pDocument); }
#endif

