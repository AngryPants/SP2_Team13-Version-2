#ifndef _INVENTORY_H
#define _INVENTORY_H

#include "Item.h"
#include <list>
#include <map>

using std::list;
using std::map;

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
	void AddItem(Item* item, int numItems);
	bool DecreaseItem(Item* item, int numItems);

	//Getters
	int GetGold();
	int GetNumberOf(Item *item);

	//Setters
	void SetGold(int gold);;

};

#endif