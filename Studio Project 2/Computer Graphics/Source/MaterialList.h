#ifndef _MATERIALLIST_H
#define _MATERIALLIST_H

#include "Material.h"

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