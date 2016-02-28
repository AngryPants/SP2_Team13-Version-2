#include "Kernite.h"

Kernite::Kernite() : Asteroid("Kernite", 40000.0f, 1500, "Image//Asteroid//Kernite.tga", 3000.0f, 6) {
}

Kernite::~Kernite() {
}

void Kernite::Die(Player &player) {

	player.GetInventory()->AddKernite(8000);

}