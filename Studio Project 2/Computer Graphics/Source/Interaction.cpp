#include "Interaction.h"

//Static Variable
string Interaction::message = "";
/*******************************************************/
/*!
\brief
Constructor of interaction
\param
none
\return
nothing
*/
/*******************************************************/
//Constructor
Interaction::Interaction() {
}
/*******************************************************/
/*!
\brief
Destructor of interaction
\param
none
\return
nothing
*/
/*******************************************************/
//Destructor
Interaction::~Interaction() {
}
/*******************************************************/
/*!
\brief
Get Render Message
\param
none
\return
returns a string "message"
*/
/*******************************************************/
string Interaction::GetRenderMessage()
{
	return message;
}
/*******************************************************/
/*!
\brief
interaction between playership and different interactables
\param player 
to make the player to interact
\param objects 
the object the player is gonna interact with
\param dt
to update per frame
\return
none
*/
/*******************************************************/
bool Interaction::ShipToObject(Player &player, Interactable* object, double &dt) {

	if (Physics::getDistance(player.GetShip()->GetPosition(), object->GetPosition()) < object->GetApproachRadius()) 
	{
		if (Physics::getDistance(player.GetShip()->GetPosition(), object->GetPosition()) > object->GetInteractRadius()) 
		{
			message = object->GetApproachMessage();
			return true;
		} 
		else 
		{
			message = object->GetInteractMessage();

			if (object->GetName() != "Carrick Station" ) 
			{
				if (Application::IsKeyPressed('E'))
				{

					object->Interact(player, dt);

				}
			}
			else
			{

				object->Interact(player, dt);

			}
			return true;
		}

	}
	else
	{
		message = "";
		return false;
	}

}