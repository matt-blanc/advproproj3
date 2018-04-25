<<<<<<< HEAD
#include "stdafx.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Battleship.h"
#pragma once

//enumerated data type to use the labels of "Vertical" & "Horizontal" to describe placement of ship
enum ShipDirection {Vertical, Horizontal}; 

//declaration of class Ship
class Ship {
private: 
	int numHits;
	string shipType;
	ShipDirection shipDirect;
	int startRow;
	int startCol;

public:

	Ship();
	Ship(int nHits, string shipName);

	void setStartRow(int StRow); 
	int getStartRow();

	void setStartCol(int StCol);
	int getStartCol();

	int getNumOfHits();

	ShipDirection getShipDir();
	void setShipDir(ShipDirection shipDir);

	string getNameShip();
	void setNameShip(string Name);


};
=======
#pragma once
#include "stdafx.h"
#include <iostream>
#ifndef SHIP_H
#define SHIP_H
using namespace std;

class Ship
{
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
>>>>>>> b4fe1d14f4331307ee9dbe3d64a5375f809b52ec
