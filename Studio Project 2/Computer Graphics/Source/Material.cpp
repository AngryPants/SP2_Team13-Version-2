#include "Material.h"

//Component
Component::Component(float r, float g, float b) {

	Set(r, g, b);

}

void Component::Set(float r, float g, float b) {

	this->r = r;
	this->g = g;
	this->b = b;

}

Component::~Component() {
}

//Material
Material::Material() {

	Component kAmbient(0.1f, 0.1f, 0.1f);
	Component kDiffuse(0.1f, 0.1f, 0.1f);
	Component kSpecular(0.1f, 0.1f, 0.1f);
	
	float kShiniess = 0;

}

Material::~Material() {

}