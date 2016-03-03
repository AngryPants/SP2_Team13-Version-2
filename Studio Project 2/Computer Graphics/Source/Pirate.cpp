#include "Pirate.h"
/****************************************************************************/
/*!
\brief
Constructor of the Class Pirate
*/
/****************************************************************************/
Pirate::Pirate() : 
Ship("Pirate", 2, 10.0f, 3000.0f, "OBJ//Enemies//Pirate.obj", "Image//Enemies//Pirate.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 4000.0f, 30.0f, 5, 15.0f, RED)
{

	SetRewardGold(6000);

}
/****************************************************************************/
/*!
\brief
Destructor of the Class Pirate
*/
/****************************************************************************/
Pirate::~Pirate() {
}