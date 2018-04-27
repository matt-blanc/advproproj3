#include "stdafx.h"
#include "Battleship.h"
#include <cmath>

//Default constructor for a "battleship" sized ship
Battleship::Battleship()
{
	health = 4;
	length = 4;
	//placeholder values, will always be changed in board class
	startX = 0;
	startY = 0;
	horizVert = (int)rand() % 2;
}
//Decrements health if ship is hit
void Battleship::hit()
{
	health-=1;
}
//returns health
int Battleship::getHealth()
{
	return health;
}
//returns length
int Battleship::getLength()
{
	return length;
}
//returns starting x coordinate
int Battleship::getX()
{
	return startX;
}
//sets starting x coordinate
void Battleship::setX(int x)
{
	startX = x;
}
//returns starting y coordinate
int Battleship::getY()
{
	return startY;
}
//sets starting y coordinate
void Battleship::setY(int y)
{
	startY = y;
}
//returns whether the ship is horizontal or vertical
int Battleship::getHorizVert()
{
	return horizVert;
}