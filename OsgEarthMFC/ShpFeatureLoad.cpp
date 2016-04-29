#include "stdafx.h"
#include "ShpFeatureLoad.h"


/*!
* 功能 ShpLayerOperator实现
* 版本号 1.0
* 作者 樊晓剑
* 创建时间  2016 4 20
* 修改时间
*/

#include "stdafx.h"
#include "ShpFeatureLoad.h"



ModelLayerOptions ShpFeatureLoad::shpLoad(string filepath, string layerName){
	OGRFeatureOptions featureOptions;
	// 根据路径加载矢量文件的驱动
	featureOptions.url() = filepath;


	// 设置样式
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

