#include "Kernite.h"
/****************************************************************************/
/*!
\brief
Constructor of the Class Kernite
*/
/****************************************************************************/
Kernite::Kernite() : Asteroid("Kernite", 4000000.0f, "Image//Asteroid//Kernite.tga", 3000.0f, 6) {

	SetRewardItem(Item("Tin", 20, 3), 3000);

}
/****************************************************************************/
/*!
\brief
Destructor of the Class Kernite
*/
/****************************************************************************/
Kernite::~Kernite() {
}