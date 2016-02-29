#include "Inventory.h"

//Constructor
Inventory::Inventory() {

	SetGold(0);

}

//Destructor
Inventory::~Inventory() {
}

//Functions
void Inventory::AddGold(int gold) {

	this->gold += gold;

}

bool Inventory::DecreaseGold(int gold) {

	if (gold > this->gold) {
	
		return false;

	}

	this->gold -= gold;
	return true;

}

void Inventory::AddItem(Item item, int numItems) {

	if (numItems <= 0) {
	
		return;

	}

	//map<Item, int>::iterator mapPtr = items.find(item);

	/*if (mapPtr == items.end()) {
	
		items.insert(std::pair<Item, int>(item, numItems));

	} else {
	
		mapPtr->second += numItems;

	}*/

}

bool Inventory::DecreaseItem(Item item, int numItem) {

	/*map<Item, int>::iterator mapPtr = items.find(item);

	if (numItem <= 0 || mapPtr == items.end() || mapPtr->second < numItem) {
		
		return false;

	}

	mapPtr->second -= numItem;
	
	if (mapPtr->second == 0) {
	
		mapPtr = items.erase(mapPtr);

	}*/

	return true;

}

//Getters
int Inventory::GetGold() {

	return this->gold;

}

int Inventory::GetNumberOf(Item item) {

	return 0;

	/*map<Item, int>::iterator mapPtr = items.find(item);

	if (mapPtr == items.end()) {
	
		return 0;

	}

	return mapPtr->second;*/

}

//Setters
void Inventory::SetGold(int gold) {
	 
	if (gold >= 0) {
	
		this->gold = gold;

	}

}