#include "Veldspar.h"

Veldspar::Veldspar() : Asteroid("Veldspar", 40000.0f, 200, "Image//Asteroid//Veldspar.tga", 9000.0f, 4) {

	SetRewardItem(Item("Copper", 3), 8000);

}

Veldspar::~Veldspar() {
}