#include "pch.h"

#include "TicTacToe.h"



Player& TicTacToe::PlayerAtWins(int x, int y)
{
	char c = board.symbolAt(x, y);
	if (players[0].getSymbol() == c)
	{
		players[0].setWinner(true);
		return players[0];
	}
	else
	{
		players[1].setWinner(true);
		return players[1];
	}
}
void TicTacToe::checkForWinner()
{
	if (board.Diagonal())
	{
		foundAWinner = true;
		winner = PlayerAtWins(1, 1);
	}

	for (int i = 0; i < 3; i++)
	{
		if (board.ThreeInARow() == i || board.ThreeInACol() == i)
		{
			foundAWinner = true;
			winner = PlayerAtWins(i, i);

		}
	}
}
Board& TicTacToe::getBoard()
{
	return this->board;
}
Player& TicTacToe::PlayerTurn()
{
	if (board.getCountOfSymbols() % 2 == 0)
		return players[0];
	else
		return players[1];
}
TicTacToe::TicTacToe(Board& b, Player& p1, Player& p2)
{
	board = b;
	players[0] = p1;
	players[1] = p2;
	foundAWinner = false;
	multiplayer = true;
}
TicTacToe::TicTacToe(Board& b, Player& p1, Bot& bot)
{
	board = b;
	players[0] = p1;
	players[1] = bot;
	foundAWinner = false;
	multiplayer = false;

}
bool TicTacToe::Over()
{
	if (board.getCountOfSymbols() != 9 && !foundAWinner)
		return false;
	return true;

}
void TicTacToe::Update()
{
	checkForWinner();
	board.Print();
	if (foundAWinner)
	{
		cout << "The winner is player "
			<< winner.getSymbol() << endl;

	}
	else if(Over())
	{
		cout << "Game Over!" << endl;
	}
}
void TicTacToe::botMove()
{
	int randX, randY;
	randX = rand() % 3;
	randY = rand() % 3;

	board.setPositions(randX, randY, players[1].getSymbol());
}
