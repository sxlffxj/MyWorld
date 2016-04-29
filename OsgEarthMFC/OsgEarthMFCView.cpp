
// OsgEarthMFCView.cpp : COsgEarthMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "OsgEarthMFC.h"
#endif

#include "OsgEarthMFCDoc.h"
#include "OsgEarthMFCView.h"
#include "OsgFrame.h"
#include "ShpFeatureLoad.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

OsgFrame* mOSG;
HANDLE mThreadHandle;
// COsgEarthMFCView

IMPLEMENT_DYNCREATE(COsgEarthMFCView, CView)

BEGIN_MESSAGE_MAP(COsgEarthMFCView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32774, &COsgEarthMFCView::On_Shp_LayerLoad)
END_MESSAGE_MAP()

// COsgEarthMFCView 构造/析构

COsgEarthMFCView::COsgEarthMFCView()
{
	// TODO:  在此处添加构造代码

}

COsgEarthMFCView::~COsgEarthMFCView()
{
}

BOOL COsgEarthMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// COsgEarthMFCView 绘制

void COsgEarthMFCView::OnDraw(CDC* /*pDC*/)
{
	COsgEarthMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// COsgEarthMFCView 诊断

#ifdef _DEBUG
void COsgEarthMFCView::AssertValid() const
{
	CView::AssertValid();
}

void COsgEarthMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COsgEarthMFCDoc* COsgEarthMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COsgEarthMFCDoc)));
	return (COsgEarthMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// COsgEarthMFCView 消息处理程序


void COsgEarthMFCView::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  在此处添加消息处理程序代码
}


int COsgEarthMFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}
	else{

		mOSG = new OsgFrame(m_hWnd);

	}

	

	return CView::OnCreate(lpCreateStruct);
}


void COsgEarthMFCView::OnDestroy()
{
	CView::OnDestroy();

	if (mOSG != 0){
		delete mOSG;
	}


	WaitForSingleObject(mThreadHandle, 1000);
}


BOOL COsgEarthMFCView::OnEraseBkgnd(CDC* pDC)
{
	if (0 == mOSG) {

		return CView::OnEraseBkgnd(pDC);
	}
	else {

		return FALSE;
	}
	return CView::OnEraseBkgnd(pDC);
}


void COsgEarthMFCView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonUp(nFlags, point);
}



void COsgEarthMFCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	mOSG->InitOSG();

	mThreadHandle = (HANDLE)_beginthread(&OsgFrame::Render, 0, mOSG);
}

ref_ptr<Map> COsgEarthMFCView::getMap(){

	return mOSG->getMap();
}

void COsgEarthMFCView::On_Shp_LayerLoad()
{
	CFileDialog cfd(true, _T(".jpg"), NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, _T("ShapFiles   (*.shp)|*.shp|"), this);
	if (cfd.DoModal() != IDOK)     // Tell if get the image  
	{
		return;
	}
	//std::string m_path = LPCSTR(cfd.GetPathName().GetBuffer(cfd.GetPathName().GetLength()));
	std::string m_path = "E:\\WorkSpace\\3DWorks\\OsgEarthMFC\\x64\\Release\\imageSource\\world.shp";
	//cfd.GetPathName().ReleaseBuffer();

	//if (m_path == "")        //判断图片路径是否存在  
	//{
	//	return;
	//}
	//else{
		//ShpFeatureLoad shpLoad;
		//ModelLayerOptions newLayer = shpLoad.shpLoad(m_path, "world");
		//mOSG->getMap()->addModelLayer(new ModelLayer(newLayer));
	mOSG->getMap().get()->getImageLayerByName("basemap")->setVisible(false);


		mOSG->getViewer()->frame();
	//}
}
