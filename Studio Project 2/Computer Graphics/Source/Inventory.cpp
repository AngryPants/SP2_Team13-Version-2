#include "Inventory.h"

//Constructor
Inventory::Inventory() {

	SetGold(0);
	SetVeldspar(0);
	SetOmber(0);
	SetKernite(0);

}

//Destructor
Inventory::~Inventory() {
}

//Functions
void Inventory::AddGold(int gold) {

	this->gold += gold;

}

void Inventory::AddVeldspar(int veldspar) {

	this->veldspar += veldspar;

}

void Inventory::AddOmber(int omber) {

	this->omber += omber;

}

void Inventory::AddKernite(int kernite) {

	this->kernite += kernite;

}

bool Inventory::DecreaseGold(int gold) {

	if (gold > this->gold) {
	
		return false;

	}

	this->gold -= gold;
	return true;

}

bool Inventory::DecreaseVeldspar(int veldspar) {

	if (veldspar > this->veldspar) {
	
		return false;

	}

	this->veldspar -= veldspar;
	return true;

}

bool Inventory::DecreaseOmber(int omber) {

	if (omber > this->omber) {
	
		return false;

	}

	this->omber -= omber;
	return true;

}

bool Inventory::DecreaseKernite(int kernite) {

	if (kernite > this->kernite) {

		return false;

	}

	this->kernite -= kernite;
	return true;

}

//Getters
int Inventory::GetGold() {

	return this->gold;

}

int Inventory::GetVeldspar() {

	return this->veldspar;

}

int Inventory::GetOmber() {

	return this->veldspar;

}

int Inventory::GetKernite() {

	return this->kernite;

}

//Setters
void Inventory::SetGold(int gold) {
	 
	if (gold >= 0) {
	
		this->gold = gold;

	}

}	 
	 
void Inventory::SetVeldspar(int velspar) {

	if (velspar >= 0) {
	
		this->veldspar = veldspar;

	}

}

void Inventory::SetOmber(int omber) {

	if (omber >= 0) {
	
		this->omber = omber;

	}

}

void Inventory::SetKernite(int kernite) {

	if (kernite >= 0) {
	
		this->kernite = kernite;

	}

}