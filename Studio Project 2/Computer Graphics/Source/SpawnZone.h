#ifndef _SPAWNZONE_H
#define _SPAWNZONE_H

#include "Vector3.h"

class SpawnZone {

private:
	//Variables
	Vector3 position;
	float spawnRadius;
	float despawnRadius;

public:
	//Constructors & Destructor
	SpawnZone();
	SpawnZone(Vector3 position, float spawnRadius, float depawnRadius);
	~SpawnZone();

	//Getters
	Vector3 GetPosition();
	float GetSpawnRadius();
	float GetDespawnRadius();

	//Setters
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void SetSpawnRadius(float radius);
	void SetDespawnRadius(float radius);

};

#endif