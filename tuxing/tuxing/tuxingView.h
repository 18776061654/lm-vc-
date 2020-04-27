
// tuxingView.h : CtuxingView 类的接口
//

#pragma once


class CtuxingView : public CView
{
protected: // 仅从序列化创建
	CtuxingView();
	DECLARE_DYNCREATE(CtuxingView)

// 特性
public:
	CtuxingDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CtuxingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // tuxingView.cpp 中的调试版本
inline CtuxingDoc* CtuxingView::GetDocument() const
   { return reinterpret_cast<CtuxingDoc*>(m_pDocument); }
#endif

