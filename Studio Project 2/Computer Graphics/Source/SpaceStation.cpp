#include "SpaceStation.h"
#include "PlayerShip.h"

SpaceStation::SpaceStation(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material, unsigned int sceneNumber)
: Interactable(name, approachRadius, interactRadius, approachMessage, interactMessage, meshFile, textureFile, material)
{
	this->sceneNumber = sceneNumber;
}

SpaceStation::~SpaceStation() {
}

void SpaceStation::Interact(Player &player, double &dt)
{
	
	SharedData::GetInstance()->sceneNumber = 1;

}

void SpaceStation::PlayAnimation(Player &object, double &dt) {

	/*if (GetInteracting() == true) {

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

	}*/

}








