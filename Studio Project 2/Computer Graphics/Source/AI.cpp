#include "AI.h"

AI::AI() {
}

AI::~AI() {
}

void AI::FaceTarget(GameObject* object, GameObject* target, float maxTurnAngle, double &dt) {
	
	float distance = Physics::getDistance(object->GetPosition(), target->GetPosition());
	float yRotation = 0.0f;
	float xRotation = 0.0f;

	if (distance < 0.1f) {
	
		return;

	} else if (distance < 30.0f && object->GetForwardVector().AngleBetween(target->GetPosition() - object->GetPosition()) <= 90) {
	
		yRotation = GenerateRange(-maxTurnAngle, maxTurnAngle);
		xRotation = GenerateRange(-maxTurnAngle, maxTurnAngle);
		Mtx44 rotate;
		rotate.SetToRotation(yRotation, 0, 1, 0);
		rotate.SetToRotation(xRotation, 1, 0, 0);
		object->Rotate(rotate);

	} else if (distance > 30.f && distance < 180.0f && object->GetForwardVector().AngleBetween(target->GetPosition() - object->GetPosition()) >= 90) {
	
		/*xRotation = GenerateRange(-maxTurnAngle, maxTurnAngle);
		if (xRotation > 15.0f) {
			xRotation = 15.0f;
		} else if (xRotation < -15.0f) {
			xRotation = -15.0f;
		}
		Mtx44 rotate;
		rotate.SetToRotation(xRotation, 1, 0, 0);
		object->Rotate(rotate);*/

		return;

	} else if (distance > 150.f && object->GetForwardVector().AngleBetween(target->GetPosition() - object->GetPosition()) <= 90) {

		//Rotating on the Y-Axis.
		Vector3 targetVector = (target->GetPosition() - object->GetPosition()).Normalized();
		Vector3 yRotationForwardVector = Vector3(object->GetForwardVector().x, 0, object->GetForwardVector().z);
		Vector3 yRotationTargetVector = Vector3(targetVector.x, 0, targetVector.z);

		if (yRotationForwardVector.Length() > Math::EPSILON && yRotationTargetVector.Length() > Math::EPSILON) {
		
			yRotationForwardVector.Normalize();
			yRotationTargetVector.Normalize();
			yRotation += yRotationForwardVector.AngleBetween(yRotationTargetVector);

			if (yRotation > maxTurnAngle) {
				yRotation = maxTurnAngle;
			}

			if (yRotationForwardVector.AngleBetween(yRotationTargetVector) > Math::EPSILON) {
				
				Mtx44 rotate;
				//I think I fixed the crash. Will have to test further to confirm. 24-2-2016.
				if (yRotationForwardVector.AngleBetween(yRotationTargetVector) < 180.0f - Math::EPSILON && yRotationForwardVector.Cross(yRotationTargetVector).Length() > Math::EPSILON && yRotationForwardVector.Cross(yRotationTargetVector).Normalized().y > 0.0f) {
			
					rotate.SetToRotation(yRotation, 0, 1, 0);

				} else {
					
					rotate.SetToRotation(-yRotation, 0, 1, 0);
					
				}

				object->Rotate(rotate);

			}

		}

		//Rotating on the X-Axis
		Vector3 xRotationForwardVector = Vector3(sqrt(1.0f - object->GetForwardVector().y * object->GetForwardVector().y) * targetVector.x, object->GetForwardVector().y, sqrt(1.0f - object->GetForwardVector().y * object->GetForwardVector().y) * targetVector.z).Normalized();
		xRotation += xRotationForwardVector.AngleBetween(targetVector);

		if (xRotation > Math::EPSILON * 100) {
		
			if (xRotation > maxTurnAngle) {
				xRotation = maxTurnAngle;
			}

			Mtx44 rotate;

			if (xRotationForwardVector.y > targetVector.y) {
		
				rotate.SetToRotation(xRotation, 1, 0, 0);

			} else {
			
				rotate.SetToRotation(-xRotation, 1, 0, 0);

			}

			object->Rotate(rotate);

		}

	}

}

void AI::MoveToTarget(Ship* ship, GameObject* target, float force, double &dt) {

	if (Physics::getDistance(ship->GetPosition(), target->GetPosition()) <= ship->GetRadius() || Physics::getDistance(ship->GetPosition(), target->GetPosition()) <= 0.1f) {
	
		return;

	}

	ship->AddRelativeForce(0.0f, 0.0f, force, dt);

	if (ship->GetVelocity().Length() > ship->GetMaxSpeed()) {
	
		ship->SetVelocity(ship->GetAcceleration() * ship->GetMaxSpeed());
		ship->SetAcceleration(0.0f, 0.0f, 0.0f);

	}

}

void AI::ShootAtTarget(Ship* ship, GameObject* target) {

	Vector3 targetVector = target->GetPosition() - ship->GetPosition();

	if (targetVector.Length() > 0.1f && Physics::getDistance(ship->GetPosition(), target->GetPosition()) <= 250.0f) {
	
		if (ship->GetForwardVector().AngleBetween(targetVector) <= 25.0f) {
		
			ship->Shoot();

		}

	}

}