#include "MaterialList.h"

MaterialList::MaterialList() {

	material[PLASTIC].kAmbient.Set(0.25f, 0.25f, 0.25f);
	material[PLASTIC].kDiffuse.Set(0.7f, 0.7f, 0.7f);
	material[PLASTIC].kSpecular.Set(0.8f, 0.8f, 0.8f);
	material[PLASTIC].kShininess = 0.7f;

	material[METAL].kAmbient.Set(0.25f, 0.25f, 0.25f);
	material[METAL].kDiffuse.Set(0.8f, 0.8f, 0.8f);
	material[METAL].kSpecular.Set(0.02f, 0.02f, 0.02f);
	material[METAL].kShininess = 0.05f;

	material[PAPER].kAmbient.Set(0.25f, 0.25f, 0.25f);
	material[PAPER].kDiffuse.Set(0.7f, 0.7f, 0.7f);
	material[PAPER].kSpecular.Set(0.1f, 0.1f, 0.1f);
	material[PAPER].kShininess = 0.2f;

	material[SAND].kAmbient.Set(0.25f, 0.25f, 0.25f);
	material[SAND].kDiffuse.Set(1.0f, 1.0f, 1.0f);
	material[SAND].kSpecular.Set(0.0f, 0.0f, 0.0f);
	material[SAND].kShininess = 0.01f;

	material[CEMENT].kAmbient.Set(0.25f, 0.25f, 0.25f);
	material[CEMENT].kDiffuse.Set(0.7f, 0.7f, 0.7f);
	material[CEMENT].kSpecular.Set(0.01f, 0.01f, 0.01f);
	material[CEMENT].kShininess = 0.01f;

}

MaterialList::~MaterialList() {
}

MaterialList* MaterialList::GetInstance() {

	static MaterialList materialList;

	return &materialList;

}