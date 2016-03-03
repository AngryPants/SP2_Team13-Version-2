#ifndef _COLOUR_H
#define _COLOUR_H

/****************************************************************************/
/*!
\file Colour.h
\author
\par email:
\brief

*/
/****************************************************************************/

/*****************************************/
/*!
		Struct Colour
\brief

*/
/*****************************************/

struct Colour {

	float r, g, b;

	Colour(float r = 1.0f, float g = 1.0f, float b = 1.0f) {
		Set(r, g, b);
	}

	void Set(float r, float g, float b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}

};

#endif