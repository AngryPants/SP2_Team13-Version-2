#ifndef _AI_H
#define _AI_H
#include "Ship.h"

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