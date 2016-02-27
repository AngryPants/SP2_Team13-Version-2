#ifndef _MOUSEPOSITION_H
#define _MOUSEPOSITION_H

struct MousePosition {

public:
	double x;
	double y;

	//Constructors & Destructor
	MousePosition() {
		
		this->x = 0;
		this->y = 0;

	}

	MousePosition(double x, double y) {
	
		this->x = x;
		this->y = y;

	}

	~MousePosition() {
	}

};

#endif