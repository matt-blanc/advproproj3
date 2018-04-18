//All needed header files
#pragma once
#include "stdafx.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

//Board class to show and change board values
class Board
{
	//Will be used for an array
protected:
	int *board;
public:
	//Default and one other Constructor, Desctructor, changing value at a point, operator overloading to show board to screen
	Board();
	Board(int);
	~Board();
	int& at(int, int);
	friend ostream &operator<<(ostream&, const Board&);
};
