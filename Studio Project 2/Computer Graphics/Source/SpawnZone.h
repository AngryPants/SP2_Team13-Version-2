#ifndef _SPAWNZONE_H
#define _SPAWNZONE_H

#include "Vector3.h"
#include <string>

using std::string;

class SpawnZone {

private:
	//Variables
	string name;
	Vector3 position;
	float spawnRadius;
	float renderRadius;
	float despawnRadius;

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

	//Setters
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void SetSpawnRadius(float radius);
	void SetRenderRadius(float radius);
	void SetDespawnRadius(float radius);
	void SetName(string name);

};

#endif