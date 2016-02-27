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
void Spawn::SpawnObjects(SpaceObject* object, int i , Vector3 zoneCentre, float zoneRadius, list<SpaceObject*> &objectList) {

	float sValue = time(NULL) * (i + counter) + 1;

	SpaceObject* listObject;

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

}