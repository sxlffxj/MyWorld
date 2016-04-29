
// OsgEarthMFCView.h : COsgEarthMFCView 类的接口
//

#pragma once
#include "OsgEarthMFCDoc.h"
#include "OsgFrame.h"

class COsgEarthMFCView : public CView
{
protected: // 仅从序列化创建
	COsgEarthMFCView();
	DECLARE_DYNCREATE(COsgEarthMFCView)

// 特性
public:
	COsgEarthMFCDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~COsgEarthMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	ref_ptr<Map> getMap();
	afx_msg void On_Shp_LayerLoad();
};

#ifndef _DEBUG  // OsgEarthMFCView.cpp 中的调试版本
inline COsgEarthMFCDoc* COsgEarthMFCView::GetDocument() const
   { return reinterpret_cast<COsgEarthMFCDoc*>(m_pDocument); }
#endif

