#include "WarpGate.h"

//Constructor
WarpGate::WarpGate(string name, Vector3 position, Vector3 exitPosition)
: Interactable(name, 60.0f, 20.f, "You are approaching " + name, "Press E to use the warp gate.", "OBJ//Portal//Portal.obj", "Image//Portal//PortalText.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{
	SetPosition(position);
	SetExitPosition(exitPosition);
}

//Destructor
WarpGate::~WarpGate() {
}

//Functions
void WarpGate::Interact(Player &player, double &dt) {
	player.GetShip()->SetPosition(exitPosition);
}

void WarpGate::PlayAnimation(Player &player, double &dt) {
	
}

//Getters
Vector3 WarpGate::GetExitPosition() {

	return this->exitPosition;
}

//Setters
void WarpGate::SetExitPosition(Vector3 position) {

	this->exitPosition = position;

}

void WarpGate::SetExitPosition(float x, float y, float z) {

	SetExitPosition(Vector3(x, y, z));

}