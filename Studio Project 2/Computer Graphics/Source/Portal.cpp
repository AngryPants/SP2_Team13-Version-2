#include "Portal.h"


Portal::Portal() :WarpGate(Vector3(80, 80, 80), 150, 100, "", "Portal", "OBJ//Portal//Portal.obj", "Image//Portal//PortalText.tga", MaterialList::GetInstance()->material[MaterialList::METAL])
{
	//"WarpGate", 100, 50, "OBJ//WarpGate//WarpGate.obj", "Image//WarpGate//WarpGateText.tga", MaterialList::GetInstance()->material[MaterialList::METAL]

}

Portal::~Portal()
{

}