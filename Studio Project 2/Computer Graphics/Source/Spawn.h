#ifndef _SPAWN_H
#define _SPAWN_H

#include "Veldspar.h"
#include "Omber.h"
#include "Kernite.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "Player.h"
#include "Ship.h"
#include "SpawnZone.h"
#include "GenerateRange.h"

/****************************************************************************/
/*!
\file Spawn.h
\author 
\brief
Struct that generates the coordinates using an algorithm for each Objects in Space
*/
/****************************************************************************/

struct Spawn
{
public:
	
	//Constructor & Destructor
	Spawn();
	~Spawn();
	
	//Variables
	static int counter;

	//Functions
	static void SpawnObjects(Ship* object, int i, Vector3 zoneCentre, float zoneRadius, list<Ship*> &objectList);
	static void SpawnObjects(Asteroid* object, int i, Vector3 zoneCentre, float zoneRadius, list<Asteroid*> &objectList);
	static void UpdateObjects(Vector3 playerPos, Vector3 &zoneCenterValue);

	static void SpawnObjects(Asteroid* object, float objectRadius, unsigned int numObjects, SpawnZone spawnZone, list<Asteroid> &asteroids, int seed);
	static void EnableObject(SpawnZone &spawnZone, GameObject* object, Vector3 playerPosition);
	static void DisableObject(SpawnZone &spawnZone, GameObject* object, Vector3 playerPosition);

	static void CheckKill(SpaceObject* object, Player &player);
	static void CheckKill(Player &player);

};

#endif