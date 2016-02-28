#include "Interaction.h"

//Static Variable
string Interaction::message = "";

//Constructor
Interaction::Interaction() {
}

//Destructor
Interaction::~Interaction() {
}

void Interaction::ShipToObject(Player &player, Interactable* object, double &dt) {

	if (Physics::getDistance(player.GetShip()->GetPosition(), object->GetPosition()) < object->GetApproachRadius()) {
	
		if (Physics::getDistance(player.GetShip()->GetPosition(), object->GetPosition()) > object->GetInteractRadius()) {
		
			message = object->GetApproachMessage();

		} else {
		
			message = object->GetInteractMessage();

			if (Application::IsKeyPressed('E')) {
			
				object->Interact(player, dt);

			}

		}

	}

}