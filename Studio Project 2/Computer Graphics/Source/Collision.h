#ifndef _COLLISION_H
#define _COLLISION_H
/*****************************************/
/*!
\file Collision
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Header file for Collision
*/
/*****************************************/
#include "Bullet.h"
#include "SpaceObject.h"
#include "StaticObject.h"
/*****************************************/
/*!
		Struct Collision
\brief
Define Collision Detection and its methods. Used to check collision between objects.
*/
/*****************************************/
struct Collision
{

	static void SpaceObjectToSpaceObject(SpaceObject* object, SpaceObject* playerShip, double &dt);
	static void MovingSpaceObjectToMovingSpaceObject(SpaceObject* object1, SpaceObject* object2, double &dt);
	static void BulletToSpaceObject(Bullet* bullet, SpaceObject* object, double &dt);
	static void GameObjectToStaticObject(GameObject* object1, StaticObject* object2);
	static bool SphereSphereCollision(SpaceObject* object, SpaceObject* object2);
	static bool LineSphereCollision(Vector3 lineOrigin, Vector3 lineForward, float lineLength, SpaceObject* object);

};
#endif