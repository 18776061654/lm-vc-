
// 3.9-2View.h : CMy392View 类的接口
//

#pragma once


class CMy392View : public CView
{
protected: // 仅从序列化创建
	CMy392View();
	DECLARE_DYNCREATE(CMy392View)

// 特性
public:
	CMy392Doc* GetDocument() const;

// 操作
public:
	
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
	virtual ~CMy392View();
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
};

#ifndef _DEBUG  // 3.9-2View.cpp 中的调试版本
inline CMy392Doc* CMy392View::GetDocument() const
   { return reinterpret_cast<CMy392Doc*>(m_pDocument); }
#endif

