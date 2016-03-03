#ifndef _STATIC_OBJECT_H
#define _STATIC_OBJECT_H
/****************************************************************************/
/*!
\file StaticObject.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "GameObject.h"
/******************************************************************************/
/*!
		Class StaticObject:
\brief
*/
/******************************************************************************/
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