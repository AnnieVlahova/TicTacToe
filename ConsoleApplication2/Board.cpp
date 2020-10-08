#include "pch.h"

#include "Board.h"


bool Board::getSuccTurn() const
{
	return succTurn;
}
void Board::setSuccTurn(bool sT)
{
	succTurn = sT;
}
char Board::symbolAt(int x, int y) const
{
	return positions[x][y];
}
int Board::getCountOfSymbols() const
{
	return countOfSymbols;
}
void Board::setCountOfSymbols(int c)
{
	if (c >= 0 && c <= 9)
		countOfSymbols = c;
	else
		c = 0;
}
void Board::setPositions(int x, int y, char symbol)
{
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
	{
		if (positions[x][y] == 'X' || positions[x][y] == 'O')
		{
			succTurn = false;
			return;
		}
		positions[x][y] = symbol;
		succTurn = true;
		countOfSymbols++;
	}
}
Board::Board()
{
	initPositions();
	setCountOfSymbols(0);
	setSuccTurn(true);
}
void Board::initPositions()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			positions[i][j] = ' ';
		}
	}
}
void Board::Print()
{
	cout << "    0   1   2   " << endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << "  +---+---+---+  " << endl;
		cout << i << " |" << positions[i][0] << "  |" << positions[i][1] << "  |" << positions[i][2] << "  |" << endl;
	}
	cout << "  +---+---+---+  " << endl;
}


int Board::ThreeInARow()
{
	for (int i = 0; i < ROW; i++)
	{
		if (positions[i][0] == positions[i][1] && positions[i][1] == positions[i][2] && positions[i][1] != ' ')
		{
			return i;
		}
	}
	return -1;
}
int Board::ThreeInACol()
{
	for (int i = 0; i < COL; i++)
	{
		if (positions[0][i] == positions[1][i] && positions[1][i] == positions[2][i] && positions[1][i] != ' ')
		{
			return i;
		}
	}
	return -1;
}
bool Board::Diagonal()
{
	if (positions[0][0] == positions[1][1] && positions[1][1] == positions[2][2] && positions[1][1] != ' ')
		return true;
	else if (positions[0][2] == positions[1][1] && positions[1][1] == positions[2][0] && positions[1][1] != ' ')
		return true;
	else
		return false;
}