#ifndef _STATIC_OBJECT_H
#define _STATIC_OBJECT_H

#include "GameObject.h"

class StaticObject : public GameObject {

protected:
	//Variables
	Vector3 dimensions;

	//Constructor
	StaticObject(string name, Vector3 position, Vector3 dimensions, string meshFile, const char* textureFile, Material material);

public:
	//Destructor
	virtual ~StaticObject();

	//Getter
	Vector3 GetDimensions();

};

#endif