#include "WarpGate.h"
/*******************************************************/
/*!
\brief
Constructor of warpGate
\param string name
the name of gate
\param vector3 position
spawn position
\param vector3 exitPosition
its exit position
\return
none
*/
/*******************************************************/
//Constructor
WarpGate::WarpGate(string name, Vector3 position, Vector3 exitPosition)
: Interactable(name, 80.0f, 40.f, "You are approaching " + name, "Press E to use the warp " + name, "OBJ//Warp_Gate//Warp_Gate.obj", "Image//Warp_Gate//Warp_Gate.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{
	SetPosition(position);
	SetExitPosition(exitPosition);
}
/*******************************************************/
/*!
\brief
Destructor of warpGate
\param
none
\return
nothing
*/
/*******************************************************/
//Destructor
WarpGate::~WarpGate() {
}
/*******************************************************/
/*!
\brief
interaction between player and object
\param player
player to check for interact
\param dt
update the interaction per frame
\return
return nothing

*/
/*******************************************************/
//Functions
void WarpGate::Interact(Player &player, double &dt) {
	player.GetShip()->SetPosition(exitPosition);
	player.GetShip()->SetVelocity(0, 0, 0);
	player.GetShip()->SetAcceleration(0, 0, 0);
}
/*******************************************************/
/*!
\brief
get the exit position of the interactable
\param
none
\return
returns the exit position
*/
/*******************************************************/
//Getters
Vector3 WarpGate::GetExitPosition() {

	return this->exitPosition;
}
/*******************************************************/
/*!
\brief
set the exit position of the object
\param vector3 position
vector 3 of the position of the object
\return
none
*/
/*******************************************************/
//Setters
void WarpGate::SetExitPosition(Vector3 position) {

	this->exitPosition = position;

}
/*******************************************************/
/*!
\brief
Alternative of setting the exit position of the warpgate
\param float x,y,z
takes in 3 floats 
\return
none
*/
/*******************************************************/
void WarpGate::SetExitPosition(float x, float y, float z) {

	SetExitPosition(Vector3(x, y, z));

}