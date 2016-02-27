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
void Spawn::SpawnObjects(Ship* object, int i , Vector3 zoneCentre, float zoneRadius, list<Ship*> &objectList) {

	float sValue = time(NULL) * (i + counter) + 1;

	Ship* listObject;

	listObject = object;
	srand(sValue);

	int xValue, yValue, zValue;
	while (Physics::getDistance(zoneCentre, listObject->GetPosition()) > zoneRadius);
	{
		srand(sValue);
		xValue = sValue = rand() % 1900 - 950 + (zoneCentre.x);
		srand(sValue);
		yValue = sValue = rand() % 1900 - 950 + (zoneCentre.y);
		srand(sValue);
		zValue = sValue = rand() % 1900 - 950 + (zoneCentre.z);

		counter += 1;
		listObject->SetPosition(xValue,yValue,zValue);
	}
	counter++;
	objectList.push_back(listObject);
	cout << "enermyship" << std::endl;

}

void Spawn::SpawnObjects(Asteroid* object, float objectRadius, unsigned int numObjects, SpawnZone spawnZone, list<Asteroid> &asteroids, int seed) {

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
			spawnStack.Rotate(GenerateRange(0, 360), 1, 0, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 1, 0);
			spawnStack.Rotate(GenerateRange(0, 360), 0, 0, 1);
			spawnStack.Translate(GenerateRange(spawnZone.GetPosition().x - spawnZone.GetSpawnRadius(), spawnZone.GetPosition().x + spawnZone.GetSpawnRadius()), GenerateRange(spawnZone.GetPosition().y - spawnZone.GetSpawnRadius(), spawnZone.GetPosition().y + spawnZone.GetSpawnRadius()), GenerateRange(spawnZone.GetPosition().z - spawnZone.GetSpawnRadius(), spawnZone.GetPosition().z + spawnZone.GetSpawnRadius()));
		
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

				if (Physics::getDistance(object->GetPosition(), iter->GetPosition()) < objectRadius * 2) {
				
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

void Spawn::SpawnObjects(Asteroid* object, int i, Vector3 zoneCentre, float zoneRadius, list<Asteroid*> &objectList) {

	float sValue = time(NULL) * (i + counter) + 1;

	Asteroid* listObject;

	listObject = object;
	srand(sValue);

	int xValue, yValue, zValue;
	while (Physics::getDistance(zoneCentre, listObject->GetPosition()) > zoneRadius);
	{
		srand(sValue);
		xValue = sValue = rand() % 1900 - 950 + (zoneCentre.x);
		srand(sValue);
		yValue = sValue = rand() % 1900 - 950 + (zoneCentre.y);
		srand(sValue);
		zValue = sValue = rand() % 1900 - 950 + (zoneCentre.z);

		counter += 1;
		listObject->SetPosition(xValue, yValue, zValue);
	}
	counter++;
	objectList.push_back(listObject);

	cout << "Asteroid" << std::endl;
}

void Spawn::UpdateObjects(Vector3 playerPos, Vector3 &zoneCenterValue)
{
	if (playerPos.x > 50) //(+, , )
	{
		if (playerPos.y > 50) //(+,+, )
		{
			if (playerPos.z > 50) //(+,+,+)
			{
				//HighEmptyZone
				zoneCenterValue = Vector3(1025, 1025, 1025);

			}
			else if (playerPos.z < -50) //(+,+,-)
			{
				//OmberZone
				zoneCenterValue = Vector3(1025, 1025, -1025);
			}
		}
		else if (playerPos.y < -50) //(+,-, )
		{

			if (playerPos.z > 50) //(+,-,+)
			{
				//LowEmptyZone
				zoneCenterValue = Vector3(1025, -1025, 1025);
			}
			else if (playerPos.z < -50) //(+,-,-)
			{
				//PirateZone
				zoneCenterValue = Vector3(1025, -1025, -1025);
			}
		}
	}
	else if (playerPos.x < -50) //(-, , )
	{
		if (playerPos.y > 50) //(-,+, )
		{
			if (playerPos.z > 50) //(-,+,+)
			{
				//VeldsparZone
				zoneCenterValue = Vector3(-1025, 1025, 1025);
			}
			else if (playerPos.z < -50) //(-,+,-)
			{
				//KerniteZone
				zoneCenterValue = Vector3(-1025, 1025, -1025);
			}
		}
		else if (playerPos.y < -50) //(-,-, )
		{

			if (playerPos.z > 50) //(-,-,+)
			{
				//DroneZone
				zoneCenterValue = Vector3(-1025, -1025, 1025);
			}
			else if (playerPos.z < -50) //(-,-,-)
			{
				//AlienZone
				zoneCenterValue = Vector3(-1025, -1025, -1025);
			}
		}
	}
}