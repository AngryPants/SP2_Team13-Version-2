#ifndef _SPAWN_H
#define _SPAWN_H
/****************************************************************************/
/*!
\file Spawn.h
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
Struct that generates the coordinates using an algorithm for each Objects in OuterSpace
*/
/****************************************************************************/
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
/******************************************************************************/
/*!
		Struct Spawn:
\brief
Generates the coordinates using an algorithm for each Objects in OuterSpace
*/
/******************************************************************************/
struct Spawn
{
public:
	
	//Constructor & Destructor
	Spawn();
	~Spawn();
	
	//Variables
	static int counter;

	//Functions
	static void SpawnObjects(Asteroid* object, float objectRadius, unsigned int numObjects, SpawnZone &spawnZone, list<Asteroid> &asteroids, int seed);
	static void SpawnObjects(Ship* object, float objectRadius, unsigned int numObjects, SpawnZone &spawnZone, list<Ship> &ship, int seed);
	static void RespawnEnemies(SpawnZone &spawnZone, int seed);
	static void CheckZone(SpawnZone &spawnZone, Vector3 playerPosition);
	static void CheckKill(SpaceObject* object, Player &player);
	static void CheckKill(Player &player);

};

#endif