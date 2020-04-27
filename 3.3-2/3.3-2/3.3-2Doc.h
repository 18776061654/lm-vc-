
// 3.3-2Doc.h : interface of the CMy332Doc class
//


#pragma once


class CMy332Doc : public CDocument
{
protected: // create from serialization only
	CMy332Doc();
	DECLARE_DYNCREATE(CMy332Doc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	CString s=_T("ÎÒÊÇ´óË§¸ç£¡£¡£¡");

	int a = 20;
// Implementation
public:
	virtual ~CMy332Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
