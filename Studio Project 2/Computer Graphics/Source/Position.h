#ifndef _POSITION_H
#define _POSITION_H

struct Position {

	float x, y, z;

	Position(float x = 0, float y = 0, float z = 0) {
		Set(x, y, z);
	}

	void Set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

};

#endif