// project3_battleship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

int main()
{
	Board b;
	b.at(0, 0) = 1;
	cout << b;

    return 0;
}

