#pragma once
#include "stdafx.h"
#include "Ship.h"
#include "Board.h"
//EACH SHIP NEEDS: health, position x/y, vert/horiz


/*Ship::Ship(int horiz1, int vert1, int horiz2, int vert2, int sz)
{
	x1 = horiz1;
	y1 = vert1;
	x2 = horiz2;
	y2 = vert2;
	size = sz;

	health = new int [sz];
		
	for (int i = 0; i < sz; i++)
	{
		health[i] = 0;
	}


} 
Ship::~Ship()				//destructor that will be used to destroy the health array
{
	delete[] health;//[] to delete entire array rather than just first position
}
*/

/* 1). need a pure virtual function for hit (moves health array down by 1) and getlength/getsize
	2). do we need heatlth to be an array or can it be an integer?
	not in Ship.cpp 3). if hits > size then boat is sunk, because a position cannot be picked twice. TIP have sunk return a value of 1, and have a counter for sunk where if it equals 3 the gamme is won.
	4). return name function and use ex) cruiser.hit, then check if it is sunk, and if so, add 1 to the sunk counter


	3&4 work off of each other. 
*/
