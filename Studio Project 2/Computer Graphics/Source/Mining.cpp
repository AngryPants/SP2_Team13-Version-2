#include "Mining.h"

void Mining::Mine(PlayerShip* playerShip, Asteroid* asteroid, double &dt) {

	if (Application::IsKeyPressed(VK_RBUTTON)) {

		playerShip->SetMining(true);

		if (Physics::getDistance(playerShip->GetPosition(), asteroid->GetPosition()) <= (350.0f + playerShip->GetRadius() + asteroid->GetRadius())) {

			if (Collision::CollisionCheck(playerShip->GetPosition(), playerShip->GetForwardVector(), 350.0f + playerShip->GetRadius() + asteroid->GetRadius(), asteroid)) {
			
				MiningLaser* miningLaser = playerShip->GetMiningLaser();
				miningLaser->AddZRotation(360 * dt);
				miningLaser->Rotate(0, 0, miningLaser->GetZRotation());
				miningLaser->SetLength(Physics::getDistance(miningLaser->GetPosition(), asteroid->GetPosition()));
				asteroid->DecreaseHealth(playerShip->GetMiningLaser()->GetExtractRate() * dt);
				asteroid->SetRadius((asteroid->GetHealth()/asteroid->GetMaxHealth()) * asteroid->GetMaxRadius());

				if (asteroid->GetRadius() < 3.5f) {
				
					asteroid->SetRadius(3.5f);

				}

			}

		} 
	
	} else if (playerShip->IsMining()) {
	
		playerShip->SetMining(false);
		playerShip->GetMiningLaser()->SetLength(10);
		playerShip->GetMiningLaser()->SetRotation(playerShip->GetRotationMatrix());

	}

}