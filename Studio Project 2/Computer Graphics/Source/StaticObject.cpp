#include "StaticObject.h"

/****************************************************************************/
/*!

\brief
Constructor for StaticObject

\param name
The name of the StaticObject.

\param position
The position of the StaticObject

\param dimensions
The dimensions of the StaticObject

\param meshFile
The file path of the OBJ.

\param textureFile
The file path of the texture.

\param material
The material of the StaticObject.

*/
/****************************************************************************/
StaticObject::StaticObject(string name, Vector3 position, Vector3 dimensions, string meshFile, const char* textureFile, Material material)
: GameObject(name, meshFile, textureFile, material) {

	this->dimensions = dimensions;
	this->position = position;

}

/****************************************************************************/
/*!

\brief
An empty destructor

*/
/****************************************************************************/
StaticObject::~StaticObject() {
}


//Getters
/****************************************************************************/
/*!

\brief
Gets the dimensions of the object.

\return
Returns the dimensions of the object.

*/
/****************************************************************************/
Vector3 StaticObject::GetDimensions() {

	return this->dimensions;

}