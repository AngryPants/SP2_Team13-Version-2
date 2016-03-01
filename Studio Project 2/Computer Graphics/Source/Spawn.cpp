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
A pointer to SpaceObject that would be pushed into the list and be rendered later
/param i
A integer value that adds into the Seeded value
/param zoneCentre
A Vector3 value that is the Coordinate of the centre of each zone
/param zoneRadius
A float value that determines how far each zone stretches
/param objectlist
A list that would have the final result pushed into
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

void Spawn::RespawnEnemies(SpawnZone &spawnZone, int seed) {

	srand(seed);

	for (list<Ship>::iterator iter = spawnZone.GetEnemyList()->begin(); iter != spawnZone.GetEnemyList()->end(); ++iter) {
	
		MS spawnStack;
		spawnStack.Rotate(GenerateRange(0, 360), 1, 0, 0);
		spawnStack.Rotate(GenerateRange(0, 360), 0, 1, 0);
		spawnStack.Rotate(GenerateRange(0, 360), 0, 0, 1);
		spawnStack.Translate(GenerateRange(spawnZone.GetPosition().x - spawnZone.GetSpawnRadius()/8.0f, spawnZone.GetPosition().x + spawnZone.GetSpawnRadius()/8.0f), GenerateRange(spawnZone.GetPosition().y - spawnZone.GetSpawnRadius()/8.0f, spawnZone.GetPosition().y + spawnZone.GetSpawnRadius()/8.0f), GenerateRange(spawnZone.GetPosition().z - spawnZone.GetSpawnRadius()/8.0f, spawnZone.GetPosition().z + spawnZone.GetSpawnRadius()/8.0f));

		iter->SetPosition(spawnStack.Top().a[12], spawnStack.Top().a[13], spawnStack.Top().a[14]);

	}

}

void Spawn::CheckKill(SpaceObject* object, Player &player) {

	if (object->IsDead() && !object->IsDisabled()) {
	
		player.GetInventory()->AddGold(object->GetRewardGold());
		player.GetShip()->AddHealth(object->GetMaxHealth()/3.0f);
		
		if (player.GetShip()->GetHealth() > player.GetShip()->GetMaxHealth()) {
		
			player.GetShip()->SetHealth(player.GetShip()->GetMaxHealth());

		}

		if (object->GetRewardItem().GetID() != 0) {
		
			player.GetInventory()->AddItem((object->GetRewardItem()), object->GetNumberOfRewardItems());

		}

		object->Disable();

	}

}

void Spawn::CheckKill(Player &player) {

	if (player.GetShip()->IsDead()) {
	
		player.SetState(DEAD);

	}
}

void Spawn::CheckZone(SpawnZone &spawnZone, Vector3 playerPosition) {

	if (spawnZone.GetZoneState() == INACTIVE && Physics::getDistance(playerPosition, spawnZone.GetPosition()) <= spawnZone.GetActiveRadius()) {
	
		spawnZone.SetActive();
		RespawnEnemies(spawnZone, (int)(playerPosition.x + playerPosition.z));

	} else if (spawnZone.GetZoneState() == ACTIVE && Physics::getDistance(playerPosition, spawnZone.GetPosition()) > spawnZone.GetDespawnRadius()) {
	
		spawnZone.SetInactive();

	}

}