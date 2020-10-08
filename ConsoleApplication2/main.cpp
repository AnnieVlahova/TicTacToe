
#include "pch.h"
#include <iostream>
#include "Player.h"
#include "Board.h"
#include "Bot.h"
#include "TicTacToe.h"


using namespace std;

void PlayMulti(Board& board, char secondSymbol, Player& player1);
void PlayAlone(Board& board, char secondSymbol, Player& player1);


int main()
{
	const char XChar = 'X';
	const char OChar = 'O';
	bool isSecond = false;
	bool multiplay;
	cout << "How many player do you want?(1 or 2)" << endl;
	int numOfPlayers;
	char charNum;
	do
	{
		cin >> charNum;
		numOfPlayers = charNum - '0';
		if (numOfPlayers != 1 && numOfPlayers != 2)
		{
			cout << "There is not an option for " << numOfPlayers << " players." << endl;
		}
		else if (numOfPlayers == 1)
			multiplay = false;
		else
			multiplay = true;
	} while (numOfPlayers != 1 && numOfPlayers != 2);

	
	char firstSymbol, secondSymbol;

	do
	{
		std::cout << "Enter X or O: ";
		cin >> firstSymbol;
		if (firstSymbol == XChar || firstSymbol == OChar)
		{
			break;
		}
		else
		{
			cout << "Only X or O are allowed." << endl;
		}
	} while (firstSymbol != XChar || firstSymbol != OChar);

	Player player1(firstSymbol, true);
	if (firstSymbol == player1.playerXSymbol)
		secondSymbol = player1.playerOSymbol;
	else
		secondSymbol = player1.playerXSymbol;

	Board board;
	if (multiplay)
	{
		PlayMulti(board, secondSymbol, player1);
	}
	else
	{
		PlayAlone(board, secondSymbol, player1);
	}


}

void PlayMulti(Board& board, char secondSymbol, Player& player1)
{
	Player player2(secondSymbol, false);
	TicTacToe game(board, player1, player2);

	game.getBoard().Print();

	char xChar, yChar;
	int x, y;
	while (game.getBoard().getCountOfSymbols() != 9 && !(game.Over()))
	{
	cout << "Position: ";
	cin >> xChar;
	cin >> yChar;
	x = xChar - '0';
	y = yChar - '0';
	game.getBoard().setPositions(x, y, game.PlayerTurn().getSymbol());
	if (!game.getBoard().getSuccTurn())
	{
		cout << "You can't play there!" << endl;
	}
	game.Update();
	}
}
void PlayAlone(Board& board, char secondSymbol, Player& player1)
{
	Bot player2(secondSymbol, false);
	TicTacToe game(board, player1, player2);

	game.getBoard().Print();

	char xChar, yChar;
	int x, y;
	while (game.getBoard().getCountOfSymbols() != 9 && !game.Over())
	{
		if (player2.getIsBotsTurn())
		{
			game.botMove();
			if (game.getBoard().getSuccTurn() == true)
			{
				player2.setIsBotsTurn(false);
				game.Update();

			}
			else
			{
				cout << "You can't play there!" << endl;
			}
			
		}
		else
		{
			cout << "Position: ";
			cin >> xChar;
			cin >> yChar;
			x = xChar - '0';
			y = yChar - '0';
			game.getBoard().setPositions(x, y, game.PlayerTurn().getSymbol());
			if (game.getBoard().getSuccTurn() == true)
			{
				player2.setIsBotsTurn(true);
				game.Update();
			}
			else
			{
				if(!player2.getIsBotsTurn())
					cout << "You can't play there!" << endl;
			}
		}
		
	
	}
}