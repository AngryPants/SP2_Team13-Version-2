/****************************************************************************/
/*!
\file Player.cpp
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for Player
*/
/****************************************************************************/

#include "Player.h"

/****************************************************************************/
/*!

\brief
Constructor for Player.

\param name
The name of the Player.

\param questFile
The file path of the Player's Quest file.

\param inventoryFile
The file path of the Player's Inventory file.

\param shipFile
The file path of the PlayerShip file.

*/
/****************************************************************************/
Player::Player(string name, string questFile, string inventoryFile, string shipFile) {

	this->name = name;
	SetGodMode(false);

}

/****************************************************************************/
/*!

\brief
An empty destructor

*/
/****************************************************************************/
Player::~Player() {
}

//Getters
/****************************************************************************/
/*!

\brief
Gets the name of the Player.

\return
Returns the name of the Player.

*/
/****************************************************************************/
string Player::GetName() {

	return this->name;

}

/****************************************************************************/
/*!

\brief
Gets the Inventory of the Player.

\return
Returns the Inventory of the Player.

*/
/****************************************************************************/
Inventory* Player::GetInventory() {

	return &(this->inventory);

}

/****************************************************************************/
/*!

\brief
Gets the Quests of the Player.

\return
Returns the Quests of the Player.

*/
/****************************************************************************/
list<Quest>* Player::GetQuests() {

	return &(this->quests);

}

/****************************************************************************/
/*!

\brief
Gets the PlayerShip of the Player.

\return
Returns the PlayerShip of the Player.

*/
/****************************************************************************/
PlayerShip* Player::GetShip() {

	return &(this->ship);

}

/****************************************************************************/
/*!

\brief
Gets the current PLAYER_STATE of the Player.

\return
Returns the current PLAYER_STATE of the Player.

*/
/****************************************************************************/
PLAYER_STATE Player::GetState() {

	return this->playerState;

}

/****************************************************************************/
/*!

\brief
Gets whether or not the Player is invincible.

\return
Returns true if the Player is invincible and false if the Player is not.

*/
/****************************************************************************/
bool Player::GodModeOn() {

	return this->godMode;

}

//Setters
/****************************************************************************/
/*!

\brief
Sets the PLAYER_STATE of the Player.

\param playerState
The new PLAYER_STATE of the Player.

*/
/****************************************************************************/
void Player::SetState(PLAYER_STATE playerState) {

	this->playerState = playerState;

}

/****************************************************************************/
/*!

\brief
Turns on or off the Player's invincibility.

\param mode
The new state of the Player's invincibility.

*/
/****************************************************************************/
void Player::SetGodMode(bool mode) {

	this->godMode = mode;

}