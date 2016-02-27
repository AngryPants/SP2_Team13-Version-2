#include "SpaceStation.h"
#include "PlayerShip.h"

SpaceStation::SpaceStation(float messageRadius, float interactRadius, string message, string name, string meshFile, const char* textureFile, Material material, unsigned int sceneNumber)
: Interactable(messageRadius,interactRadius, message,name,meshFile, textureFile,material)
{

	this->sceneNumber = sceneNumber;

}

SpaceStation::~SpaceStation() {
}

void SpaceStation::Interact(RigidBody * object, double &dt)
{
	
	if (Physics::getDistance(object->GetPosition(), this->GetPosition())<GetMessageRadius() && Physics::getDistance(object->GetPosition(), this->GetPosition())>GetInteractRadius()) {

		SetRenderMessage("Heading Towards " + GetName());

	} else if (Physics::getDistance(object->GetPosition(), this->GetPosition())<GetInteractRadius()) {
		
		SetRenderMessage("Entering " + GetName());
		SetInteracting(true);
		PlayAnimation(object,dt);

	} else { //Not close to the station.

		SetRenderMessage("");

	}

}

void SpaceStation::PlayAnimation(RigidBody * object, double &dt) {

	if (GetInteracting() == true) {

		//playAnimation
		if (object->GetPosition().x < -20)
		{
			object->Translate(10.0f * dt, 0, 0);
		}
		else if (object->GetPosition().x > 20)
		{
			object->Translate(-10.0f * dt, 0, 0);
		}
		else if (object->GetPosition().y < -20)
		{
			object->Translate(0, 10.0f * dt, 0);
		}
		else if (object->GetPosition().y > 20)
		{
			object->Translate(0, -10.0f * dt, 0);
		}
		else if (object->GetPosition().z < -20)
		{
			object->Translate(0, 0, 10.0f * dt);
		}
		else if (object->GetPosition().z > 20)
		{
			object->Translate(0, 0, -10.0f * dt);
		}
		else 
		{
			SharedData::GetInstance()->sceneNumber = sceneNumber;
		}

		SetInteracting(false);

	}
}








