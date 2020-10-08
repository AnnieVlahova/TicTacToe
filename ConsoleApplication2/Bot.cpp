#include "pch.h"

#include "Bot.h"
#include "Player.h"

bool Bot::getIsBotsTurn() const
{
	return isBotsTurn;
}
void Bot::setIsBotsTurn(bool turn)
{
	isBotsTurn = turn;
}
Bot::Bot(char symbol, bool first) : Player(symbol, first)
{
	isBotsTurn = first;
}