
// 3.24-1View.h : CMy3241View ��Ľӿ�
//

#pragma once


class CMy3241View : public CView
{
protected: // �������л�����
	CMy3241View();
	DECLARE_DYNCREATE(CMy3241View)

// ����
public:
	CMy3241Doc* GetDocument() const;

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
	virtual ~CMy3241View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNameLmname();
};

#ifndef _DEBUG  // 3.24-1View.cpp �еĵ��԰汾
inline CMy3241Doc* CMy3241View::GetDocument() const
   { return reinterpret_cast<CMy3241Doc*>(m_pDocument); }
#endif

