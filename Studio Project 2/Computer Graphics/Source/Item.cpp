#include "Item.h"

//Constructors
Item::Item() {

	name = "";
	value = 0;
	itemID = 0;

}

Item::Item(string name, int value, int itemID) {

	this->name = name;
	
	if (value >= 0) {
	
		this->value = value;

	} else {
	
		this->value = 0;

	}

	if (itemID >= 0) {
	
		this->itemID = itemID;

	} else {
	
		this->itemID = 0;

	}

}

//Destructors
Item::~Item() {
}

//Functions
bool Item::operator==(Item &rhs) {

	if (rhs.GetID() == GetID()) {
	
		return true;

	}

	return false;

}

bool Item::operator!=(Item &rhs) {

	if (rhs.GetID() != GetID()) {
	
		return true;

	}

	return false;

}

bool Item::operator<(const Item &rhs) const {

	if (rhs.GetID() > GetID()) {
	
		return true;

	}

	return false;

}

//Getters
string Item::GetName() {

	return this->name;

}

string Item::GetName() const {

	return this->name;

}

int Item::GetValue() {

	return this->value;

}

int Item::GetID() {

	return this->itemID;

}

int Item::GetID() const {

	return this->itemID;

}