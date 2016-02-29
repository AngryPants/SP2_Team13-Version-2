#include "Collision.h"



void Collision::BulletToSpaceObject(Bullet* bullet, SpaceObject* object) {

	//Do Collision check here.

}

void Collision::SpaceObjectToSpaceObject(SpaceObject* object1, SpaceObject* object2, double &dt)
{

	if (Physics::getDistance(object1->GetAcceleration(), object2->GetPosition()) < 0.1f) {
	
		return;

	}

	if (CollisionCheck(object1, object2)) {
	
		object1->DecreaseHealth(((object2->GetVelocity().Length() + object1->GetVelocity().Length()) * dt)/2.0f);
		object2->DecreaseHealth(((object2->GetVelocity().Length() + object1->GetVelocity().Length()) * dt)/2.0f);

		if ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) > 50.0f) {
		
			object1->AddForce((object1->GetPosition() - object2->GetPosition()).Normalized() * ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) * 800.0f), dt);
			object2->AddForce((object2->GetPosition() - object1->GetPosition()).Normalized() * ((object1->GetVelocity().Length() + object2->GetVelocity().Length()) * 800.0f), dt);

		} else {
		
			object1->AddForce((object1->GetPosition() - object2->GetPosition()).Normalized() * (40.0f * 800.0f), dt);
			object2->AddForce((object2->GetPosition() - object1->GetPosition()).Normalized() * (40.0f * 800.0f), dt);
		
		}
		

	}

}

void Collision::GameObjectToStaticObject(GameObject* object, StaticObject* object2) {
}

bool Collision::CollisionCheck(SpaceObject* object1, SpaceObject* object2) {
	// Early Escape test: if the length of the movevec is less
	// than distance between the centers of these circles minus
	// their radii, there's no way they can hit.
	double dist = Physics::getDistance(object2->GetPosition(), object1->GetPosition());//B.center.distance(A.center);
	double sumRadii = (object2->GetRadius() + object1->GetRadius());
	dist -= sumRadii;

	Vector3 movevec;
	movevec = object1->GetVelocity();

	//float movevec = Physics::getDistance(object1->GetPosition(), object1->GetPosition() + object1->GetForwardVector());
	if ( movevec.Length() < dist){
		return false;
	}

	// Normalize the movevec
	Vector3 N = movevec;
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

bool Collision::CollisionCheck(SpaceObject* object, Bullet &bullets) {
	// Early Escape test: if the length of the movevec is less
	// than distance between the centers of these circles minus
	// their radii, there's no way they can hit.

	double dist = Physics::getDistance(object->GetPosition(), bullets.GetPosition() );//B.center.distance(A.center);
	double sumRadii =object->GetRadius();
	dist -= sumRadii;

	Vector3 movevec;
	movevec = object->GetVelocity();

	//float movevec = Physics::getDistance(object1->GetPosition(), object1->GetPosition() + object1->GetForwardVector());
	if (movevec.Length() < dist){
		return false;
	}

	// Normalize the movevec
	Vector3 N = movevec;
	N.Normalize();

	// Find C, the vector from the center of the moving
	// circle A to the center of B
	Vector3 C = bullets.GetPosition() - object->GetPosition();//.center.minus(A.center);

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