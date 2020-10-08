#pragma once

#include <iostream>
#include "Player.h"


using namespace std;

class Board
{

	static const int ROW = 3;
	static const int COL = 3;
	static const int startSymbols = 0;
	char positions[ROW][COL];
	int countOfSymbols;
	bool succTurn;

	static const int BOXES = 9;

public:

	bool getSuccTurn() const;
	void setSuccTurn(bool sT);
	char symbolAt(int x, int y) const;
	int getCountOfSymbols() const;
	void setCountOfSymbols(int c);
	void setPositions(int x, int y, char symbol);
	Board();
	void Print();
	void initPositions();
	int ThreeInARow();
	int ThreeInACol();
	bool Diagonal();
};