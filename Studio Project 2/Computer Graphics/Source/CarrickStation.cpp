#include "CarrickStation.h"
/*****************************************/
/*!
\file CarrickStation.h
\author Chua Teck Lee
\par email:c_tecklee@hotmail.com
\brief
Creates a CarrickStation
*/
/*****************************************/

/*******************************************************/
/*!
\brief
constructor of carrickstation
\param
none
\return
nothing
*/
/*******************************************************/
CarrickStation::CarrickStation()
: SpaceStation("Carrick Station", 120.0f, 60.0f, "You are approaching Carrick Station.", "Docking at Carrick Station", "OBJ//Space_Station//SpaceStation.obj", "Image//Space_Station//Space_Station.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 1)
{
}
/*******************************************************/
/*!
\brief
destruction of carrickstation
\param
none
\return
nothing
*/
/*******************************************************/
CarrickStation::~CarrickStation() {
}