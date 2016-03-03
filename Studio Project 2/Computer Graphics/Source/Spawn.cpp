/****************************************************************************/
/*!
\file Spawn.cpp
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
CPP file for Spawn
*/
/****************************************************************************/
#include "Spawn.h"

int Spawn::counter = 0; //A counter that changes the seed value everytime it runs to make the values more random

/****************************************************************************/
/*!
\brief
Constructor of the struct Spawn
*/
/****************************************************************************/
Spawn::Spawn()
{
}

/****************************************************************************/
/*!
\brief
Destructor of the struct Spawn
*/
/****************************************************************************/
Spawn::~Spawn()
{
}

/****************************************************************************/
/*!
\brief
Seeds a value then generates a coordinate for Objects in space to have within its zone
\param object
A pointer to Asteroid that would be pushed into the list and be rendered later
/param objectRadius
A float value that defines the radius of the object
/param numObjects
An unsigned integer that defines the number of times the object would be pushed into the list
/param &spawnZone
A reference to the Class SpawnZone
/param &asteroids
A reference to the list<Asteroid>
/param seed
A integer value that is to be seeded
*/
/****************************************************************************/
void Spawn::SpawnObjects(Asteroid* object, float objectRadius, unsigned int numObjects, SpawnZone &spawnZone, list<Asteroid> &asteroids, int seed) {

	if (objectRadius > spawnZone.GetSpawnRadius()) {
	
		std::cout << "The spawn radius is to small. Unable to spawn " + object->GetName() + "." << std::endl;
		return;

	}

	unsigned int totalTimesFailed = 0;
	srand(seed);
	list<Asteroid>::iterator startPoint;

	if (asteroids.begin() != asteroids.end()) {
	
		startPoint = asteroids.end();
		--startPoint;

	} else {
	
		startPoint = asteroids.begin();

	}

	for (unsigned int i = 0; i < numObjects && totalTimesFailed <= 5; ++i) {

		unsigned int timesFailed = 0;
		bool regenerate = true;

		while (timesFailed < 20 && regenerate) {
		
			MS spawnStack;
			spawnStack.Translate(spawnZone.GetPosition().x, spawnZone.GetPosition().y, spawnZone.GetPosition().z);
			spawnStack.Rotate(GenerateRange(0, 360), 1, 0, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 1, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 0, 1);
			spawnStack.Translate(GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()));

			object->SetPosition(spawnStack.Top().a[12], spawnStack.Top().a[13], spawnStack.Top().a[14]);

			for (list<Asteroid>::iterator iter = startPoint;; ++iter) {
			
				if (iter == asteroids.end()) {
				
					Asteroid newAsteroid = *object;
					asteroids.push_back(newAsteroid);
					regenerate = false;

					if (startPoint == asteroids.end()) {
					
						--startPoint;

					}

					break;

				}

				if (Physics::getDistance(object->GetPosition(), iter->GetPosition()) < objectRadius * 2 + 1.0f) {
				
					++timesFailed;
					break;

				}

			}

		}

		if (timesFailed >= 20) {
		
			++totalTimesFailed;

		}

	}

	if (totalTimesFailed >= 5) {
	
		std::cout << "Unable to spawn all " + object->GetName() + ". There may not be enough space." << std::endl;

	}

	delete object;

}
/****************************************************************************/
/*!
\brief
Seeds a value then generates a coordinate for Objects in space to have within its zone
\param object
A pointer to Ship that would be pushed into the list and be rendered later
/param objectRadius
A float value that defines the radius of the object
/param numObjects
An unsigned integer that defines the number of times the object would be pushed into the list
/param &spawnZone
A reference to the Class SpawnZone
/param &ship
A reference to the list<Ship>
/param seed
A integer value that is to be seeded
*/
/****************************************************************************/
void Spawn::SpawnObjects(Ship* object, float objectRadius, unsigned int numObjects, SpawnZone &spawnZone, list<Ship> &ship, int seed) {

	if (objectRadius > spawnZone.GetSpawnRadius()) {

		std::cout << "The spawn radius is to small. Unable to spawn " + object->GetName() + "." << std::endl;
		return;

	}

	unsigned int totalTimesFailed = 0;
	srand(seed);
	list<Ship>::iterator startPoint;

	if (ship.begin() != ship.end()) {

		startPoint = ship.end();
		--startPoint;

	}
	else {

		startPoint = ship.begin();

	}

	for (unsigned int i = 0; i < numObjects && totalTimesFailed <= 5; ++i) {

		unsigned int timesFailed = 0;
		bool regenerate = true;

		while (timesFailed < 20 && regenerate) {

			MS spawnStack;
			spawnStack.Translate(spawnZone.GetPosition().x, spawnZone.GetPosition().y, spawnZone.GetPosition().z);
			spawnStack.Rotate(GenerateRange(0, 360), 1, 0, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 1, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 0, 1);
			spawnStack.Translate(GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + object->GetRadius(), spawnZone.GetSpawnRadius() - object->GetRadius()));

			object->SetPosition(spawnStack.Top().a[12], spawnStack.Top().a[13], spawnStack.Top().a[14]);

			for (list<Ship>::iterator iter = startPoint;; ++iter) {

				if (iter == ship.end()) {

					Ship newShip = *object;
					ship.push_back(newShip);
					regenerate = false;

					if (startPoint == ship.end()) {

						--startPoint;

					}

					break;

				}

				if (Physics::getDistance(object->GetPosition(), iter->GetPosition()) < objectRadius * 2 + 1.0f) {

					++timesFailed;
					break;

				}

			}

		}

		if (timesFailed >= 20) {

			++totalTimesFailed;

		}

	}

	if (totalTimesFailed >= 5) {

		std::cout << "Unable to spawn all " + object->GetName() + ". There may not be enough space." << std::endl;

	}

	delete object;

}
/****************************************************************************/
/*!
\brief
Respawns the Enemy into the SpawnZone
/param &spawnZone
A reference to the Class SpawnZone
/param seed
A integer value that is to be seeded
*/
/****************************************************************************/
void Spawn::RespawnEnemies(SpawnZone &spawnZone, int seed) {

	srand(seed);

	for (list<Ship>::iterator iter = spawnZone.GetEnemyList()->begin(); iter != spawnZone.GetEnemyList()->end(); ++iter) {
	
		MS spawnStack;
		spawnStack.Translate(spawnZone.GetPosition().x, spawnZone.GetPosition().y, spawnZone.GetPosition().z);
			spawnStack.Rotate(GenerateRange(0, 360), 1, 0, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 1, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 0, 1);
			spawnStack.Translate(GenerateRange(-spawnZone.GetSpawnRadius() + iter->GetRadius(), spawnZone.GetSpawnRadius() - iter->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + iter->GetRadius(), spawnZone.GetSpawnRadius() - iter->GetRadius()), GenerateRange(-spawnZone.GetSpawnRadius() + iter->GetRadius(), spawnZone.GetSpawnRadius() - iter->GetRadius()));

		iter->SetPosition(spawnStack.Top().a[12], spawnStack.Top().a[13], spawnStack.Top().a[14]);

	}

}
/****************************************************************************/
/*!
\brief
Checks if the player has killed an Enemy
\param object
A pointer to he Class SpaceObject
/param &player
A reference to the Class Player
*/
/****************************************************************************/
void Spawn::CheckKill(SpaceObject* object, Player &player) {

	if (object->IsDead() && !object->IsDisabled()) {
	
		player.GetInventory()->AddGold(object->GetRewardGold());

		if (object->GetRewardItem().GetID() != 0) {
		
			player.GetInventory()->AddItem((object->GetRewardItem()), object->GetNumberOfRewardItems());

		}

		object->Disable();

	}

}
/****************************************************************************/
/*!
\brief
Checks if the player is killed by an Enemy
/param &player
A reference to the Class Player
*/
/****************************************************************************/
void Spawn::CheckKill(Player &player) {

	if (player.GetShip()->IsDead()) {
	
		player.SetState(DEAD);

	}
}
/****************************************************************************/
/*!
\brief
Checks if the player has killed an Enemy
\param &spawnZone
A pointer to the Class SpawnZone
/param playerPosition
A vector that is Position of the Class Player
*/
/****************************************************************************/
void Spawn::CheckZone(SpawnZone &spawnZone, Vector3 playerPosition) {

	if (spawnZone.GetZoneState() == INACTIVE && Physics::getDistance(playerPosition, spawnZone.GetPosition()) <= spawnZone.GetActiveRadius()) {
	
		spawnZone.SetActive();
		RespawnEnemies(spawnZone, (int)(playerPosition.x + playerPosition.z));

	} else if (spawnZone.GetZoneState() == ACTIVE && Physics::getDistance(playerPosition, spawnZone.GetPosition()) > spawnZone.GetDespawnRadius()) {
	
		spawnZone.SetInactive();

	}

}