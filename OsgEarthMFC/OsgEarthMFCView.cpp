
// OsgEarthMFCView.cpp : COsgEarthMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// COsgEarthMFCView ����/����

COsgEarthMFCView::COsgEarthMFCView()
{
	// TODO:  �ڴ˴���ӹ������

}

COsgEarthMFCView::~COsgEarthMFCView()
{
}

BOOL COsgEarthMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// COsgEarthMFCView ����

void COsgEarthMFCView::OnDraw(CDC* /*pDC*/)
{
	COsgEarthMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// COsgEarthMFCView ���

#ifdef _DEBUG
void COsgEarthMFCView::AssertValid() const
{
	CView::AssertValid();
}

void COsgEarthMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COsgEarthMFCDoc* COsgEarthMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COsgEarthMFCDoc)));
	return (COsgEarthMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// COsgEarthMFCView ��Ϣ�������


void COsgEarthMFCView::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  �ڴ˴������Ϣ����������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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

	//if (m_path == "")        //�ж�ͼƬ·���Ƿ����  
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
