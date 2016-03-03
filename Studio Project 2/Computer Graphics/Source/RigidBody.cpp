/****************************************************************************/
/*!
\file RigidBody.cpp
\author Lim Ngiain Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for Rigidbody.

*/
/****************************************************************************/
#include "RigidBody.h"

/*************************************************************************************************************************/
/*!

\brief
Constructor of the Rigidbody.

\param name
The name of the RigidBody

\param meshFile
The file path of the OBJ.

\param textureFile
The file path of the texture.

\param material
The material of the mesh.

\param mass
The mass of the RigidBody.

\param radius
The radius of the RigidBody.

*/
/*************************************************************************************************************************/
RigidBody::RigidBody(string name, string meshFile, const char* textureFile, Material material, float mass, float radius)
: GameObject(name, meshFile, textureFile, material) {

	this->mass = mass;
	this->radius = radius;
	this->velocity = Vector3(0, 0, 0);
	this->acceleration = Vector3(0, 0, 0);

}

/*************************************************************************************************************************/
/*!

\brief
An empty destuctor.

*/
/*************************************************************************************************************************/
RigidBody::~RigidBody() {
}

//Functions
/*************************************************************************************************************************/
/*!

\brief
Updates the position of the RigidBody based on the current velocity and acceleration.

\param dt
The time taken to process this frame.

*/
/*************************************************************************************************************************/
void RigidBody::UpdatePosition(double &dt) {

	position += Vector3(Physics::getDisplacementUTA(velocity.x, dt, acceleration.x), Physics::getDisplacementUTA(velocity.y, dt, acceleration.y), Physics::getDisplacementUTA(velocity.z, dt, acceleration.z));

}

/*************************************************************************************************************************/
/*!

\brief
Adds a new velocity to the curent velocity of the RigidBody.

\param velocity
The new velocity to add to the current velocity.

*/
/*************************************************************************************************************************/
void RigidBody::AddVelocity(Vector3 velocity) {

	this->velocity += velocity;

}

