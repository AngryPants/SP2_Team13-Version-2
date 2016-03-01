#include "SpawnZone.h"
#include "Spawn.h"

//Constructors
SpawnZone::SpawnZone() {

	SetName("<Zone Name>");
	SetPosition(0.0f, 0.0f, 0.0f);
	SetSpawnRadius(0.0f);
	SetActiveRadius(0.0f);
	SetDespawnRadius(0.0f);
	zoneState = ACTIVE;

}

SpawnZone::SpawnZone(string name, Vector3 position, float spawnRadius, float renderRadius, float despawnRadius) {

	SetName(name);
	SetPosition(position);
	SetSpawnRadius(spawnRadius);
	SetActiveRadius(renderRadius);
	SetDespawnRadius(despawnRadius);
	zoneState = ACTIVE;

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

float SpawnZone::GetActiveRadius() {

	return this->activeRadius;

}

float SpawnZone::GetDespawnRadius() {

	return this->despawnRadius;

}

string SpawnZone::GetName() {

	return this->name;

}

list<Asteroid>* SpawnZone::GetAsteroidList() {
	
	return &(this->asteroids);

}

list<Ship>* SpawnZone::GetEnemyList() {

	return &(this->enemies);

}

ZONE_STATE SpawnZone::GetZoneState() {

	return this->zoneState;

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

void SpawnZone::SetActiveRadius(float radius) {

	if (radius >= this->spawnRadius) {

		this->activeRadius = radius;

	} else {
	
		this->activeRadius = this->spawnRadius;

	}

}

void SpawnZone::SetDespawnRadius(float radius) {

	if (radius >= this->activeRadius) {

		this->despawnRadius = radius;

	} else {
	
		this->despawnRadius = this->activeRadius;

	}

}

void SpawnZone::SetName(string name) {

	this->name = name;

}

void SpawnZone::SetActive() {

	for (list<Asteroid>::iterator iter = asteroids.begin(); iter != asteroids.end(); ++iter) {
	
		iter->Spawn();

	}

	for (list<Ship>::iterator iter = enemies.begin(); iter != enemies.end(); ++iter) {
	
		iter->Spawn();

	}

	zoneState = ACTIVE;

}

void SpawnZone::SetInactive() {

	for (list<Asteroid>::iterator iter = asteroids.begin(); iter != asteroids.end(); ++iter) {
	
		iter->Despawn();

	}

	for (list<Ship>::iterator iter = enemies.begin(); iter != enemies.end(); ++iter) {
	
		iter->Despawn();

	}

	zoneState = INACTIVE;

}