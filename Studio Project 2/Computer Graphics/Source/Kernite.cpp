/****************************************************************************/
/*!
\file Kernite.cpp
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
CPP file for Kernite
*/
/****************************************************************************/
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