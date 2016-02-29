#include "CarrickStation.h"

CarrickStation::CarrickStation()
: SpaceStation("Carrick Station", 120.0f, 60.0f, "You are approaching Carrick Station.", "Docking at Carrick Station", "OBJ//Space_Station//SpaceStation.obj", "Image//Space_Station//Space_Station.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 1)
{
}

CarrickStation::~CarrickStation() {
}