/****************************************************************************/
/*!

\file Inventory.cpp
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for Inventory

*/
/****************************************************************************/

#include "Inventory.h"

/**********************************************************************************************************************/
/*!

\brief
Default constructor for the Inventory.

*/
/**********************************************************************************************************************/
Inventory::Inventory() {

	SetGold(0);

}

/**********************************************************************************************************************/
/*!

\brief
An empty destructor

*/
/**********************************************************************************************************************/
Inventory::~Inventory() {
}

//Functions
/**********************************************************************************************************************/
/*!

\brief
Adds gold to the Inventory.

\param gold
The amount of gold to add to the Inventory.

*/
/**********************************************************************************************************************/
void Inventory::AddGold(int gold) {

	this->gold += gold;

}

/**********************************************************************************************************************/
/*!

\brief
Decreases gold to the Inventory.

\param gold
The amount of gold to decrease from the Inventory.

*/
/**********************************************************************************************************************/
bool Inventory::DecreaseGold(int gold) {

	if (gold > this->gold) {
	
		return false;

	}

	this->gold -= gold;
	return true;

}

/**********************************************************************************************************************/
/*!

\brief
Adds Items to the Inventory.

\param item
The Item to add to the Inventory.

\param numItems
The number of Items to add.

*/
/**********************************************************************************************************************/
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

/**********************************************************************************************************************/
/*!

\brief
Removes Items from the Inventory.

\param item
The Item to remove from the Inventory.

\param numItems
The number of Items to remove.

*/
/**********************************************************************************************************************/
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
/**********************************************************************************************************************/
/*!

\brief
Gets the amount of gold in the Inventory.

\return
Returns the amount of gold in the Inventory.

*/
/**********************************************************************************************************************/
int Inventory::GetGold() {

	return this->gold;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the number of an Item in the Inventory.

\param item
The Item to check for.

*/
/**********************************************************************************************************************/
int Inventory::GetNumberOf(Item item) {

	map<Item, int>::iterator mapIter = items.find(item);

	if (mapIter == items.end()) {
	
		return 0;

	}

	return mapIter->second;

}

/**********************************************************************************************************************/
/*!

\brief
Gets the map of items in the Inventory.

\return
Return the map of items in the Inventory.

*/
/**********************************************************************************************************************/
map<Item, int>* Inventory::GetItems() {

	return &(this->items);

}

//Setters
/**********************************************************************************************************************/
/*!

\brief
Sets the amount of gold in the Inventory.

\param gold
The new amount of gold in the Inventory.

*/
/**********************************************************************************************************************/
void Inventory::SetGold(int gold) {
	 
	if (gold >= 0) {
	
		this->gold = gold;

	}

}