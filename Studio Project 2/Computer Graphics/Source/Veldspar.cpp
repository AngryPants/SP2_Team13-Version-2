/****************************************************************************/
/*!
\file Veldspar.cpp
\author Tan Teck Ling
\par email: teckling1998@gmail.com
\brief
CPP file for Veldspar

*/
/****************************************************************************/

#include "Veldspar.h"

/****************************************************************************/
/*!
\brief
Constructor of the Class Veldspar
*/
/****************************************************************************/
Veldspar::Veldspar() : Asteroid("Veldspar", 4000000.0f, "Image//Asteroid//Veldspar.tga", 9000.0f, 4) {

	SetRewardItem(Item("Copper", 3, 1), 8000);

}
/****************************************************************************/
/*!
\brief
Destructor of the Class Veldspar
*/
/****************************************************************************/
Veldspar::~Veldspar() {
}