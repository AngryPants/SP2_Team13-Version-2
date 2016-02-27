#include "Light.h"

Light::Light() {

	position.Set(5.0f, 5.0f, 5.0f);
	colour.Set(1.0f, 1.0f, 1.0f);
	power = 1.0f;
	kC = kL = kQ = 0.0f;
	type = LIGHT_SPOT;

}