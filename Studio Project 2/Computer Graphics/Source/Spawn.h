#ifndef _SPAWN_H
#define _SPAWN_H

#include "Veldspar.h"
#include "Omber.h"
#include "Kernite.h"
#include "Drone.h"
#include "Pirate.h"
#include "Alien.h"
#include "PlayerShip.h"

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
	static void SpawnObjects(SpaceObject* object, int i, Vector3 zoneCentre, float zoneRadius, list<SpaceObject*> &objectList);

};

#endif