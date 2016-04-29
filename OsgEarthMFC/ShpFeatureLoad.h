#pragma once
#include <osg/Notify>
#include <osgGA/StateSetManipulator>
#include <osgEarthUtil/ExampleResources>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/AutoClipPlaneHandler>
#include <osgEarthSymbology/Style>
#include <osgEarthFeatures/ConvertTypeFilter>
#include <osgEarthDrivers/feature_ogr/OGRFeatureOptions>
#include <osgEarthDrivers/agglite/AGGLiteOptions>
#include <osgEarthDrivers/model_feature_geom/FeatureGeomModelOptions>
#include <osgEarthDrivers/model_feature_stencil/FeatureStencilModelOptions>
#include <osgDB/WriteFile>

using namespace std;
using namespace osgEarth;
using namespace osgEarth::Features;
using namespace osgEarth::Drivers;
using namespace osgEarth::Symbology;
using namespace osgEarth::Util;
/*!
* 功能 shp数据操作类
* 版本号 1.0
* 作者 樊晓剑
* 创建时间  2016 4 20
* 修改时间
*/
class ShpFeatureLoad
{
public:
	/*!
	* 功能 根据路径加载shp数据，并配置初始参数
	* 参数 filepath: 数据路径
	*      layerName 图层名称
	* 返回值 所需加载的数据构成的ModelLayer图层
	* 版本号 1.0
	* 作者 樊晓剑
	* 创建时间  2016 4 20
	* 修改时间
	*/
	ModelLayerOptions shpLoad(string filepath, string layerName);

	/*!
	* 功能 设置线要素样式
	* 参数 width 宽度
	*      color 要素颜色
	* 返回值 要素样式
	* 版本号 1.0
	* 作者 樊晓剑
	* 创建时间  2016 4 20
	* 修改时间
	*/
	Style setStyles(float width, Color color);

	/*!
	* 功能 设置面要素样式
	* 参数 width 外晕宽度
	*      color 要素颜色
	* isFill 是否填充
	* fillColor 填充色
	* 返回值 要素样式
	* 版本号 1.0
	* 作者 樊晓剑
	* 创建时间  2016 4 20
	* 修改时间
	*/
	Style setStyles(float width, Color color, bool isFill, Color fileColor);

	/*!
	* 功能 设置点要素样式
	* 参数 size 要素大小
	*       color 颜色
	*		iconPath 图标路径
	* 返回值 要素样式
	* 版本号 1.0
	* 作者 樊晓剑
	* 创建时间  2016 4 20
	* 修改时间
	*/
	Style setStyles(float size, Color color, string iconPath);

	/*!
	* 功能 设置注记样式
	* 参数  fieldName 标注字段名
	*       priority 优先字段
	*		 size  注记字号
	*		 textSymbol 注记位置
	*		 fillColor 填充颜色
	*		 haloColor 外晕颜色
	* 返回值 要素样式
	* 版本号 1.0
	* 作者 樊晓剑
	* 创建时间  2016 4 20
	* 修改时间
	*/
	Style setLabel(string fieldName, string priority, float size, TextSymbol textSymbol, Color fillColor, Color haloColor);
};

