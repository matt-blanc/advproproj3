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
//Bottom board
Board::Board(int val)
{
	//Initial seed for random number
	srand(time(NULL));
	//0 = horizontal, 1 = vertical
	int horizVert = (rand() % 2), startLoc, rowCol;
	//Creates an array of size 36
	board = new int[36];

	//Sets each value to 0 when initialized
	for (int i = 0; i < 36; i++)
	{
		board[i] = val;
	}
	if (horizVert == 0)
	{
		do
		{
			rowCol = rand() % 6;
			startLoc = rand() % 6;
		} while (startLoc + 4 > 6);
		for (int i = startLoc; i < (startLoc + 4); i++)
		{
			board[(rowCol * 6) + i] = 1;
		}
	}
	else
	{
		do
		{
			rowCol = rand() % 6;
			startLoc = rand() % 6;
		} while (startLoc + 4 > 6);
		for (int i = startLoc; i < (startLoc + 4); i++)
		{
			board[rowCol + (i * 6)] = 1;
		}
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
