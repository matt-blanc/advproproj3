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
	//Needed variables and a placeholder HEALTH
	int HEALTH = 4, guessX, guessY, turns = 0;
	//top board 6x6 using default constructor
	Board top;
	//bot board 6x6 using other constructor
	Board bot(5);
	//DEBUG TO SEE BOTTOM BOARD
	cout << bot << endl;
	cout << "Welcome to singleplayer Battleship!";
	//CREATE SHIPS AND PUT ONTO BOARD
	do
	{
		do
		{
			//Get guess from user
			cout << endl << top << endl << "Please enter guess for x-coordinate and then y-coordinate: ";
			cin >> guessX;
			cin >> guessY;
			//Check to see if that spot has been guessed before
			if (top.at(guessY, guessX) == 5 || top.at(guessY, guessX) == 1)
			{
				cout << "ERROR CANNOT CHOOSE SAME PLACE TWICE";
			}
			//Checks to see if the choice was out of bounds
			if (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0)
			{
				cout << "ERROR X OR Y OUT OF BOUNDS";
			}
			//Keep guessing until a valid guess is chosen
		} while ((top.at(guessY, guessX) == 5 || top.at(guessY, guessX) == 1) || (guessX > 5 || guessX < 0 || guessY > 5 || guessY < 0));
		//Increment turns if valid guess
		turns++;
		//Put bottom board value on top board
		top.at(guessY, guessX) = bot.at(guessY, guessX);
		//If the value was a hit (1) decrement HEALTH PLACEHOLDER
		if (top.at(guessY, guessX) == 1)
		{
			HEALTH -= 1;
			cout << endl << "Wow you got a hit!";
			//WHATEVER SHIP IS THERE LOSE 1 "HEALTH"
		}
		else
		{
			//IF NOT OUTPUT MISS
			cout << "That was a miss!";
		}

		//Do while HEALTH PLACEHOLDER is greater than 0
	} while (HEALTH > 0);
	//When all ships are sunk say you won in that amount of turns
	cout << " You won in " << turns << " turns!";
    return 0;
}