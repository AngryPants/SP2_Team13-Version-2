#include"Interactable.h"
/*******************************************************/
/*!
\brief
Constructor of interactable
\param
name of the object,the bigger radius, the interact radius the mesh name,texture and material

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
\param
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
\param
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
\param
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
\param
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