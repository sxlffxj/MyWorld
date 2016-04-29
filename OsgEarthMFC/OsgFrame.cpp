#include "stdafx.h"
#include "OsgFrame.h"
#include "ShpFeatureLoad.h"

OsgFrame::OsgFrame(HWND hWnd)
{
	m_hWnd = hWnd;
}


OsgFrame::~OsgFrame()
{

}

void OsgFrame::InitOSG(){
	InitSceneGraph();
	InitCameraConfig();
	InitBackGround();
}

void OsgFrame::InitSceneGraph(){
	mRoot = new Group();
	
	//ref_ptr<Node> node = readNodeFile("E:/lib/opengis/osgearth/final/OpenSceneGraph3.4/OpenSceneGraph-Data/cow.osg");

	mMap = new Map();
	MapNode* mapNode = new MapNode(mMap);






	//ShpFeatureLoad shpcreate;
	//ModelLayerOptions newLayer = shpcreate.shpLoad(".\\imageSource\\world.shp", "world");

	//mMap->addModelLayer(new ModelLayer(newLayer));

	TMSOptions imgOption;
	imgOption.url() = "http://readymap.org/readymap/tiles/1.0.0/7/";

	mMap->addImageLayer(new ImageLayer("image", imgOption));

	GDALOptions basemapOpt;
	basemapOpt.url() = ".\\imageSource\\world.tif";
	mMap->addImageLayer(new ImageLayer(ImageLayerOptions("basemap", basemapOpt)));





	//std::string m_path = "E:\\WorkSpace\\3DWorks\\OsgEarthMFC\\x64\\Release\\imageSource\\world.shp";
	//ModelLayerOptions newLayerx = shpLoad.shpLoad(m_path, "world");
	//mMap->addModelLayer(new ModelLayer(shpcreate.shpLoad(m_path, "world")));

	OGRFeatureOptions featureOptions;
	// 根据路径加载矢量文件的驱动
	featureOptions.url() = ".\\imageSource\\world.shp";


	// 设置样式
	//Style style;

	//LineSymbol* ls = style.getOrCreateSymbol<LineSymbol>();
	//ls->stroke()->color() = Color::Yellow;
	//ls->stroke()->width() = 2.0f;

	//FeatureGeomModelOptions geomOptions;
	//geomOptions.featureOptions() = featureOptions;
	//geomOptions.styles() = new StyleSheet();
	//geomOptions.styles()->addStyle(style);
	//geomOptions.enableLighting() = false;
	

	mMap->addModelLayer(new ModelLayer(ModelLayerOptions("world", featureOptions)));


	mRoot->addChild(mapNode);
}

void OsgFrame::InitCameraConfig(){
	//RECT rect;
	CRect rect;
	mViewer = new osgViewer::Viewer;

	::GetWindowRect(m_hWnd, &rect);

	ref_ptr<GraphicsContext::Traits> traits = new GraphicsContext::Traits; 
	ref_ptr<Referenced> windata = new GraphicsWindowWin32::WindowData(m_hWnd);

	traits->x =0;

	traits->y =0;


	
	traits->width = rect.right - rect.left;

	traits->height = rect.bottom - rect.top;


	traits->windowDecoration = false;

	traits->doubleBuffer = true;

	traits->sharedContext = 0;

	traits->setInheritedWindowPixelFormat = true;

	traits->inheritedWindowData = windata;

	GraphicsContext * gc = GraphicsContext::createGraphicsContext(traits);

	ref_ptr<osg::Camera> camera = new Camera;

	camera->setGraphicsContext(gc);

	camera->setViewport(new Viewport(0, 0, traits->width, traits->height));
	camera->setProjectionMatrixAsPerspective(30.0f,
		static_cast<double>(traits->width) / static_cast<double>(traits->height), 
		1.0, 1000.0);
	mViewer->setCamera(camera);

	mViewer->setCameraManipulator(new osgGA::TrackballManipulator);

	mViewer->setSceneData(mRoot);

	mViewer->realize();

	mViewer->getCamera()->setComputeNearFarMode(osg::CullSettings::COMPUTE_NEAR_FAR_USING_PRIMITIVES);

	mViewer->getCamera()->setNearFarRatio(0.000003f);

	//mViewer->addEventHandler(new osgViewer::SStatsHandler());
	//mViewer->addEventHandler(new osgViewer::SWindowSizeHandler());
	mViewer->addEventHandler(new osgGA::StateSetManipulator(mViewer->getCamera()->getOrCreateStateSet()));

}

void OsgFrame::PreFrameUpdate()

{

}

void OsgFrame::PostFrameUpdate(){

}

void OsgFrame::Render(void * ptr) {

	OsgFrame *osg = (OsgFrame*)ptr;

	Viewer * viewer = osg->getViewer(); 
	while (!viewer->done()) {

		osg->PreFrameUpdate(); 
		viewer->frame(); 
		osg->PostFrameUpdate();
	}

	_endthread();
}

ref_ptr<Viewer> OsgFrame::getViewer() {

	return mViewer;
}

ref_ptr<Map> OsgFrame::getMap() {

	return mMap;
}


void OsgFrame::InitBackGround(){
	ref_ptr<osg::Texture2D> texture = new Texture2D;
	ref_ptr<osg::Image> image = readImageFile(".\\imageSource\\222634.png");
	texture->setImage(image.get());

	ref_ptr<osg::Drawable> quad = createTexturedQuadGeometry(osg::Vec3(), osg::Vec3(1.0f, 0.0f, 0.0f), osg::Vec3(0.0f, 1.0f, 0.0f));
	quad->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture.get());

	ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(quad.get());


	ref_ptr<osg::Camera> camera = new osg::Camera;
	camera->setClearMask(0);
	camera->setCullingActive(false);
	camera->setAllowEventFocus(false);
	camera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	camera->setRenderOrder(osg::Camera::POST_RENDER);
	camera->setProjectionMatrix(Matrix::ortho2D(0.0, 1.0, 0.0, 1.0));
	camera->addChild(geode.get());

	osg::StateSet* ss = camera->getOrCreateStateSet();
	ss->setMode(GL_LIGHTING, StateAttribute::OFF);
	ss->setAttributeAndModes(new Depth(Depth::LEQUAL, 1.0, 1.0));
	mRoot->addChild(camera.get());
}