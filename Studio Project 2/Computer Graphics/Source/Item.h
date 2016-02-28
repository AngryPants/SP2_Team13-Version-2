#ifndef _ITEM_H
#define _ITEM_H

#include <string>

using std::string;

class Item {

private:
	//Variables
	string name;
	int value;

public:
	//Constructor & Destructor
	Item();
	Item(string name, int value);
	~Item();

	//Functions
	bool operator==(Item &rhs);
	bool operator!=(Item &rhs);

	//Getters
	string GetName();
	int GetValue();

};

#endif