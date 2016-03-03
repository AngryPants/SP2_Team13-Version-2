#include "SpawnZone.h"
#include "Spawn.h"

//Constructors
SpawnZone::SpawnZone()
: GameObject("<Spawn Zone Name>", "OBJ//ZoneBeacon//Beacon.obj", "Image//PlaceHolder//PlaceHolder.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	SetPosition(0.0f, 0.0f, 0.0f);
	SetSpawnRadius(0.1f);
	SetActiveRadius(0.1f);
	SetDespawnRadius(0.1f);
	mesh = MeshBuilder::GenerateOBJ("Beacon", "OBJ//ZoneBeacon//Beacon.obj");
	SetBeaconColour(RED_BEACON);
	zoneState = ACTIVE;

}

SpawnZone::SpawnZone(string name, Vector3 position, float spawnRadius, float activeRadius, float despawnRadius, BEACON_COLOUR colour) 
: GameObject(name, "OBJ//ZoneBeacon//Beacon.obj", "Image//PlaceHolder//PlaceHolder.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	SetPosition(position);
	SetSpawnRadius(spawnRadius);
	SetActiveRadius(activeRadius);
	SetDespawnRadius(despawnRadius);
	mesh = MeshBuilder::GenerateOBJ("Beacon", "OBJ//ZoneBeacon//Beacon.obj");
	SetBeaconColour(colour);
	zoneState = ACTIVE;

}

//Destructor
SpawnZone::~SpawnZone() {
}

//Getters
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

void SpawnZone::SetActive() {

	for (list<Asteroid>::iterator iter = asteroids.begin(); iter != asteroids.end(); ++iter) {
	
		iter->Spawn();
		iter->SetRadius(iter->GetMaxRadius());

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

void SpawnZone::SetBeaconColour(BEACON_COLOUR colour) {
	
	switch (colour) {
	
		case YELLOW_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//YellowBeacon.tga"); break;
	
		case BLUE_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//BlueBeacon.tga"); break;
	
		case BROWN_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//BrownBeacon.tga"); break;

		case TURQUOISE_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//TurquoiseBeacon.tga"); break;

		case RED_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//RedBeacon.tga"); break;

		case GREEN_BEACON:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//GreenBeacon.tga"); break;
	
		default:
			mesh->textureID = LoadTGA("Image//ZoneBeacon//BlueBeacon.tga"); break;
				
	}

}