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
