
// 04.07View.h : interface of the CMy0407View class
//

#pragma once


class CMy0407View : public CView
{
protected: // create from serialization only
	CMy0407View();
	DECLARE_DYNCREATE(CMy0407View)

// Attributes
public:
	CMy0407Doc* GetDocument() const;

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
	virtual ~CMy0407View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // debug version in 04.07View.cpp
inline CMy0407Doc* CMy0407View::GetDocument() const
   { return reinterpret_cast<CMy0407Doc*>(m_pDocument); }
#endif

