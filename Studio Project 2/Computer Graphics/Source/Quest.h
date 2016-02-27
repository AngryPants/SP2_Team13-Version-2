#ifndef _QUEST_H
#define _QUEST_H

#include <string>
#include <vector>
#include "Inventory.h"

using std::string;

class Quest {

public:
	Quest();
	~Quest();
	void Update();
	void HandIn();
	void Cancel();
	void PickUp();
	bool operator==(const Quest &rhs);

	string name;
	string description;
	string giver;
	
	int conditionID;
	
	int current;
	int target;
	
	bool isActive;
	bool isComplete;
	
	int reward;

};

#endif