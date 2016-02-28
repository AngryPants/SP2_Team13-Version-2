#include "SpawnZone.h"

//Constructors
SpawnZone::SpawnZone() {

	SetName("<Zone Name>");
	SetPosition(0.0f, 0.0f, 0.0f);
	SetSpawnRadius(0.0f);
	SetDespawnRadius(0.0f);

}

SpawnZone::SpawnZone(string name, Vector3 position, float spawnRadius, float despawnRadius) {

	SetName(name);
	SetPosition(position);
	SetSpawnRadius(spawnRadius);
	SetDespawnRadius(despawnRadius);

}

//Destructor
SpawnZone::~SpawnZone() {
}

//Getters
Vector3 SpawnZone::GetPosition() {

	return this->position;

}

float SpawnZone::GetSpawnRadius() {

	return this->spawnRadius;

}

float SpawnZone::GetDespawnRadius() {

	return this->despawnRadius;

}

string SpawnZone::GetName() {

	return this->name;

}

//Setters
void SpawnZone::SetPosition(Vector3 position) {

	this->position = position;

}

void SpawnZone::SetPosition(float x, float y, float z) {

	SetPosition(Vector3(x, y, z));

}

void SpawnZone::SetSpawnRadius(float radius) {

	if (radius >= 0.0f) {
	
		this->spawnRadius = radius;

	} else {
	
		this->spawnRadius = 0.0f;

	}

}

void SpawnZone::SetDespawnRadius(float radius) {

	if (radius >= this->spawnRadius) {

		this->despawnRadius = radius;

	} else {
	
		this->despawnRadius = this->spawnRadius;

	}

}

void SpawnZone::SetName(string name) {

	this->name = name;

}