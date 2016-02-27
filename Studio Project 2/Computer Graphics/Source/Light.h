#ifndef _LIGHT_H
#define _LIGHT_H

#include "Vertex.h"

struct Light {

public:
	Position position;
	Colour colour;
	float power;
	float kC, kL, kQ;

	//Constructors & Destructor
	Light();

	enum LIGHT_TYPE {
	
		LIGHT_POINT = 0,
		LIGHT_DIRECTIONAL,
		LIGHT_SPOT,

	};

	LIGHT_TYPE type;
	Vector3 spotDirection;
	float cosCutoff;
	float cosInner;
	float exponent;

};

#endif