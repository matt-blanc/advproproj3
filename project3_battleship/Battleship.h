#pragma once
class Battleship
{
protected:
	int health;
	int length;
public:
	Battleship();
	void hit();
	int getHealth();
	int getLength();
};