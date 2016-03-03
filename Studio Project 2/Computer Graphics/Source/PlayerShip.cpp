/****************************************************************************/
/*!

\file PlayerShip.cpp
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for PlayerShip

*/
/****************************************************************************/

#include "PlayerShip.h"

/****************************************************************************************************************************/
/*!

\brief
The constructor for PlayerShip.

*/
/****************************************************************************************************************************/
PlayerShip::PlayerShip()
: Ship("Condor", 0, 8.0f, 5000.0f, "OBJ//Condor//Condor.obj", "Image//Condor//Condor.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 6000.0f, 75.0f, 8, 400, YELLOW)
{

	isMining = false;
	speed = 0.0f;

}

/****************************************************************************************************************************/
/*!

\brief
An empty destructor.

*/
/****************************************************************************************************************************/
PlayerShip::~PlayerShip() {
}

//Functions
/****************************************************************************************************************************/
/*!

\brief
Increases the speed of the PlayerShip.

\param
The amount to increase the speed by.

*/
/****************************************************************************************************************************/
void PlayerShip::IncreaseSpeed(float increaseAmount) {

	if (increaseAmount > 0.0f) {
	
		speed += increaseAmount;

		if (speed > GetMaxSpeed()) {
		
			SetSpeed(GetMaxSpeed());

		}

	}

}

/****************************************************************************************************************************/
/*!

\brief
Decreases the speed of the PlayerShip.

\param
The amount to decrease the speed by.

*/
/****************************************************************************************************************************/
void PlayerShip::DecreaseSpeed(float decreaseAmount) {

	if (decreaseAmount > 0.0f) {

		speed -= decreaseAmount;

		if (speed < 0.0f) {
		
			SetSpeed(0.0f);

		}

	}

}

/****************************************************************************************************************************/
/*!

 \brief
 Updates the PlayerShip.

 \param dt
 The time taken for this frame to complete.

*/
/****************************************************************************************************************************/
void PlayerShip::Update(double &dt) {

	UpdateTimeToFire(dt);
	UpdateBullets(dt);
	miningLaser.SetRotation(GetRotationMatrix());
	miningLaser.SetPosition(GetPosition() + GetForwardVector() * GetRadius());

}

//Is-ters
/****************************************************************************************************************************/
/*!

\brief
Gets whether the PlayerShip is currently mining or not.

\return
Returns a true if the PlayerShip is mining and a false if it is not.

*/
/****************************************************************************************************************************/
bool PlayerShip::IsMining() {

	return this->isMining;

}

//Getters
/****************************************************************************************************************************/
/*!

\brief
Gets the current speed of the player.

\return
Returns the current speed of the player.

*/
/****************************************************************************************************************************/
float PlayerShip::GetSpeed() {

	return this->speed;

}

/****************************************************************************************************************************/
/*!

\brief
Gets the mining laser of the PlayerShip.

\return
Returns the PlayerShip's mining laser.

*/
/****************************************************************************************************************************/
MiningLaser* PlayerShip::GetMiningLaser() {

	return &(this->miningLaser);	

}

//Setters
/****************************************************************************************************************************/
/*!

\brief
Sets the speed of the PlayerShip.

\param newSpeed
The new speed of the PlayerShip.

*/
/****************************************************************************************************************************/
void PlayerShip::SetSpeed(float newSpeed) {

	if (newSpeed > GetMaxSpeed()) {
	
		this->speed = GetMaxSpeed();

	} else if (newSpeed < 0.0f) {
	
		this->speed = 0.0f;

	} else {
	
		this->speed = newSpeed;

	}

}

/****************************************************************************************************************************/
/*!

\brief
Sets the whether the PlayerShip is mining or not.

\param isMining
The new value of PlayerShip's isMining.

*/
/****************************************************************************************************************************/
void PlayerShip::SetMining(bool isMining) {

	this->isMining = isMining;
	
}