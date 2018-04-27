

#pragma once
#include "stdafx.h"
#include <iostream>
#ifndef SHIP_H
#define SHIP_H
using namespace std;

//abstract class for all ships (ie. batteship/cruiser/destroyer)
class Ship
{
protected:
	int health, length, startX, startY, horizVert; //health and length are equal, the starting location x/y and starting orientation
public:
	virtual int getLength() = 0; //pure virtual function to get length of a ship
	virtual void hit() = 0; //pure virtual function to hit a ship
	virtual int getHealth() = 0; //pure virtual function to see if a ship is sunk or not
	virtual int getX() = 0; //pure virtual function to get a ships starting x location
	virtual void setX(int) = 0; //pure virtual function to set a ships starting x location
	virtual int getY() = 0; //pure virtual function to get a ships starting y location
	virtual void setY(int) = 0; //pure virtual function to set a ships starting y location
	virtual int getHorizVert() = 0; //pure virtual function to get a ships starting orientation
};

#endif

