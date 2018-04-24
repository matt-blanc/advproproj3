//Needed libraries
#include "stdafx.h"
#include "Board.h"
using namespace std;

//Top board
Board::Board()
{
	//Creates an array of size 36
	board = new int[36];
	//Sets each value to 0 when initialized
	for (int i = 0; i < 36; i++)
	{
		board[i] = 0;
	}
}
Board::Board(int val)
{
	//Creates an array of size 36
	board = new int[36];
	//Sets each value to val when initialized
	for (int i = 0; i < 36; i++)
	{
		board[i] = val;
	}
}
//Destructor for new data
Board::~Board()
{
	delete[] board;
}
//Returns a reference to the pointer at the specified location (changes the value at that point)
int& Board::at(int row, int col)
{
	return board[row * 6 + col];
}
void Board::addShips(Ship* shipList)
{
	//Boolean to see if it needs to change location
	bool changeLoc;
	//0 = horizontal, 1 = vertical
	int col, row;
	for (int j = 0; j < 2; j++)
	{
		//If its 0 horizontal, 1 vertical
		if (shipList[j].getHorizVert() == 0)
		{
			do
			{
				//Makes it default to no error
				changeLoc = false;
				//Gets a semi-random row and column
				row = (int)rand() % 6;
				col = (int)rand() % (6 - shipList[j].getLength());
				//First checks to see if something else is there where it wants to go
				for (int i = col; i < (col + shipList[j].getLength()); i++)
				{
					if (board[(row * 6) + i] == 1)
					{
						changeLoc = true;
						break;
					}
				}
				//If it does not need to change, put a ship there
				if (!changeLoc)
				{
					for (int i = col; i < (col + shipList[j].getLength()); i++)
					{
						board[(row * 6) + i] = 1;
					}
				}
			} while (changeLoc);
		}
		else
		{
			do
			{
				//Makes it default to no error
				changeLoc = false;
				//Gets a semi-random row and column
				row = (int)rand() % (6 - shipList[j].getLength());
				col = (int)rand() % 6;
				//First checks to see if something else is there where it wants to go
				for (int i = row; i < (row + shipList[j].getLength()); i++)
				{
					if (board[row + (i * 6)] == 1)
					{
						changeLoc = true;
						break;
					}
				}
				//If it does not need to change, put a ship there
				if (!changeLoc)
				{
					for (int i = row; i < (row + shipList[j].getLength()); i++)
					{
						board[row + (i * 6)] = 1;
					}
				}
			} while (changeLoc);
		}
		shipList[j].setX(col);
		shipList[j].setY(row);
	}
}
//Operator overloading to use with cout to form board
ostream &operator<<(ostream&, const Board& b)
{
	//Sets up column numbering
	cout << " ";
	for (int i = 0; i < 6; i++)
	{
		cout << setw(2) << i;
	}
	//Outputs board values and row numbering
	for (int i = 0; i < 6; i++)
	{
		cout << endl << i;
		for (int j = 0; j < 6; j++)
		{
			cout << setw(2) << b.board[(i * 6) + j];
		}
	}
	cout << endl;
	return cout;
}
