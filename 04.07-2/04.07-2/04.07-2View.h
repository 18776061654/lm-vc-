
// 04.07-2View.h : CMy04072View ��Ľӿ�
//

#pragma once


class CMy04072View : public CView
{
protected: // �������л�����
	CMy04072View();
	DECLARE_DYNCREATE(CMy04072View)

// ����
public:
	CMy04072Doc* GetDocument() const;

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
	virtual ~CMy04072View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onchange();
};

#ifndef _DEBUG  // 04.07-2View.cpp �еĵ��԰汾
inline CMy04072Doc* CMy04072View::GetDocument() const
   { return reinterpret_cast<CMy04072Doc*>(m_pDocument); }
#endif

