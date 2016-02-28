#include "Item.h"

//Constructors
Item::Item() {

	name = "<Item Name>";
	value = 0;

}

Item::Item(string name, int value) {

	this->name = name;
	
	if (value >= 0) {
	
		this->value = value;

	} else {
	
		this->value = 0;

	}

}

//Destructors
Item::~Item() {
}

//Functions
bool Item::operator==(Item &rhs) {

	if (rhs.GetName() == GetName() && rhs.GetValue() == GetValue()) {
	
		return true;

	}

	return false;

}

bool Item::operator!=(Item &rhs) {

	if (rhs.GetName() != GetName() || rhs.GetValue() != GetValue()) {
	
		return true;

	}

	return false;

}

//Getters
string Item::GetName() {

	return this->name;

}

int Item::GetValue() {

	return this->value;

}