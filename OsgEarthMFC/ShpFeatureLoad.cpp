#include "stdafx.h"
#include "ShpFeatureLoad.h"


/*!
* ���� ShpLayerOperatorʵ��
* �汾�� 1.0
* ���� ������
* ����ʱ��  2016 4 20
* �޸�ʱ��
*/

#include "stdafx.h"
#include "ShpFeatureLoad.h"



ModelLayerOptions ShpFeatureLoad::shpLoad(string filepath, string layerName){
	OGRFeatureOptions featureOptions;
	// ����·������ʸ���ļ�������
	featureOptions.url() = filepath;


	// ������ʽ
	Style style;

	LineSymbol* ls = style.getOrCreateSymbol<LineSymbol>();
	ls->stroke()->color() = Color::Yellow;
	ls->stroke()->width() = 2.0f;

	FeatureGeomModelOptions geomOptions;
	geomOptions.featureOptions() = featureOptions;
	geomOptions.styles() = new StyleSheet();
	geomOptions.styles()->addStyle(style);
	geomOptions.enableLighting() = false;

	ModelLayerOptions layerOptions(layerName, geomOptions);
	return layerOptions;

}


Style ShpFeatureLoad::setStyles(float width, Color color){
	Style style;

	LineSymbol* ls = style.getOrCreateSymbol<LineSymbol>();
	ls->stroke()->color() = color;
	ls->stroke()->width() = width;



	return style;
}



Style ShpFeatureLoad::setStyles(float width, Color color, bool isFill, Color fileColor){
	return NULL;
}



Style ShpFeatureLoad::setStyles(float size, Color color, string iconPath){
	return NULL;
}



Style ShpFeatureLoad::setLabel(string fieldName, string priority, float size, TextSymbol textSymbol, Color fillColor, Color haloColor){
	return NULL;
}

