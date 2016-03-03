#ifndef _INVENTORY_H
#define _INVENTORY_H
/****************************************************************************/
/*!

\file Inventory.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header file for Inventory

*/
/****************************************************************************/
#include "Item.h"
#include <list>
#include <map>

using std::list;
using std::map;
/*****************************************/
/*!
		Class Inventory
\brief
Defines Inventory, used to store the player's gold and Items.
*/
/*****************************************/
class Inventory {

private:
	int gold;
	map<Item, int> items;

public:
	//Constructor & Destructor
	Inventory();
	~Inventory();

	//Functions
	void AddGold(int gold);
	bool DecreaseGold(int gold);
	void AddItem(Item item, int numItems);
	bool DecreaseItem(Item item, int numItems);

	//Getters
	int GetGold();
	int GetNumberOf(Item item);
	map<Item, int>* GetItems();

	//Setters
	void SetGold(int gold);;

};

#endif