#include "SpawnZone.h"
#include "Spawn.h"

//Constructors
SpawnZone::SpawnZone() {

	SetName("<Zone Name>");
	SetPosition(0.0f, 0.0f, 0.0f);
	SetSpawnRadius(0.0f);
	SetRenderRadius(0.0f);
	SetDespawnRadius(0.0f);
	SetRenderable(false);

}

SpawnZone::SpawnZone(string name, Vector3 position, float spawnRadius, float renderRadius, float despawnRadius) {

	SetName(name);
	SetPosition(position);
	SetSpawnRadius(spawnRadius);
	SetRenderRadius(renderRadius);
	SetDespawnRadius(despawnRadius);
	SetRenderable(false);

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

float SpawnZone::GetRenderRadius() {

	return this->renderRadius;

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

bool SpawnZone::GetRenderable() {

	return this->renderable;

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

void SpawnZone::SetRenderRadius(float radius) {

	if (radius >= this->spawnRadius) {

		this->renderRadius = radius;

	} else {
	
		this->renderRadius = this->spawnRadius;

	}

}

void SpawnZone::SetDespawnRadius(float radius) {

	if (radius >= this->renderRadius) {

		this->despawnRadius = radius;

	} else {
	
		this->despawnRadius = this->renderRadius;

	}

}

void SpawnZone::SetName(string name) {

	this->name = name;

}

void SpawnZone::SetAsteroidList(list<Asteroid> asteroidList) {

	this->asteroids = asteroidList;

}

void SpawnZone::SetEnemyList(list<Ship> enemyList) {

	this->enemies = enemyList;

}

void SpawnZone::SetRenderable(bool inArea) {

	this->renderable = inArea;

}

void SpawnZone::GenerateAsteroidCoordinates(SpawnZone &spawnZone, Asteroid* object) {

	list<Asteroid> generatedList;
	/*Asteroid newAsteroid = *object;*/
	Spawn::SpawnObjects(object, object->GetRadius(), 50, spawnZone, generatedList, 17);

	SetAsteroidList(generatedList);

}

void SpawnZone::GenerateShipCoordinates(SpawnZone &spawnZone, Ship* object) {

	list<Ship> generatedList;
	/*Asteroid newAsteroid = *object;*/
	Spawn::SpawnObjects(object, object->GetRadius(), 50, spawnZone, generatedList, 17);

	SetEnemyList(generatedList);

}

void SpawnZone::CheckSpawn(SpawnZone &spawnZone, Vector3 &playerPos) {

	if (Physics::getDistance(spawnZone.GetPosition(), playerPos) >= spawnZone.GetDespawnRadius()) {
		
		spawnZone.SetRenderable(false);

	}
	else if (Physics::getDistance(spawnZone.GetPosition(), playerPos) <= spawnZone.GetRenderRadius()) {

		spawnZone.SetRenderable(true);

	}


}