#include "StaticObject.h"

//Constructor
StaticObject::StaticObject(string name, Vector3 position, Vector3 dimensions, string meshFile, const char* textureFile, Material material)
: GameObject(name, meshFile, textureFile, material) {

	this->dimensions = dimensions;
	this->position = position;

}

//Destructor
StaticObject::~StaticObject() {
}


//Getters
Vector3 StaticObject::GetDimensions() {

	return this->dimensions;

}