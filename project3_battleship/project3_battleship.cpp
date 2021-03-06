//project3_battleship.cpp : Defines the entry point for the console application.
//SINGLE PLAYER BATTLESHIP BY MATTHEW BLANC, STEFAN NORTZ, ALYSSA PHOTHISEN
#pragma once
#include "stdafx.h"
#include "Board.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	//Seeds random number
	srand(time(NULL));
	//Needed variables- guess in X/Y, total turns, and how to tell where a ship is
	int guessX, guessY, turns = 0, gotX, gotY, length, horizVert;
	//top board 6x6 using default constructor
	Board top;
	//bot board 6x6 using other constructor
	Board bot(5);
	//default constructors for each ship type
	Battleship bat;
	Cruiser cru;
	Destroyer des;
	//ship pointer array as a reference to each type of ship
	Ship *shipList[] = { &bat, &cru, &des };
	//Adds each ship to the board
	for (int i = 0; i < 3; i++)
	{
		bot.addShip(shipList[i]);
	}
	//output rules
	cout << "Welcome to singleplayer Battleship!" << endl << "Rules for Battleship: " <<
		endl << "Use the outer 0-5 lines to choose a location (x being the column, and y being the row)" <<
		endl << "'0' is a spot that has not been guessed" << endl << "'1' is a hit" << endl << "'5' is a miss" << endl;
	//do while total health > 0
	do
	{
		//do while a non valid guess
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
		//If the value was a hit (1) decrement health
		if (top.at(guessY, guessX) == 1)
		{
			//Check each ship to see if it was hit
			for (int i = 0; i < 3; i++)
			{
				//Putting each getter value into a variable
				horizVert = shipList[i]->getHorizVert();
				gotX = shipList[i]->getX();
				gotY = shipList[i]->getY();
				length = shipList[i]->getLength();
				//If horizVert == 0 horizontal, == 1 vertical
				if (horizVert == 0)
				{
					//Checks to see if this ship was hit
					if ((gotY == guessY) && ((guessX <= (gotX + length))) && (guessX >= gotX))
					{
						//Output to screen and use hit function
						cout << endl << "Wow you got a hit!";
						shipList[i]->hit();
						//Check to see if the health is = 0 then the ship is sunk
						if (shipList[i]->getHealth() == 0)
						{
							//Output the type of ship sunk
							cout << " You sunk a ";
							switch (length)
							{
							case 4: cout << "Battleship!";
								break;
							case 3: cout << "Cruiser!";
								break;
							case 2: cout << "Destroyer!";
								break;
							}
						}
						break;
					}
				}
				//Vertical ship
				else if (shipList[i]->getHorizVert() == 1)
				{
					//Checks to see if this ship was hit
					if ((gotX == guessX) && (guessY < (gotY + length)) && (guessY >= gotY))
					{
						//Output to screen and use hit function
						cout << endl << "Wow you got a hit!";
						shipList[i]->hit();
						//Check to see if the health is = 0 then the ship is sunk
						if (shipList[i]->getHealth() == 0)
						{
							//Output which ship was sunk
							cout << " You sunk a ";
							switch (length)
							{
							case 4: cout << "Battleship!";
								break;
							case 3: cout << "Cruiser!";
								break;
							case 2: cout << "Destroyer!";
								break;
							}
						}
						break;
					}
				}
			}
		}
		else
		{
			//If a ship wasn't hit then output miss
			cout << "That was a miss!";
		}
		//play the game while the total health is lower than 0
	} while ((shipList[0]->getHealth() + shipList[1]->getHealth() + shipList[2]->getHealth()) > 0);
	//When all ships are sunk say you won in that amount of turns
	cout << endl << top << endl << "Congratulations you won in " << turns << " turns!" << endl;
	return 0;
}