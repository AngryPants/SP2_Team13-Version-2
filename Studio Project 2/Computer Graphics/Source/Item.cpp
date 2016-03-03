#include "Item.h"

/**********************************************************************************************************************/
/*!

\brief
A default constructor.

*/
/**********************************************************************************************************************/
Item::Item() {

	name = "";
	value = 0;
	itemID = 0;

}

/**********************************************************************************************************************/
/*!

\brief
A constructor for Item.

\param name
The name of the Item.

\param value
How much gold each item is worth.

\param itemID
The ID of the item.

*/
/**********************************************************************************************************************/
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

/**********************************************************************************************************************/
/*!

\brief
An empty destructor.

*/
/**********************************************************************************************************************/
Item::~Item() {
}

//Functions
/**********************************************************************************************************************/
/*!

\brief
An overload == operator for Item.

\param rhs
The Item to compare to.

*/
/**********************************************************************************************************************/
bool Item::operator==(Item &rhs) {

	if (rhs.GetID() == GetID()) {
	
		return true;

	}

	return false;

}

/**********************************************************************************************************************/
/*!

\brief
An overload != operator for Item.

\param rhs
The Item to compare to.

*/
/**********************************************************************************************************************/
bool Item::operator!=(Item &rhs) {

	if (rhs.GetID() != GetID()) {
	
		return true;

	}

	return false;

}

/**********************************************************************************************************************/
/*!

\brief
An overload < operator for Item.

\param rhs
The Item to compare to.

*/
/**********************************************************************************************************************/
bool Item::operator<(const Item &rhs) const {

	if (rhs.GetID() > GetID()) {
	
		return true;

	}

	return false;

}

//Getters
/**********************************************************************************************************************/
/*!

\brief
Gets the name of the Item.

\rerturn
Returns the name of the Item.

*/
/**********************************************************************************************************************/
string Item::GetName() {

	return this->name;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the name of the Item.

\rerturn
Returns the name of the Item.

*/
/**********************************************************************************************************************/
string Item::GetName() const {

	return this->name;

}


/**********************************************************************************************************************/
/*!

\brief
Gets the value of the Item.

\rerturn
Returns the value of the Item.

*/
/**********************************************************************************************************************/
int Item::GetValue() {

	return this->value;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the ID of the Item.

\rerturn
Returns the ID of the Item.

*/
/**********************************************************************************************************************/
int Item::GetID(){

	return this->itemID;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the ID of the Item.

\rerturn
Returns the ID of the Item.

*/
/**********************************************************************************************************************/
int Item::GetID() const {

	return this->itemID;

}