#ifndef _MATERIALLIST_H
#define _MATERIALLIST_H
/****************************************************************************/
/*!
\file MaterialList.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for MaterialList.

*/
/****************************************************************************/
#include "Material.h"
/*****************************************/
/*!
		Class MaterialList
\brief
Defines MaterialList, a singleton which stores various presets of materials.

*/
/*****************************************/
class MaterialList {

public:

	enum MATERIAL_TYPE {
	
		PLASTIC = 0,
		METAL,
		PAPER,
		SAND,
		CEMENT,

		//Total Number of Enum
		MAX_MATERIAL,
	
	};

	Material material[MAX_MATERIAL];

	static MaterialList* GetInstance();
	~MaterialList();

private:
	MaterialList();

};

#endif