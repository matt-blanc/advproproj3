#pragma once
#include "Ship.h"
class Battleship : public Ship
{
public:
	Battleship(); //Default and only constructor
	virtual void hit(); //virtual "hit" function
	virtual int getHealth(); //virtual function to get health (used for checking if ship is sunk)
	virtual int getLength(); //virtual function to get length (used for size checking)
	virtual int getX(); //virtual function to get starting x coordinate
	virtual void setX(int); //virtual function to set starting x coordinate
	virtual int getY(); //virtual function to get starting y coordinate
	virtual void setY(int); //virtual function to set starting y coordinate
	virtual int getHorizVert(); //virtual function to get starting orientation
};