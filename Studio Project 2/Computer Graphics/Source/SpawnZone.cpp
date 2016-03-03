#include "SpawnZone.h"
#include "Spawn.h"

//Constructors

/****************************************************************************/
/*!
\brief
Constructor of the Class SpawnZone
/****************************************************************************/
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

//Copy Constructor

/****************************************************************************/
/*!
\brief
Copy constructor of the Class SpawnZone
\param name
Defines the name of the Class SpawnZone
\param position
Defines the position of the Class SpawnZone
\param spawnRadius
Defines the spawnRadius of the Class SpawnZone
\param activeRadius
Defines the activeRadius of the Class SpawnZone
\param despawnRadius
Defines the despawnRadius of the Class SpawnZone
\param colour
Defines the BEACON_COLOUR of the Class SpawnZone
*/
/****************************************************************************/
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

/****************************************************************************/
/*!
\brief
Destructor of the Class SpawnZone
/****************************************************************************/
SpawnZone::~SpawnZone() {
}

//Getters

/****************************************************************************/
/*!
\brief
Getter of the value spawnRadius
\return
returns the value spawnRadius of the Class SpawnZone
/****************************************************************************/
float SpawnZone::GetSpawnRadius() {

	return this->spawnRadius;

}
/****************************************************************************/
/*!
\brief
Getter of the value activeRadius
\return
returns the value activeRadius of the Class SpawnZone
/****************************************************************************/
float SpawnZone::GetActiveRadius() {

	return this->activeRadius;

}
/****************************************************************************/
/*!
\brief
Getter of the value despawnRadius
\return
returns the value despawnRadius of the Class SpawnZone
/****************************************************************************/
float SpawnZone::GetDespawnRadius() {

	return this->despawnRadius;

}
/****************************************************************************/
/*!
\brief
Getter of the string name
\return
returns the string name of the Class SpawnZone
/****************************************************************************/
string SpawnZone::GetName() {

	return this->name;

}
/****************************************************************************/
/*!
\brief
Getter of the pointer Asteroid
\return
returns the pointer Asteroid of the Class SpawnZone
/****************************************************************************/
list<Asteroid>* SpawnZone::GetAsteroidList() {
	
	return &(this->asteroids);

}
/****************************************************************************/
/*!
\brief
Getter of the pointer Enemy
\return
returns the pointer Enemy of the Class SpawnZone
/****************************************************************************/
list<Ship>* SpawnZone::GetEnemyList() {

	return &(this->enemies);

}
/****************************************************************************/
/*!
\brief
Getter of the enum ZONE_STATE
\return
returns the enum ZONE_STATE of the Class SpawnZone
/****************************************************************************/
ZONE_STATE SpawnZone::GetZoneState() {

	return this->zoneState;

}

//Setters

/****************************************************************************/
/*!
\brief
Setter of the value spawnRadius
\param radius
Sets the value of spawnRadius of the Class SpawnZone
/****************************************************************************/
void SpawnZone::SetSpawnRadius(float radius) {

	if (radius >= 0.0f) {
	
		this->spawnRadius = radius;

	} else {
	
		this->spawnRadius = 0.0f;

	}

}
/****************************************************************************/
/*!
\brief
Setter of the value activeRadius
\param radius
Sets the value of activeRadius of the Class SpawnZone
/****************************************************************************/
void SpawnZone::SetActiveRadius(float radius) {

	if (radius >= this->spawnRadius) {

		this->activeRadius = radius;

	} else {
	
		this->activeRadius = this->spawnRadius;

	}

}
/****************************************************************************/
/*!
\brief
Setter of the value despawnRadius
\param radius
Sets the value of despawnRadius of the Class SpawnZone
/****************************************************************************/
void SpawnZone::SetDespawnRadius(float radius) {

	if (radius >= this->activeRadius) {

		this->despawnRadius = radius;

	} else {
	
		this->despawnRadius = this->activeRadius;

	}

}
/****************************************************************************/
/*!
\brief
Sets enum ZONE_STATE of the Class SpawnZone to ACTIVE
/****************************************************************************/
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
/****************************************************************************/
/*!
\brief
Sets enum ZONE_STATE of the Class SpawnZone to INACTIVE
/****************************************************************************/
void SpawnZone::SetInactive() {

	for (list<Asteroid>::iterator iter = asteroids.begin(); iter != asteroids.end(); ++iter) {
	
		iter->Despawn();

	}

	for (list<Ship>::iterator iter = enemies.begin(); iter != enemies.end(); ++iter) {
	
		iter->Despawn();

	}

	zoneState = INACTIVE;

}
/****************************************************************************/
/*!
\brief
Setter of the enum BEACON_COLOUR
\param colour
Sets the enum BEACON_COLOUR of the Class SpawnZone
/****************************************************************************/
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