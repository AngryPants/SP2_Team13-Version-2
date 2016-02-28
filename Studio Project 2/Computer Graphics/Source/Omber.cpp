#include "Omber.h"

Omber::Omber() : Asteroid("Omber", 40000.0f, 500, "Image//Asteroid//Omber.tga", 6000.0f, 5) {
}

Omber::~Omber() {
}

void Omber::Die(Player &player) {

	player.GetInventory()->AddOmber(2000);

}