
// 3.24-2View.h : CMy3242View ��Ľӿ�
//

#pragma once


class CMy3242View : public CView
{
protected: // �������л�����
	CMy3242View();
	DECLARE_DYNCREATE(CMy3242View)

// ����
public:
	CMy3242Doc* GetDocument() const;

// ����
public:
	CBitmap m_bitmap;
	int width;
	int height;
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
	virtual ~CMy3242View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3.24-2View.cpp �еĵ��԰汾
inline CMy3242Doc* CMy3242View::GetDocument() const
   { return reinterpret_cast<CMy3242Doc*>(m_pDocument); }
#endif

