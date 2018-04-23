//All needed header files
#pragma once
#include "stdafx.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Ship.h"
using namespace std;

class Board //Board class to show and change board values
{
	
protected:
	int *board; //Will be used for an array
public:
	Board(); //Default constructor
	Board(int); //Other constructor
	~Board(); //Destructor
	int& at(int, int); //changing value at a point
	void addShips(Ship*);
	friend ostream &operator<<(ostream&, const Board&); //operator overloading to show board
};
