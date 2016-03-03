#include "MiningLaser.h"

/***********************************************************************************/
/*!

\brief
Default constructor for MiningLaser.

*/
/***********************************************************************************/
MiningLaser::MiningLaser()
: GameObject("Mining Laser", "OBJ//Condor//Mining_Laser.obj", "Image//Condor//Mining_Laser.tga", MaterialList::GetInstance()->material[MaterialList::PLASTIC])
{

	this->length = 0.0f;
	this->extractRate = 500.0f;
	this->zRotation = 0.0f;

}

/***********************************************************************************/
/*!

\brief
An empty destructor.

*/
/***********************************************************************************/
MiningLaser::~MiningLaser() {
}

//Functions
/***********************************************************************************/
/*!

\brief
Adds a rotation the mining laser along the z axis to create a animation.

\param zRotation
The rotation to add to the MiningLaser's z axis.

*/
/***********************************************************************************/
void MiningLaser::AddZRotation(float zRotation) {

	this->zRotation += zRotation;
	this->zRotation = (int)this->zRotation%360;

}

//Getters
/***********************************************************************************/
/*!

\brief
Gets the length of the MiningLaser.

\return
Returns the length of the MiningLaser.

*/
/***********************************************************************************/
float MiningLaser::GetLength() {

	return this->length;

}

/***********************************************************************************/
/*!

\brief
Gets the extraction rate of the MiningLaser.

\return
Returns the extraction rate of the MiningLaser.

*/
/***********************************************************************************/
float MiningLaser::GetExtractRate() {

	return this->extractRate;

}

/***********************************************************************************/
/*!

\brief
Gets the z rotation of the MiningLaser.

\return
Returns the z rotation of the MiningLaser.

*/
/***********************************************************************************/
float MiningLaser::GetZRotation() {

	return this->zRotation;

}

//Setters
/***********************************************************************************/
/*!

\brief
Sets the length of the MiningLaser.

\param length
The new length of the MiningLaser.

*/
/***********************************************************************************/
void MiningLaser::SetLength(float length) {

	if (length >= 0.0f) {
	
		this->length = length;

	}

}