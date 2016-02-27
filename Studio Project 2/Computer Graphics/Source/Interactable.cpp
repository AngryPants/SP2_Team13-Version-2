#include"Interactable.h"

Interactable::Interactable(float messageRadius, float interactRadius, string message,  string name, string meshFile, const char* textureFile, Material material) : GameObject(name, meshFile, textureFile, material) {
	
	this->messageRadius = messageRadius;
	this->interactRadius = interactRadius;
	this->message = message;
	this->isInteracting = false;

}

Interactable::~Interactable() {
}

string Interactable::GetRenderMessage() {
	
	return message;

}

float Interactable::GetMessageRadius() {
	
	return messageRadius;

}
float Interactable::GetInteractRadius() {
	
	return interactRadius;

}

bool Interactable::GetInteracting() {

	return isInteracting;

}

//Setters
void Interactable::SetRenderMessage(string message) {
	
	this->message = message;

}

void Interactable::SetMessageRadius(float radius) {

	if (radius <= 0.0f) {
	
		this->messageRadius = 0.0f;

	} else {

		this->messageRadius = radius;

	}

}

void Interactable::SetInteractRadius(float radius) {

	if (radius > GetMessageRadius()) {
	
		this->interactRadius = GetMessageRadius();

	} else {
		
		this->interactRadius = radius;

	}

}

void Interactable::SetInteracting(bool interact) {

	this->isInteracting = interact;

}