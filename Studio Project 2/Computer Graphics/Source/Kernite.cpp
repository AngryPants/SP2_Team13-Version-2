#include "Kernite.h"

Kernite::Kernite() : Asteroid("Kernite", 40000.0f, 1500, "Image//Asteroid//Kernite.tga", 3000.0f, 6) {

	SetRewardItem(Item("Tin", 20, 3), 3000);

}

Kernite::~Kernite() {
}