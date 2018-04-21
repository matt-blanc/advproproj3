#include "stdafx.h"
#include "Battleship.h"

Battleship::Battleship()
{
	health = 4;
	length = 4;
}
void Battleship::hit()
{
	health = health - 1;
}
int Battleship::getHealth()
{
	return health;
}
int Battleship::getLength()
{
	return length;
}