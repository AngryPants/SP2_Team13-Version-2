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

	map<Item, int>::iterator mapIter = items.find(item);

	if (mapIter == items.end()) {
	
		items.insert(std::pair<Item, int>(item, numItems));

	} else {
	
		mapIter->second += numItems;

	}

}

bool Inventory::DecreaseItem(Item item, int numItem) {

	map<Item, int>::iterator mapIter = items.find(item);

	if (numItem <= 0 || mapIter == items.end() || mapIter->second < numItem) {
		
		return false;

	}

	mapIter->second -= numItem;
	
	if (mapIter->second == 0) {
	
		mapIter = items.erase(mapIter);

	}

	return true;

}

//Getters
int Inventory::GetGold() {

	return this->gold;

}

int Inventory::GetNumberOf(Item item) {

	map<Item, int>::iterator mapIter = items.find(item);

	if (mapIter == items.end()) {
	
		return 0;

	}

	return mapIter->second;

}

map<Item, int>* Inventory::GetItems() {

	return &(this->items);

}

//Setters
void Inventory::SetGold(int gold) {
	 
	if (gold >= 0) {
	
		this->gold = gold;

	}

}