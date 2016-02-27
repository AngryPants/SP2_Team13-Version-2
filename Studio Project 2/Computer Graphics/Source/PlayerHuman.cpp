#include "PlayerHuman.h"

PlayerHuman::PlayerHuman(string name) : RigidBody(name, "OBJ//PlaceHolder//PlaceHolder.obj", "Image//PlaceHolder//PlaceHolder.tga", MaterialList::GetInstance()->material[MaterialList::PAPER], 60, 3) {
}

PlayerHuman::~PlayerHuman() {
}