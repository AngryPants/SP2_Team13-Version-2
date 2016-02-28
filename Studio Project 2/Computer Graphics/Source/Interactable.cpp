#include"Interactable.h"

//Constructor
Interactable::Interactable(string name, float approachRadius, float interactRadius, string approachMessage, string interactMessage, string meshFile, const char* textureFile, Material material)
: GameObject(name, meshFile, textureFile, material)
{
	
	this->approachRadius = approachRadius;
	this->interactRadius = interactRadius;
	this->approachMessage = approachMessage;
	this->interactMessage = interactMessage;

}

//Destructor
Interactable::~Interactable() {
}

//Getters
string Interactable::GetApproachMessage() {

	return this->approachMessage;

}

string Interactable::GetInteractMessage() {

	return this->interactMessage;

}

float Interactable::GetApproachRadius() {

	return this->approachRadius;

}

float Interactable::GetInteractRadius() {

	return this->interactRadius;

}

//Setters
void Interactable::SetApproachMessage(string message) {

	this->approachMessage = message;

}

void Interactable::SetInteractMessage(string message) {

	this->interactMessage = message;

}

void Interactable::SetApproachRadius(float radius) {

	this->approachMessage = radius;

}

void Interactable::SetInteractRadius(float radius) {

	if (radius > approachRadius) {
	
		this->interactRadius = approachRadius;

	} else {
	
		this->interactRadius = radius;

	}

}