/*************************************************************************************************************************/
/*!

\brief
Adds a new velocity to the curent velocity of the RigidBody.

\param x
The new x velocity to add to the current velocity.

\param y
The new y velocity to add to the current velocity.

\param z
The new z velocity to add to the current velocity.

*/
/*************************************************************************************************************************/
void RigidBody::AddVelocity(float x, float y, float z) {

	AddVelocity(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief Adds a force to the RigidBody.

\param forceVector
The force being added to the RigidBody.

\param dt
The time this frame took to complete.

*/
/*************************************************************************************************************************/
void RigidBody::AddForce(Vector3 forceVector, double &dt) {

	if (mass >= 0.0f) {
	
		acceleration = Vector3(Physics::getAccelerationFM(forceVector.x, mass), Physics::getAccelerationFM(forceVector.y, mass), Physics::getAccelerationFM(forceVector.z, mass));
		velocity = Vector3(Physics::getVelocityUTA(velocity.x, dt, acceleration.x), Physics::getVelocityUTA(velocity.y, dt, acceleration.y), Physics::getVelocityUTA(velocity.z, dt, acceleration.z));

	}

}

/*************************************************************************************************************************/
/*!

\brief Adds a force to the RigidBody.

\param x
The force being added to the RigidBody on the x axis.

\param y
The force being added to the RigidBody on the y axis.

\param z
The force being added to the RigidBody on the z axis.

\param dt
The time this frame took to complete.

*/
/*************************************************************************************************************************/
void RigidBody::AddForce(float x, float y, float z, double &dt) {

	AddForce(Vector3(x, y, z), dt);

}

/*************************************************************************************************************************/
/*!

\brief Adds a force to the RigidBody based on the local axis.

\param forceVector
The vector of the force being added to the RigidBody based on the local axis.

\param dt
The time this frame took to complete.

*/
/*************************************************************************************************************************/
void RigidBody::AddRelativeForce(Vector3 forceVector, double &dt) {

	Mtx44 direction;
	direction.SetToTranslation(forceVector.x, forceVector.y, forceVector.z);
	direction = rotationMatrix * direction;
	AddForce(direction.a[12], direction.a[13], direction.a[14], dt);

}

/*************************************************************************************************************************/
/*!

\brief Adds a force to the RigidBody based on the local axis.

\param x
The force being added to the RigidBody on the local x axis.

\param y
The force being added to the RigidBody on the local y axis.

\param z
The force being added to the RigidBody on the local z axis.

\param dt
The time this frame took to complete.

*/
/*************************************************************************************************************************/
void RigidBody::AddRelativeForce(float x, float y, float z, double &dt) {

	AddRelativeForce(Vector3(x, y, z), dt);

}

//Setters
/*************************************************************************************************************************/

/*!

\brief
Sets the velocity of the RigidBody.

\param velocity
The new velocity to set the current velocity to.

*/

/*************************************************************************************************************************/
void RigidBody::SetVelocity(Vector3 velocity) {

	this->velocity = velocity;

}

/*************************************************************************************************************************/

/*!

\brief
Sets the velocity of the RigidBody.

\param x
The new velocity to set the current x velocity to.

\param y
The new velocity to set the current y velocity to.

\param z
The new velocity to set the current z velocity to.

*/

/*************************************************************************************************************************/
void RigidBody::SetVelocity(float x, float y, float z) {

	SetVelocity(Vector3(x, y, z));

}

/*************************************************************************************************************************/
/*!

\brief
Sets the mass of the RigidBody.

\param mass
The new mass of the RigidBody.

*/
/*************************************************************************************************************************/
void RigidBody::SetMass(float mass) {

	if (mass > 0.0f) {
	
		this->mass = mass;

	} else {
	
		this->mass = 0.0f;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Sets the radius of the RigidBody.

\param mass
The new radius of the RigidBody.

*/
/*************************************************************************************************************************/
void RigidBody::SetRadius(float radius) {

	if (radius > 0.0f) {
	
		this->radius = radius;

	} else {
	
		this->radius = 0.0f;

	}

}

/*************************************************************************************************************************/
/*!

\brief
Sets the acceleration of the RigidBody.

\param acceleration
The new acceleration of the RigidBody.

*/
/*************************************************************************************************************************/
void RigidBody::SetAcceleration(Vector3 acceleration) {

	this->acceleration = acceleration;

}

/*************************************************************************************************************************/
/*!

\brief
Sets the acceleration of the RigidBody.

\param x
The new x acceleration of the RigidBody.

\param y
The new y acceleration of the RigidBody.

\param z
The new z acceleration of the RigidBody.

*/
/*************************************************************************************************************************/
void  RigidBody::SetAcceleration(float x, float y, float z) {

	SetAcceleration(Vector3(x, y, z));

}

//Getters
/*************************************************************************************************************************/
/*!

\brief
Gets the radius of the RigidBody.

\return
Returns the radius of the RigidBody.

*/
/*************************************************************************************************************************/
float RigidBody::GetRadius() {
	
	return this->radius;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the mass of the RigidBody.

\return
Returns the mass of the RigidBody.

*/
/*************************************************************************************************************************/
float RigidBody::GetMass() {

	return this->mass;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the velocity of the RigidBody.

\return
Returns the velocity of the RigidBody.

*/
/*************************************************************************************************************************/
Vector3 RigidBody::GetVelocity() {

	return this->velocity;

}

/*************************************************************************************************************************/
/*!

\brief
Gets the acceleration of the RigidBody.

\return
Returns the acceleration of the RigidBody.

*/
/*************************************************************************************************************************/
Vector3 RigidBody::GetAcceleration() {

	return this->acceleration;

}

//Static Functions
/*************************************************************************************************************************/
/*!

\brief
Updates a RigidBody.

\param rigidbody
The RigidBody to be updated.

\param dt
The time taken for this frame to complete.

*/
/*************************************************************************************************************************/
void RigidBody::UpdateRigidBody(RigidBody* rigidbody, double &dt) {

	rigidbody->UpdatePosition(dt);

}

/*************************************************************************************************************************/
/*!

\brief
Updates a list of RigidBodies.

\param rigidbodies
The RigidBodies to be updated.

\param dt
The time taken for this frame to complete.

*/
/*************************************************************************************************************************/
void RigidBody::UpdateRigidBody(list<RigidBody*> rigidbodies, double &dt) {

	for (list<RigidBody*>::iterator iter = rigidbodies.begin(); iter != rigidbodies.end(); ++iter) {
	
		UpdateRigidBody(*iter, dt);

	}

}