#include "Collision.h"
/*****************************************/
/*!
\file Collision.cpp
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Collision Methods and functions
*/
/*****************************************/
/*******************************************************/
/*!
\brief
effect of collision between bullet and objects
\param bullet
to find the different relevant vectors and radius
\param SpaceObject 
to find the different relevant vectors and radius
\param dt
to update the object and check against update
\return
none
*/
/*******************************************************/
void Collision::BulletToSpaceObject(Bullet* bullet, SpaceObject* object, double& dt) {
	
	if (bullet->GetSpeed() <= 0.1f || object->GetRadius() <= 0.1f) {
	
		return;

	}

	if (LineSphereCollision(bullet->GetPosition(), bullet->GetForwardVector(), bullet->GetSpeed() * dt, object)) {
	
		object->DecreaseHealth(bullet->GetDamage());
		bullet->Despawn();

	}

}
/*******************************************************/
/*!
\brief
effects of collision between spaceobject and playership
\param spaceobject
the object the ship collides to
\param playership 
the playership to apply collision
\param dt
to update the object and check against update
\return
none
*/
/*******************************************************/
void Collision::SpaceObjectToSpaceObject(SpaceObject* object, SpaceObject* playerShip, double &dt)
{

	if (Physics::getDistance(object->GetPosition(), playerShip->GetPosition()) < 0.1f) {
	
		return;

	}

	if (SphereSphereCollision(object, playerShip)) {
	
		playerShip->DecreaseHealth(((playerShip->GetVelocity().Length() + object->GetVelocity().Length()) * dt * 30.0f));

		if (object->GetMass() > playerShip->GetMass()) {
		
			playerShip->SetPosition(object->GetPosition() + (playerShip->GetPosition() - object->GetPosition()).Normalized() * (playerShip->GetRadius() + object->GetRadius()));

		} else if (object->GetMass() < playerShip->GetMass()) {
		
			object->SetPosition(playerShip->GetPosition() + (object->GetPosition() - playerShip->GetPosition()).Normalized() * (playerShip->GetRadius() + object->GetRadius()));

		} else {
		
			Vector3 objectPosition = object->GetPosition();
			object->SetPosition(playerShip->GetPosition() + (object->GetPosition() - playerShip->GetPosition()).Normalized() * ((playerShip->GetRadius() + object->GetRadius())/1.0f));
			playerShip->SetPosition(objectPosition + (playerShip->GetPosition() - objectPosition).Normalized() * ((playerShip->GetRadius() + object->GetRadius())/1.0f));

		}

		if ((object->GetVelocity().Length() + playerShip->GetVelocity().Length()) > 20.0f) {
		
			object->AddForce((object->GetPosition() - playerShip->GetPosition()).Normalized() * ((object->GetVelocity().Length() + playerShip->GetVelocity().Length()) * 800.0f), dt);
			playerShip->AddForce((playerShip->GetPosition() - object->GetPosition()).Normalized() * ((object->GetVelocity().Length() + playerShip->GetVelocity().Length()) * 800.0f), dt);

		} else {
		
			object->AddForce((object->GetPosition() - playerShip->GetPosition()).Normalized() * (20.0f * 800.0f), dt);
			playerShip->AddForce((playerShip->GetPosition() - object->GetPosition()).Normalized() * (20.0f * 800.0f), dt);
		
		}

	}

}
/*******************************************************/
/*!
\brief
effects of collision between 2 moving spaceobjects
\param spaceobject1
moving spaceobj1 collision
\param spaceobject2
moving spaceobj2 collision
\param dt
to update the object and check against update
\return
none
*/
/*******************************************************/
void Collision::MovingSpaceObjectToMovingSpaceObject(SpaceObject* object1, SpaceObject* object2, double &dt)
{

	if (Physics::getDistance(object1->GetPosition(), object2->GetPosition()) < 0.1f) {
	
		return;

	}

	if (SphereSphereCollision(object1, object2)) {
	
		object1->DecreaseHealth(((object2->GetVelocity().Length() + object1->GetVelocity().Length()) * dt));
		object2->DecreaseHealth(((object2->GetVelocity().Length() + object1->GetVelocity().Length()) * dt));

		if ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) > 20.0f) {
		
			object1->AddForce((object1->GetPosition() - object2->GetPosition()).Normalized() * ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) * 800.0f), dt);
			object2->AddForce((object2->GetPosition() - object1->GetPosition()).Normalized() * ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) * 800.0f), dt);

		} else {
		
			object1->AddForce((object1->GetPosition() - object2->GetPosition()).Normalized() * (20.0f * 800.0f), dt);
			object2->AddForce((object2->GetPosition() - object1->GetPosition()).Normalized() * (20.0f * 800.0f), dt);
		
		}

	}

}
/*******************************************************/
/*!
\brief
Collision Detection between 2 spaceobjects with their own radius
\param spaceObject1
sphere radius of spaceobject1
\param spaceobject2
sphere radius of spaceobject2 

\return
none
*/
/*******************************************************/
bool Collision::SphereSphereCollision(SpaceObject* object1, SpaceObject* object2) {
	// Early Escape test: if the length of the movevec is less
	// than distance between the centers of these circles minus
	// their radii, there's no way they can hit.
	double dist = Physics::getDistance(object2->GetPosition(), object1->GetPosition());//B.center.distance(A.center);
	double sumRadii = (object2->GetRadius() + object1->GetRadius());

	if (dist <= sumRadii) {
	
		return true;

	}

	dist -= sumRadii;

	Vector3 movevec;
	movevec = object1->GetVelocity();

	if (movevec.Length() < dist) {

		return false;

	}

	// Normalize the movevec
	Vector3 N = movevec; //This crashes when trying to normalise.
	N.Normalize();

	// Find C, the vector from the center of the moving
	// circle A to the center of B
	Vector3 C = object2->GetPosition() - object1->GetPosition();//.center.minus(A.center);

	// D = N . C = ||C|| * cos(angle between N and C)
	double D = N.Dot(C);//N.dot(C);

	// Another early escape: Make sure that A is moving
	// towards B! If the dot product between the movevec and
	// B.center - A.center is less that or equal to 0,
	// A isn't isn't moving towards B
	if (D <= 0){
		return false;
	}

	// Find the length of the vector C
	double lengthC = C.Length();

	double F = (lengthC * lengthC) - (D * D);

	// Escape test: if the closest that A will get to B
	// is more than the sum of their radii, there's no
	// way they are going collide
	double sumRadiiSquared = sumRadii * sumRadii;
	if (F >= sumRadiiSquared){
		return false;
	}

	// We now have F and sumRadii, two sides of a right triangle.
	// Use these to find the third side, sqrt(T)
	double T = sumRadiiSquared - F;

	// If there is no such right triangle with sides length of
	// sumRadii and sqrt(f), T will probably be less than 0.
	// Better to check now than perform a square root of a
	// negative number.
	if (T < 0){
		return false;
	}

	// Therefore the distance the circle has to travel along
	// movevec is D - sqrt(T)
	double distance = D - sqrt(T);

	// Get the magnitude of the movement vector
	double mag = movevec.Length();

	// Finally, make sure that the distance A has to move
	// to touch B is not greater than the magnitude of the
	// movement vector.
	if (mag < distance){
		return false;
	}

	// Set the length of the movevec so that the circles will just
	// touch
	movevec.Normalize();
	movevec*distance;

	return true;

}
/*******************************************************/
/*!
\brief
Collision detection between a bullet and a spaceobject with radius
\param vector3 lineOrigin
check for the line vector3 updates
\param vector3 lineForward
check for the forward vector
\param float lineLength 
check for the length
\param spaceObject 
check against a spaceobject
\return
none
*/
/*******************************************************/
bool Collision::LineSphereCollision(Vector3 lineOrigin, Vector3 lineForward, float lineLength, SpaceObject* object) {

	//Discriminant
	float b = 2 * ((lineForward.x * (lineOrigin.x - object->GetPosition().x)) + (lineForward.y * (lineOrigin.y - object->GetPosition().y)) + (lineForward.z * (lineOrigin.z - object->GetPosition().z)));
	float c = (lineOrigin.x - object->GetPosition().x) * (lineOrigin.x - object->GetPosition().x) +
			  (lineOrigin.y - object->GetPosition().y) * (lineOrigin.y - object->GetPosition().y) +
			  (lineOrigin.z - object->GetPosition().z) * (lineOrigin.z - object->GetPosition().z) -
			  (object->GetRadius() * object->GetRadius());

	if ((b*b - 4*c) < 0.0f) {
	
		return false;

	}

	float d1 = -b + sqrt(b*b - 4*c);
	float d2 = -b - sqrt(b*b - 4*c);

	if (d1 <= lineLength || d2<= lineLength) {
	
		return true;

	}

	return false;

}