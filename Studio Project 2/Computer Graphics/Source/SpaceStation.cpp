#include "SpaceStation.h"
#include "PlayerShip.h"

/*******************************************************/
/*!
\brief
constructor of SpaceStation
\param
none
\return
nothing
*/
/*******************************************************/
SpaceStation::SpaceStation(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material, unsigned int sceneNumber)
: Interactable(name, approachRadius, interactRadius, approachMessage, interactMessage, meshFile, textureFile, material)
{
	this->sceneNumber = sceneNumber;
}
/*******************************************************/
/*!
\brief
constructor of SpaceStation
\param
none
\return
nothing
*/
/*******************************************************/
SpaceStation::~SpaceStation() {
}
/*******************************************************/
/*!
\brief
Interaction between player and spacestation
\param
player and dt
\return
nothing
*/
/*******************************************************/
void SpaceStation::Interact(Player &player, double &dt)
{
	//playAnimation
	
	if (player.GetShip()->GetPosition().x < -20)
	{
	player.GetShip()->Translate(10.0f * dt, 0, 0);
	}
	else if (player.GetShip()->GetPosition().x > 20)
	{
	player.GetShip()->Translate(-10.0f * dt, 0, 0);
	}
	else if (player.GetShip()->GetPosition().y < -20)
	{
	player.GetShip()->Translate(0, 10.0f * dt, 0);
	}
	else if (player.GetShip()->GetPosition().y > 20)
	{
	player.GetShip()->Translate(0, -10.0f * dt, 0);
	}
	else if (player.GetShip()->GetPosition().z < -20)
	{
	player.GetShip()->Translate(0, 0, 10.0f * dt);
	}
	else if (player.GetShip()->GetPosition().z > 20)
	{
	player.GetShip()->Translate(0, 0, -10.0f * dt);
	}
	else
	{
		Load::SaveFile("Text/PlayerStat.txt", player);
		SharedData::GetInstance()->sceneNumber = 1;
	}

}









