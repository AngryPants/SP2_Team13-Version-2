#ifndef _RIGIDBODY_H
#define _RIGIDBODY_H
/****************************************************************************/
/*!
\file RigidBody.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "GameObject.h"
#include "Physics.h"
#include <list>

using std::list;
/******************************************************************************/
/*!
		Class RigidBody:
\brief
*/
/******************************************************************************/
class RigidBody : public GameObject {

protected:
	//Variables
	float radius;
	float mass;
	Vector3 velocity;
	Vector3 acceleration;

	//Constructor
	RigidBody(string name, string meshFile, const char* textureFile, Material material, float mass, float radius);

public:
	//Destructor
	virtual ~RigidBody();

	//Functions
	void UpdatePosition(double &dt);
	void AddVelocity(Vector3 velocity);
	void AddVelocity(float x, float y, float z);
	void AddForce(Vector3 forceVector, double &dt);
	void AddForce(float x, float y, float z, double &dt);
	void AddRelativeForce(Vector3 forceVector, double &dt);
	void AddRelativeForce(float x, float y, float z, double &dt);

	//Setters
	void SetVelocity(Vector3 velocity);
	void SetVelocity(float x, float y, float z);
	void SetAcceleration(Vector3 acceleration);
	void SetAcceleration(float x, float y, float z);
	void SetMass(float mass);
	void SetRadius(float radius);

	//Getters
	Vector3 GetVelocity();
	Vector3 GetAcceleration();
	float GetRadius();
	float GetMass();

	//Static Functions
	static void UpdateRigidBody(RigidBody* rigidbody, double &dt);
	static void UpdateRigidBody(list<RigidBody*> rigidbodies, double &dt);

};

#endif