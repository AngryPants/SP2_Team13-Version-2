#ifndef _MATERIAL_H
#define _MATERIAL_H

struct Component {

public:
	float r, g, b;
	
	//Constructors & Destructors
	Component(float r = 0.1f, float g = 0.1f, float b = 0.1f);
	~Component();
	
	//Setters
	void Set(float r, float g, float b);

};

struct Material {

public:
	Component kAmbient;
	Component kDiffuse;
	Component kSpecular;
	float kShininess;

	//Constructors & Destructor
	Material();
	~Material();

};

#endif