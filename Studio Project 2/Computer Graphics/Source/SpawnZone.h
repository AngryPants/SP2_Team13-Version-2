#ifndef _SPAWNZONE_H
#define _SPAWNZONE_H

#include "Vector3.h"
#include <string>
#include "Asteroid.h"
#include "Ship.h"

using std::string;

class SpawnZone {

private:
	//Variables
	string name;
	Vector3 position;
	float spawnRadius;
	float renderRadius;
	float despawnRadius;
	list<Asteroid> asteroids;
	list<Ship> enemies;
	bool renderable;

public:
	//Constructors & Destructor
	SpawnZone();
	SpawnZone(string name, Vector3 position, float spawnRadius, float renderRadius, float depawnRadius);
	~SpawnZone();

	//Getters
	Vector3 GetPosition();
	float GetSpawnRadius();
	float GetRenderRadius();
	float GetDespawnRadius();
	string GetName();
	list<Asteroid>* GetAsteroidList();
	list<Ship>* GetEnemyList();
	bool GetRenderable();

	//Setters
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void SetSpawnRadius(float radius);
	void SetRenderRadius(float radius);
	void SetDespawnRadius(float radius);
	void SetName(string name);
	void SetAsteroidList(list<Asteroid> asteroidList);
	void SetEnemyList(list<Ship> enemyList);
	void SetRenderable(bool inArea);

	void GenerateAsteroidCoordinates(SpawnZone &spawnZone, Asteroid* object);
	void GenerateShipCoordinates(SpawnZone &spawnZone, Ship* object);

	//
	static void CheckSpawn(SpawnZone &spawnZone, Vector3 &playerPos);
};

#endif