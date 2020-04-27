
// 3.3-2View.h : interface of the CMy332View class
//

#pragma once


class CMy332View : public CView
{
protected: // create from serialization only
	CMy332View();
	DECLARE_DYNCREATE(CMy332View)

// Attributes
public:
	CMy332Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy332View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 3.3-2View.cpp
inline CMy332Doc* CMy332View::GetDocument() const
   { return reinterpret_cast<CMy332Doc*>(m_pDocument); }
#endif

