
// 3.27-3View.h : CMy3273View 类的接口
//

#pragma once


class CMy3273View : public CView
{
protected: // 仅从序列化创建
	CMy3273View();
	DECLARE_DYNCREATE(CMy3273View)

// 特性
public:
	CMy3273Doc* GetDocument() const;

// 操作
public:
	int N,m;
	CArray<CRect ,CRect> cr;
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
	virtual ~CMy3273View();
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
};

#ifndef _DEBUG  // 3.27-3View.cpp 中的调试版本
inline CMy3273Doc* CMy3273View::GetDocument() const
   { return reinterpret_cast<CMy3273Doc*>(m_pDocument); }
#endif

