#ifndef _SPAWNZONE_H
#define _SPAWNZONE_H
/****************************************************************************/
/*!
\file SpawnZone.h
\author
\par email:
\brief

*/
/****************************************************************************/
#include "Vector3.h"
#include <string>
#include "Asteroid.h"
#include "Ship.h"

using std::string;
/******************************************************************************/
/*!
		Class SpawnZone:
\brief
*/
/******************************************************************************/
enum ZONE_STATE {

	ACTIVE,
	INACTIVE,

	NUM_ZONE_STATE,

};

enum BEACON_COLOUR {

	BLUE_BEACON = 0,
	RED_BEACON,
	TURQUOISE_BEACON,
	BROWN_BEACON,
	GREEN_BEACON,
	YELLOW_BEACON,

	NUM_BEACON_COLOUR,

};

class SpawnZone : public GameObject {

private:
	//Variables
	float spawnRadius;
	float activeRadius;
	float despawnRadius;
	list<Asteroid> asteroids;
	list<Ship> enemies;
	ZONE_STATE zoneState;

public:
	//Constructors & Destructor
	SpawnZone();
	SpawnZone(string name, Vector3 position, float spawnRadius, float activeRadius, float despawnRadius, BEACON_COLOUR colour);
	~SpawnZone();

	//Getters
	float GetSpawnRadius();
	float GetActiveRadius();
	float GetDespawnRadius();
	string GetName();
	list<Asteroid>* GetAsteroidList();
	list<Ship>* GetEnemyList();
	ZONE_STATE GetZoneState();

	//Setters
	void SetSpawnRadius(float radius);
	void SetActiveRadius(float radius);
	void SetDespawnRadius(float radius);
	void SetBeaconColour(BEACON_COLOUR colour);
	void SetBeaconMesh(Mesh *OBJ);
	void SetActive();
	void SetInactive();

};

#endif