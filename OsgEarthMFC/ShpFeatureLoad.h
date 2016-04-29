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
* ���� shp���ݲ�����
* �汾�� 1.0
* ���� ������
* ����ʱ��  2016 4 20
* �޸�ʱ��
*/
class ShpFeatureLoad
{
public:
	/*!
	* ���� ����·������shp���ݣ������ó�ʼ����
	* ���� filepath: ����·��
	*      layerName ͼ������
	* ����ֵ ������ص����ݹ��ɵ�ModelLayerͼ��
	* �汾�� 1.0
	* ���� ������
	* ����ʱ��  2016 4 20
	* �޸�ʱ��
	*/
	ModelLayerOptions shpLoad(string filepath, string layerName);

	/*!
	* ���� ������Ҫ����ʽ
	* ���� width ���
	*      color Ҫ����ɫ
	* ����ֵ Ҫ����ʽ
	* �汾�� 1.0
	* ���� ������
	* ����ʱ��  2016 4 20
	* �޸�ʱ��
	*/
	Style setStyles(float width, Color color);

	/*!
	* ���� ������Ҫ����ʽ
	* ���� width ���ο��
	*      color Ҫ����ɫ
	* isFill �Ƿ����
	* fillColor ���ɫ
	* ����ֵ Ҫ����ʽ
	* �汾�� 1.0
	* ���� ������
	* ����ʱ��  2016 4 20
	* �޸�ʱ��
	*/
	Style setStyles(float width, Color color, bool isFill, Color fileColor);

	/*!
	* ���� ���õ�Ҫ����ʽ
	* ���� size Ҫ�ش�С
	*       color ��ɫ
	*		iconPath ͼ��·��
	* ����ֵ Ҫ����ʽ
	* �汾�� 1.0
	* ���� ������
	* ����ʱ��  2016 4 20
	* �޸�ʱ��
	*/
	Style setStyles(float size, Color color, string iconPath);

	/*!
	* ���� ����ע����ʽ
	* ����  fieldName ��ע�ֶ���
	*       priority �����ֶ�
	*		 size  ע���ֺ�
	*		 textSymbol ע��λ��
	*		 fillColor �����ɫ
	*		 haloColor ������ɫ
	* ����ֵ Ҫ����ʽ
	* �汾�� 1.0
	* ���� ������
	* ����ʱ��  2016 4 20
	* �޸�ʱ��
	*/
	Style setLabel(string fieldName, string priority, float size, TextSymbol textSymbol, Color fillColor, Color haloColor);
};

