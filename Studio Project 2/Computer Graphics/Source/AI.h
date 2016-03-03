#ifndef _AI_H
#define _AI_H
/****************************************************************************/
/*!
\file AI.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header for AI

*/
/****************************************************************************/
#include "Ship.h"
#include "GenerateRange.h"
/*****************************************/
/*!
		Struct AI
\brief
Defines AI, a struct that holds the static functions for enemy ship's behaviour.

*/
/*****************************************/
struct AI {

public:
	//Constructor & Destructor
	AI();
	~AI();

	static void FaceTarget(GameObject* object, GameObject* target, float maxTurnAngle, double &dt);
	static void MoveToTarget(Ship* ship, GameObject* target, float force, double &dt);
	static void ShootAtTarget(Ship* ship, GameObject* target);

};

#endif