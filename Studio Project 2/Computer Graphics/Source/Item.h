#ifndef _ITEM_H
#define _ITEM_H

#include <string>

using std::string;

class Item {

private:
	//Variables
	string name;
	int itemID;
	int value;

public:
	//Constructor & Destructor
	Item();
	Item(string name, int value, int itemID);
	~Item();

	//Functions
	bool operator==(Item &rhs);
	bool operator!=(Item &rhs);
	bool operator<(const Item &rhs) const;

	//Getters
	string GetName();
	string GetName() const;
	int GetID();
	int GetID() const;
	int GetValue();

};

#endif