#include "Omber.h"

Omber::Omber() : Asteroid("Omber", 40000.0f, 500, "Image//Asteroid//Omber.tga", 6000.0f, 5) {

	SetRewardItem(Item("Steel", 8), 6000);

}

Omber::~Omber() {
}