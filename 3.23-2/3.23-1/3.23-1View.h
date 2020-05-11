
// 3.23-1View.h : CMy3231View 类的接口
//

#pragma once


class CMy3231View : public CView
{
protected: // 仅从序列化创建
	CMy3231View();
	DECLARE_DYNCREATE(CMy3231View)

// 特性
public:
	CMy3231Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&>ca;
	int n,m;
	bool set;
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
	virtual ~CMy3231View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32771();
};

#ifndef _DEBUG  // 3.23-1View.cpp 中的调试版本
inline CMy3231Doc* CMy3231View::GetDocument() const
   { return reinterpret_cast<CMy3231Doc*>(m_pDocument); }
#endif

