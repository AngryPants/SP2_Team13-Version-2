#ifndef _MOUSEPOSITION_H
#define _MOUSEPOSITION_H
/****************************************************************************/
/*!
\file MousePosition.h
\author Lim Ngian Xin Terry
\par email: lnxterry@gmail.com
\brief
Header for MousePosition

*/
/****************************************************************************/
/******************************************************************************/
/*!
Class MousePosition:
\brief
Defines MousePosition.

*/
/******************************************************************************/
struct MousePosition {

public:
	double x;
	double y;

	/***************************/
	/*!
	
	\brief
	Default constructor for MousePosition.

	*/
	/***************************/
	MousePosition() {
		
		this->x = 0;
		this->y = 0;

	}

	/***************************/
	/*!
	
	\brief
	Constructor for MousePosition.

	\param x
	x value of MousePosition.

	\param y
	y value of MousePosition.

	*/
	/***************************/
	MousePosition(double x, double y) {
	
		this->x = x;
		this->y = y;

	}

	/***************************/
	/*!
	
	\brief
	An empty destructor

	*/
	/***************************/
	~MousePosition() {
	}

};

#endif