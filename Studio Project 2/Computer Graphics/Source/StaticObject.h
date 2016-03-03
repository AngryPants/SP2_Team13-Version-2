#ifndef _STATIC_OBJECT_H
#define _STATIC_OBJECT_H
/****************************************************************************/
/*!
\file StaticObject.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for StaticObject

*/
/****************************************************************************/
#include "GameObject.h"
/******************************************************************************/
/*!
		Class StaticObject:
\brief
Defines StaticObject, a child class of GameObject.

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