#include "CarrickStation.h"

CarrickStation::CarrickStation()
: SpaceStation(120, 80, "", "OuterSpaceStation", "OBJ//Space_Station//SpaceStation.obj", "Image//Space_Station//Space_Station.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 1) {
}

CarrickStation::~CarrickStation() {
}