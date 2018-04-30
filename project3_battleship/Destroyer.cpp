#include "stdafx.h"
#include "Destroyer.h"

//Default constructor for a "Destroyer" sized ship
Destroyer::Destroyer()
{
	health = 2;
	length = 2;
	//placeholder values, will always be changed in board class
	startX = 0;
	startY = 0;
	horizVert = (int)rand() % 2;
}
//Decrements health if ship is hit
void Destroyer::hit()
{
	health -= 1;
}
//returns health
int Destroyer::getHealth()
{
	return health;
}
//returns length
int Destroyer::getLength()
{
	return length;
}
//returns starting x coordinate
int Destroyer::getX()
{
	return startX;
}
//sets starting x coordinate
void Destroyer::setX(int x)
{
	startX = x;
}
//returns starting y coordinate
int Destroyer::getY()
{
	return startY;
}
//sets starting y coordinate
void Destroyer::setY(int y)
{
	startY = y;
}
//returns whether the ship is horizontal or vertical
int Destroyer::getHorizVert()
{
	return horizVert;
}
