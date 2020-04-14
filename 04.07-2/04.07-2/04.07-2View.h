
// 04.07-2View.h : CMy04072View 类的接口
//

#pragma once


class CMy04072View : public CView
{
protected: // 仅从序列化创建
	CMy04072View();
	DECLARE_DYNCREATE(CMy04072View)

// 特性
public:
	CMy04072Doc* GetDocument() const;

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
	virtual ~CMy04072View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onchange();
};

#ifndef _DEBUG  // 04.07-2View.cpp 中的调试版本
inline CMy04072Doc* CMy04072View::GetDocument() const
   { return reinterpret_cast<CMy04072Doc*>(m_pDocument); }
#endif

