#pragma once

#include "Player.h"
#include "Board.h"
#include "Bot.h"


class TicTacToe
{

	
	Board board;
	Player players[2];
	Player winner;
	bool multiplayer;
	bool foundAWinner;
	void checkForWinner();
	
public:
	
	Player& PlayerAtWins(int x, int y);
	Board& getBoard();
	TicTacToe(Board& b, Player& p1, Player& p2);
	TicTacToe(Board& b, Player& p1, Bot& bot);
	Player& PlayerTurn();
	void botMove();
	bool Over();
	void Update();
};