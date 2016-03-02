#include "MiningLaser.h"

//Constructor
MiningLaser::MiningLaser()
: GameObject("Mining Laser", "OBJ//Condor//Mining_Laser.obj", "Image//Condor//Mining_Laser.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	this->length = 0.0f;
	this->extractRate = 500.0f;
	this->zRotation = 0.0f;

}

//Destructor
MiningLaser::~MiningLaser() {
}

//Functions
void MiningLaser::AddZRotation(float zRotation) {

	this->zRotation += zRotation;
	this->zRotation = (int)this->zRotation%360;

}

//Getters
float MiningLaser::GetLength() {

	return this->length;

}

float MiningLaser::GetExtractRate() {

	return this->extractRate;

}

float MiningLaser::GetZRotation() {

	return this->zRotation;

}

//Setters
void MiningLaser::SetLength(float length) {

	if (length >= 0.0f) {
	
		this->length = length;

	}

}