
// OsgEarthMFCView.h : COsgEarthMFCView ��Ľӿ�
//

#pragma once
#include "OsgEarthMFCDoc.h"
#include "OsgFrame.h"

class COsgEarthMFCView : public CView
{
protected: // �������л�����
	COsgEarthMFCView();
	DECLARE_DYNCREATE(COsgEarthMFCView)

// ����
public:
	COsgEarthMFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~COsgEarthMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // OsgEarthMFCView.cpp �еĵ��԰汾
inline COsgEarthMFCDoc* COsgEarthMFCView::GetDocument() const
   { return reinterpret_cast<COsgEarthMFCDoc*>(m_pDocument); }
#endif

