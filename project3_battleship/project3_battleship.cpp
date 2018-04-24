// project3_battleship.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "Board.h"
#include "Battleship.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
	//Seeds random number
	srand(time(NULL));
	//Needed variables and a placeholder HEALTH
	int HEALTH = 4, guessX, guessY, turns = 0;
	//top board 6x6 using default constructor
	Board top;
	//bot board 6x6 using other constructor
	Board bot(5);
	Battleship test;
	Battleship test2;
	Ship *shipList[] = { &test, &test2 };
	for (int i = 0; i < 2; i++)
	{
		bot.addShip(shipList[i]);
	}
	//DEBUG TO SEE BOTTOM BOARD
	cout << bot << endl;
	cout << "Welcome to singleplayer Battleship!" << endl << "'0' is a spot that has not been guessed" << endl << "'1' is a hit" << endl << "'5' is a miss" << endl;
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
		int gotX, gotY, length, horizVert;
		if (top.at(guessY, guessX) == 1)
		{
			for (int i = 0; i < 2; i++)
			{
				horizVert = shipList[i]->getHorizVert();
				gotX = shipList[i]->getX();
				gotY = shipList[i]->getY();
				length = shipList[i]->getLength();
				if (horizVert == 0)
				{
					if ((gotY == guessY) && ((guessX < (gotX + length))) && (guessX >= gotX))
					{
						cout << endl << "Wow you got a hit!";
						shipList[i]->hit();
						break;
					}
				}
				else if (shipList[i]->getHorizVert() == 1)
				{
					if ((gotX == guessX) && ((guessY < (gotY + length)) && (guessY >= gotY)))
					{
						cout << endl << "Wow you got a hit!";
						shipList[i]->hit();
						break;
					}
				}
			}
			//WHATEVER SHIP IS THERE LOSE 1 "HEALTH"
		}
		else
		{
			//IF NOT OUTPUT MISS
			cout << "That was a miss!" ;
		}

		//Do while HEALTH PLACEHOLDER is greater than 0
	} while ((shipList[0]->getHealth() + shipList[1]->getHealth()) > 0);
	//When all ships are sunk say you won in that amount of turns
	cout << endl << top << endl << "Contratulations you won in " << turns << " turns!" << endl;
    return 0;
}