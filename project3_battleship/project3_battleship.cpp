// project3_battleship.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Board.h"
#include "Battleship.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

int main()
{
	int HEALTH = 4, guessX, guessY, turns = 0;
	Board top;
	Board bot(5);
	cout << bot << endl;
	cout << "Welcome to singleplayer Battleship!";
	//CREATE SHIPS AND PUT ONTO BOARD
	do
	{
		do
		{
			cout << endl << top << endl << "Please enter guess for x-coordinate and then y-coordinate: ";
			cin >> guessX;
			cin >> guessY;
			if (top.at(guessY, guessX) == 5 || top.at(guessY, guessX) == 1)
			{
				cout << "ERROR CANNOT CHOOSE SAME PLACE TWICE";
			}
			if (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0)
			{
				cout << "ERROR X OR Y OUT OF BOUNDS";
			}
		} while ((top.at(guessY, guessX) == 5 || top.at(guessY, guessX) == 1) || (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0));
		turns++;
		top.at(guessY, guessX) = bot.at(guessY, guessX);
		if (top.at(guessY, guessX) == 1)
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
	cout << " You won in " << turns << " turns!";

    return 0;
}