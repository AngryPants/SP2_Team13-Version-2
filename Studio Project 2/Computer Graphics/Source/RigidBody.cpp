#include "RigidBody.h"

//Constructor
RigidBody::RigidBody(string name, string meshFile, const char* textureFile, Material material, float mass, float radius)
: GameObject(name, meshFile, textureFile, material) {

	this->mass = mass;
	this->radius = radius;
	this->velocity = Vector3(0, 0, 0);
	this->acceleration = Vector3(0, 0, 0);

}

//Destructor
RigidBody::~RigidBody() {
}

//Functions
void RigidBody::UpdatePosition(double &dt) {

	position += Vector3(Physics::getDisplacementUTA(velocity.x, dt, acceleration.x), Physics::getDisplacementUTA(velocity.y, dt, acceleration.y), Physics::getDisplacementUTA(velocity.z, dt, acceleration.z));

}

void RigidBody::AddVelocity(Vector3 velocity) {

	this->velocity += velocity;

}

void RigidBody::AddVelocity(float x, float y, float z) {

	AddVelocity(Vector3(x, y, z));

}

void RigidBody::AddForce(Vector3 forceVector, double &dt) {

	if (mass >= 0.0f) {
	
		acceleration = Vector3(Physics::getAccelerationFM(forceVector.x, mass), Physics::getAccelerationFM(forceVector.y, mass), Physics::getAccelerationFM(forceVector.z, mass));
		velocity = Vector3(Physics::getVelocityUTA(velocity.x, dt, acceleration.x), Physics::getVelocityUTA(velocity.y, dt, acceleration.y), Physics::getVelocityUTA(velocity.z, dt, acceleration.z));

	}

}

void RigidBody::AddForce(float x, float y, float z, double &dt) {

	AddForce(Vector3(x, y, z), dt);

}

void RigidBody::AddRelativeForce(Vector3 forceVector, double &dt) {

	Mtx44 direction;
	direction.SetToTranslation(forceVector.x, forceVector.y, forceVector.z);
	direction = rotationMatrix * direction;
	AddForce(direction.a[12], direction.a[13], direction.a[14], dt);

}

void RigidBody::AddRelativeForce(float x, float y, float z, double &dt) {

	AddRelativeForce(Vector3(x, y, z), dt);

}

//Setters
void RigidBody::SetVelocity(Vector3 velocity) {

	this->velocity = velocity;

}

void RigidBody::SetVelocity(float x, float y, float z) {

	SetVelocity(Vector3(x, y, z));

}

void RigidBody::SetMass(float mass) {

	if (mass > 0.0f) {
	
		this->mass = mass;

	} else {
	
		this->mass = 0.0f;

	}

}

void RigidBody::SetRadius(float radius) {

	if (radius > 0.0f) {
	
		this->radius = radius;

	} else {
	
		this->radius = 0.0f;

	}

}

void RigidBody::SetAcceleration(Vector3 acceleration) {

	this->acceleration = acceleration;

}

void  RigidBody::SetAcceleration(float x, float y, float z) {

	SetAcceleration(Vector3(x, y, z));

}

//Getters
float RigidBody::GetRadius() {
	
	return this->radius;

}

float RigidBody::GetMass() {

	return this->mass;

}

Vector3 RigidBody::GetVelocity() {

	return this->velocity;

}

Vector3 RigidBody::GetAcceleration() {

	return this->acceleration;

}

//Static Functions
void RigidBody::UpdateRigidBody(RigidBody* rigidbody, double &dt) {

	rigidbody->UpdatePosition(dt);

}

void RigidBody::UpdateRigidBody(list<RigidBody*> rigidbodies, double &dt) {

	for (list<RigidBody*>::iterator iter = rigidbodies.begin(); iter != rigidbodies.end(); ++iter) {
	
		UpdateRigidBody(*iter, dt);

	}

}