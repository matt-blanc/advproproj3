#pragma once
#include "stdafx.h"
#include <iostream>
#ifndef SHIP_H
#define SHIP_H

using namespace std;

class Ship
{
	int x1, y1, x2, y2;		//positions
	int* health;
	int size;

public:
	Ship(int horiz1, int vert1, int horiz2, int vert2, int sz);  //constructor
	~Ship();  //destructor that will be used to destroy the health array
	virtual int getLength() = 0; //pure virtual function to get length of a ship
	virtual int hit() = 0; //pure virtual function to hit a ship
	virtual int sunk() = 0; //pure virtual function to see if a ship is sunk

};

#endif
