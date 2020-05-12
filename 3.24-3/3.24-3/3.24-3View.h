
// 3.24-3View.h : CMy3243View 类的接口
//

#pragma once


class CMy3243View : public CView
{
protected: // 仅从序列化创建
	CMy3243View();
	DECLARE_DYNCREATE(CMy3243View)

// 特性
public:
	CMy3243Doc* GetDocument() const;

// 操作
public:
	CPoint n;
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
	virtual ~CMy3243View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.24-3View.cpp 中的调试版本
inline CMy3243Doc* CMy3243View::GetDocument() const
   { return reinterpret_cast<CMy3243Doc*>(m_pDocument); }
#endif

