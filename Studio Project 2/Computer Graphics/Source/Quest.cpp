#include "Quest.h"

/****************************************************************************/
/*!

\brief
Default constructor for Quest.

*/
/****************************************************************************/
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

/****************************************************************************/
/*!

\brief
An empty destructor.

*/
/****************************************************************************/
Quest::~Quest() {
}

/****************************************************************************/
/*!

\brief
Updates the quest.

*/
/****************************************************************************/
void Quest::Update() {

	if (isActive && !isComplete && current >= target) {
	
		isComplete = true;

	}

}

/****************************************************************************/
/*!

\brief
Hands in the quest.

*/
/****************************************************************************/
void Quest::HandIn() {

	isActive = false;
	isComplete = true;

}

/****************************************************************************/
/*!

\brief
Cancels in the quest.

*/
/****************************************************************************/
void Quest::Cancel() {

	isActive = false;
	isComplete = false;
	current = 0;

}

/****************************************************************************/
/*!

\brief
Picks up in the quest.

*/
/****************************************************************************/
void Quest::PickUp() {

	isComplete = false;
	isActive = true;
	current = 0;

}

/****************************************************************************/
/*!

\brief
An overloaded == operator for Quest.

\param rhs
The quest to compare to.

*/
/****************************************************************************/
bool Quest::operator==(const Quest &rhs) {

	if (&rhs == &(*this)) {
	
		return true;

	} else {
	
		return false;

	}

}