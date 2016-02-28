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

void Inventory::AddItem(Item* item, int numItems) {

	if (items.find(item->GetName()) == items.end()) {
	
		list<Item> newItems;

		for (int i = 0; i < numItems; ++i) {
		
			newItems.push_front(*item);
			items.insert(std::pair<string, list<Item>>(item->GetName(), newItems));

		}

	} else {
	
		list<Item>* listPtr = &(items.find(item->GetName())->second);
		
		for (int i = 0; i < numItems; ++i) {
			
			listPtr->push_front(*item);

		}

	}

}

int Inventory::DecreaseItem(Item* item, int numItem) {

	if (numItem <= 0 || items.find(item->GetName()) == items.end()) {
	
		return 0;

	}
	
	int itemsRemoved = 0;
	list<Item>* listPtr = &(items.find(item->GetName())->second);

	for (list<Item>::iterator iter = listPtr->begin(); iter != listPtr->end() && itemsRemoved <= numItem;) {
	
		iter = listPtr->erase(iter);
		++itemsRemoved;

	}

	if (listPtr->size() == 0) {
	
		items.erase(item->GetName());

	}

	return itemsRemoved;

}

//Getters
int Inventory::GetGold() {

	return this->gold;

}

int Inventory::GetNumberOf(Item* item) {

	if (items.find(item->GetName()) == items.end()) {
	
		return 0;

	}

	return items.find(item->GetName())->second.size();

}

//Setters
void Inventory::SetGold(int gold) {
	 
	if (gold >= 0) {
	
		this->gold = gold;

	}

}