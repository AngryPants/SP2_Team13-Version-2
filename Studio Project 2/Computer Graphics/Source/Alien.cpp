#include "Alien.h"

/*******************************************************************************/
/*!

/brief
A default constructor for the alien ship.

*/
/*******************************************************************************/
Alien::Alien() : 
Ship("Alien", 2, 10.0f, 9000.0f, "OBJ//Enemies//Alien.obj", "Image//Enemies//Alien.tga", MaterialList::GetInstance()->material[MaterialList::METAL], 3000.0f, 30.0f, 2, 60.0f, BLUE)
{

	SetRewardGold(6000);

}

/*******************************************************************************/
/*!

/brief
An empty destructor.

*/
/*******************************************************************************/
Alien::~Alien() {
}