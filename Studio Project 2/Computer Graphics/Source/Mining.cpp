/****************************************************************************/
/*!
\file Mining.cpp
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
CPP file for Mining

*/
/****************************************************************************/

#include "Mining.h"

/****************************************************************************************************************/
/*!

\brief
Mines an asteroid and fixes the player's Ship.

\param playerShip
The player's ship.

\param asteroid
The Asteroid currently being mined.

\param dt
The time taken for this frame to be completed.

*/
/****************************************************************************************************************/
void Mining::Mine(PlayerShip* playerShip, Asteroid* asteroid, double &dt) {

	if (Application::IsKeyPressed(VK_RBUTTON)) {

		playerShip->SetMining(true);

		if (Physics::getDistance(playerShip->GetPosition(), asteroid->GetPosition()) <= (350.0f + playerShip->GetRadius() + asteroid->GetRadius())) {

			if (Collision::LineSphereCollision(playerShip->GetPosition(), playerShip->GetForwardVector(), 350.0f + playerShip->GetRadius() + asteroid->GetRadius(), asteroid)) {
			
				MiningLaser* miningLaser = playerShip->GetMiningLaser();
				miningLaser->AddZRotation(360 * dt);
				miningLaser->Rotate(0, 0, miningLaser->GetZRotation());
				miningLaser->SetLength(Physics::getDistance(miningLaser->GetPosition(), asteroid->GetPosition()));
				asteroid->DecreaseHealth(playerShip->GetMiningLaser()->GetExtractRate() * dt);
				asteroid->SetRadius((asteroid->GetHealth()/asteroid->GetMaxHealth()) * asteroid->GetMaxRadius());

				if (asteroid->GetRadius() < 3.5f) {
				
					asteroid->SetRadius(3.5f);

				}

				playerShip->AddHealth((miningLaser->GetExtractRate()/5.0f) * dt);

				if (playerShip->GetHealth() > playerShip->GetMaxHealth()) {

					playerShip->SetHealth(playerShip->GetMaxHealth());

				}

			}

		} 
	
	} else if (playerShip->IsMining()) {
	
		playerShip->SetMining(false);
		playerShip->GetMiningLaser()->SetLength(10);
		playerShip->GetMiningLaser()->SetRotation(playerShip->GetRotationMatrix());

	}

}