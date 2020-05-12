
// 4.7-3View.h : CMy473View 类的接口
//

#pragma once


class CMy473View : public CView
{
protected: // 仅从序列化创建
	CMy473View();
	DECLARE_DYNCREATE(CMy473View)

// 特性
public:
	CMy473Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	bool set;
	int m;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy473View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 4.7-3View.cpp 中的调试版本
inline CMy473Doc* CMy473View::GetDocument() const
   { return reinterpret_cast<CMy473Doc*>(m_pDocument); }
#endif

