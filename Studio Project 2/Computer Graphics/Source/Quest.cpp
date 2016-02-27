#include "Quest.h"

Quest::Quest() {

	name = "<Quest Name>";
	description = "<Quest Description>";
	giver = "<Quest Giver>";

	conditionID = 0;

	current = 0;
	target = 1;

	isActive = false;
	isComplete = false;

}

Quest::~Quest() {
}

void Quest::Update() {

	if (isActive && !isComplete && current >= target) {
	
		isComplete = true;

	}

}

void Quest::HandIn() {

	isActive = false;
	isComplete = true;

}

void Quest::Cancel() {

	isActive = false;
	isComplete = false;
	current = 0;

}

void Quest::PickUp() {

	isComplete = false;
	isActive = true;
	current = 0;

}

bool Quest::operator==(const Quest &rhs) {

	if (&rhs == &(*this)) {
	
		return true;

	} else {
	
		return false;

	}

}