#ifndef _PHYSICS_H
#define _PHYSICS_H
/****************************************************************************/
/*!
\file Physics.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include <math.h>
#include "Vector3.h"
/******************************************************************************/
/*!
		Class Physics:
\brief
*/
/******************************************************************************/
struct Physics {

public:
	//Constructors & Destructor
	Physics();
	~Physics();

	//Getters
	static float getAccelerationFM(float F, float M);
	static float getAccelerationVUT(float v, float u, float t);
	static float getVelocityUTA(float u, float t, float a);
	static float getVelocityUAS(float u, float a, float s);
	static float getDisplacementUVT(float u, float v, float t);
	static float getDisplacementUTA(float u, float t, float a);
	static float getMomentum(float v, float m);
	static float getImpulse(float F, float t);
	static float getDistance(Vector3 a, Vector3 b);

};

#endif