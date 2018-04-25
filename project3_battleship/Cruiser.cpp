#include "stdafx.h"
#include "Cruiser.h"
#include <cmath>

//Default constructor for a "cruiser" sized ship
Cruiser::Cruiser()
{
	health = 3;
	length = 3;
	//placeholder values, will always be changed in board class
	startX = 0;
	startY = 0;
	horizVert = (int)rand() % 2;
}
//Decrements health if ship is hit
void Cruiser::hit()
{
	health -= 1;
}
//returns health
int Cruiser::getHealth()
{
	return health;
}
//returns length
int Cruiser::getLength()
{
	return length;
}
//returns starting x coordinate
int Cruiser::getX()
{
	return startX;
}
//sets starting x coordinate
void Cruiser::setX(int x)
{
	startX = x;
}
//returns starting y coordinate
int Cruiser::getY()
{
	return startY;
}
//sets starting y coordinate
void Cruiser::setY(int y)
{
	startY = y;
}
int Cruiser::getHorizVert()
{
	return horizVert;
}

