#include "stdafx.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Battleship.h"
#include "Ship.h"
//EACH SHIP NEEDS: health, position x/y, vert/horiz

Ship::Ship()
{
	shipType = "";
	shipDirect = Vertical;
	startRow = 0;
	startCol = 0;
	numHits = 0;

}

Ship::Ship(int nHits, string name)
{
	shipType = "";
	shipDirect = Vertical;
	startRow = 0;
	startCol = 0;
	numHits = nHits;
}

//set and get for start row for placement of ships
void Ship::setStartRow(int StRow)
{
	startRow = StRow;
}

int Ship::getStartRow()
{
	return startRow;
}

//set and get for start column for placement of ships
void Ship::setStartCol(int StCol)
{
	startCol = StCol;
}

int Ship::getStartCol()
{
	return startCol;
}


//function for number of hits on ship
int Ship::getNumOfHits()
{
	return numHits;
}

//set and get for ship direction (vertical or horizontal)
void Ship::setShipDir(ShipDirection shipDir)
{
	shipDirect = shipDir;
}
ShipDirection Ship::getShipDir()
{
	return shipDirect;
}

//set and get for ship type
void Ship::setNameShip(string name)
{
	shipType = name;
}

string Ship::getNameShip()
{
	return shipType;
}