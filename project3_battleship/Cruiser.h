<<<<<<< HEAD
#include "stdafx.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Battleship.h"
#include "Ship.h"

/*class Cruiser : public Ship
{
public: 
	Cruiser();

}; */
=======
#pragma once
#include "Ship.h"
class Cruiser : public Ship
{

protected:
	int health, length, startX, startY, horizVert; //health and length are equal, the starting location x/y and starting orientation
public:
	Cruiser(); //Default and only constructor
	virtual void hit(); //virtual "hit" function
	virtual int getHealth(); //virtual function to get health (used for checking if ship is sunk)
	virtual int getLength(); //virtual function to get length (used for size checking)
	virtual int getX(); //virtual function to get starting x coordinate
	virtual void setX(int); //virtual function to set starting x coordinate
	virtual int getY(); //virtual function to get starting y coordinate
	virtual void setY(int); //virtual function to set starting y coordinate
	virtual int getHorizVert(); //virtual function to get starting orientation
};
>>>>>>> b4fe1d14f4331307ee9dbe3d64a5375f809b52ec
