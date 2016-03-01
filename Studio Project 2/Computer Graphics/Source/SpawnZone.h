#ifndef _SPAWNZONE_H
#define _SPAWNZONE_H

#include "Vector3.h"
#include <string>
#include "Asteroid.h"
#include "Ship.h"

using std::string;

enum ZONE_STATE {

	ACTIVE,
	INACTIVE,

	NUM_ZONE_STATE,

};

class SpawnZone {

private:
	//Variables
	string name;
	Vector3 position;
	float spawnRadius;
	float activeRadius;
	float despawnRadius;
	list<Asteroid> asteroids;
	list<Ship> enemies;
	ZONE_STATE zoneState;

public:
	//Constructors & Destructor
	SpawnZone();
	SpawnZone(string name, Vector3 position, float spawnRadius, float activeRadius, float depawnRadius);
	~SpawnZone();

	//Getters
	Vector3 GetPosition();
	float GetSpawnRadius();
	float GetActiveRadius();
	float GetDespawnRadius();
	string GetName();
	list<Asteroid>* GetAsteroidList();
	list<Ship>* GetEnemyList();
	ZONE_STATE GetZoneState();

	//Setters
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void SetSpawnRadius(float radius);
	void SetActiveRadius(float radius);
	void SetDespawnRadius(float radius);
	void SetName(string name);
	void SetActive();
	void SetInactive();

};

#endif