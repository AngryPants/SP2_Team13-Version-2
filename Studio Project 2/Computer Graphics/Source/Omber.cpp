#include "Omber.h"

Omber::Omber() : Asteroid("Omber", 4000000.0f, "Image//Asteroid//Omber.tga", 6000.0f, 5) {

	SetRewardItem(Item("Steel", 8, 2), 6000);

}

Omber::~Omber() {
}