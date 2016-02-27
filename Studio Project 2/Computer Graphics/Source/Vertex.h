#ifndef _VERTEX_H
#define _VERTEX_H

#include "Colour.h"
#include "Position.h"
#include "Vector3.h"

struct TexCoord {

	float u, v;
	
	TexCoord(float u = 0, float v = 0) {
		Set(u, v);
	}

	~TexCoord() {
	}

	void Set(float u, float v) {
		this->u = u;
		this->v = v;
	}

};

struct Vertex {

	Position position;
	Colour colour;
	Vector3 normal;
	TexCoord texCoord;

};

#endif