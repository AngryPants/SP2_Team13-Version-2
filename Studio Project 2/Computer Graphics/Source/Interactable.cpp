#include"Interactable.h"
/*****************************************/
/*!
\file Interactable.cpp
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Create the Object class of interactables
*/
/*****************************************/

/*******************************************************/
/*!
\brief
Constructor of interactable
\param string name
name of the object
\param approachRadius
the bigger radius
\param interactRadius
the interact radius 
\param approachMessage
the message the player gets while close
\param interact radius
the interact radius
\param meshfile the mesh name
texture of the
\param material
material of the object
\return
nothing
*/
/*******************************************************/
//Constructor
Interactable::Interactable(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material)
: GameObject(name, meshFile, textureFile, material)
{
	
	this->approachRadius = approachRadius;
	this->interactRadius = interactRadius;
	this->approachMessage = approachMessage;
	this->interactMessage = interactMessage;

}
/*******************************************************/
/*!
\brief
Destructor of interactable
\param
none
\return
nothing
*/
/*******************************************************/
//Destructor
Interactable::~Interactable() {
}
/*******************************************************/
/*!
\brief
Get Approach Message
\param
none
\return
approaching message
*/
/*******************************************************/
//Getters
string Interactable::GetApproachMessage() {

	return this->approachMessage;

}
/*******************************************************/
/*!
\brief
get interact Message
\param
none
\return
return the interacting message
*/
/*******************************************************/
string Interactable::GetInteractMessage() {

	return this->interactMessage;

}
/*******************************************************/
/*!
\brief
get approaching radius of the object
\param
none
\return
return the approach radius of the object
*/
/*******************************************************/
float Interactable::GetApproachRadius() {

	return this->approachRadius;

}
/*******************************************************/
/*!
\brief
get interacting radius of the object
\param
none
\return
return the interacting radius of the object

*/
/*******************************************************/
float Interactable::GetInteractRadius() {

	return this->interactRadius;

}
/*******************************************************/
/*!
\brief
set the approach message of the object
\param message
a approach message for the object
\return
none
*/
/*******************************************************/
//Setters
void Interactable::SetApproachMessage(string message) {

	this->approachMessage = message;

}
/*******************************************************/
/*!
\brief
set the interact message of the object
\param message
a interact message for the obj
\return
none

*/
/*******************************************************/
void Interactable::SetInteractMessage(string message) {

	this->interactMessage = message;

}
/*******************************************************/
/*!
\brief
set the approach radius of the object
\param radius
set the appr radius of the obj
\return
none
*/
/*******************************************************/
void Interactable::SetApproachRadius(float radius) {

	this->approachMessage = radius;

}
/*******************************************************/
/*!
\brief

set the approach radius of the object
\param radius
set the radius of the interact radius
\return
none
*/
/*******************************************************/
void Interactable::SetInteractRadius(float radius) {

	if (radius > approachRadius) {
	
		this->interactRadius = approachRadius;

	} else {
	
		this->interactRadius = radius;

	}

}