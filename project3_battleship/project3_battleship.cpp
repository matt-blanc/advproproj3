// project3_battleship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

int main()
{
	int HEALTH = 3, guessX, guessY;
	Board top;
	Board bot(5);
	cout << "Welcome to single player Battleship!";
	//CREATE SHIPS AND PUT ONTO BOARD
	do
	{
		do
		{
			cout << endl << top << endl << "Please enter guess for x-coordinate and then y-coordinate: ";
			cin >> guessX;
			cin >> guessY;
			if (top.at(guessX, guessY) == 5 || top.at(guessX, guessY) == 1)
			{
				cout << "ERROR CANNOT CHOOSE SAME PLACE TWICE";
			}
			if (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0)
			{
				cout << "ERROR X OR Y OUT OF BOUNDS";
			}
		} while ((top.at(guessX, guessY) == 5 || top.at(guessX, guessY) == 1) || (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0));
		top.at(guessX, guessY) = bot.at(guessX, guessY);
		if (top.at(guessX, guessY) == 1)
		{
			HEALTH -= 1;
			cout << endl << "Wow you got a hit!";
			//WHATEVER SHIP IS THERE LOSE 1 "HEALTH"
		}
		else
		{
			cout << "That was close but not on target!";
		}

	} while (HEALTH > 0);


    return 0;
}

