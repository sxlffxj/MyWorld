#pragma once

#include <osgViewer/Viewer> 
#include <osgViewer/ViewerEventHandlers> 
#include <osgGA/StateSetManipulator> 
#include <osgGA/TrackballManipulator> 

#include <osgDB/ReadFile>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osg/Notify>
#include <osgEarth/Map> 
#include <osgEarth/MapNode> 
#include <osgEarthDrivers/agglite/AGGLiteOptions>
#include <osgEarthDrivers/gdal/GDALOptions> 
#include <osgEarthDrivers/bing/BingOptions> 
#include <osgEarthDrivers/model_feature_geom/FeatureGeomModelOptions>  
#include <osgEarthDrivers/feature_ogr/OGRFeatureOptions>
#include <osgEarthDrivers/cache_filesystem/FileSystemCache>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/GeodeticGraticule>
#include <osgEarthUtil/LatLongFormatter>
#include <osgEarthUtil/Controls>
#include <osgEarthUtil/MouseCoordsTool>
#include <osgEarthUtil/AutoClipPlaneHandler>
#include <osg/Group>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgUtil\optimizer>

#include <osg/AutoTransform>
#include <osg/DrawPixels>
#include <osg/Depth>
#include <osg/Texture2D> 
#include <osg/Geometry>

#include <osgEarthSymbology/Style>
#include <osgEarth/ModelLayer> 

#include <osgEarthDrivers/tms/TMSOptions>
#include <osgEarthUtil/EarthManipulator>

using namespace osg;
using namespace osgDB;
using namespace osgEarth;
using namespace osgEarth::Drivers;
using namespace osgEarth::Symbology;
using namespace osgEarth::Util;
using namespace osgViewer;

class OsgFrame
{
public:
	OsgFrame(HWND hWnd);
	~OsgFrame(void);

	void InitOSG();


	void InitSceneGraph();
	void InitCameraConfig();
	void InitBackGround();
	void PreFrameUpdate();
	void PostFrameUpdate();
	static void Render(void* ptr);

	ref_ptr<Viewer> getViewer();

	ref_ptr<Map> getMap();

private:
	HWND m_hWnd;
	ref_ptr<Viewer> mViewer;
	ref_ptr<Group> mRoot;
	ref_ptr<Map> mMap;

};

