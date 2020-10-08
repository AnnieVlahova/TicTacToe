#include "pch.h"

#include "Player.h"


Player::Player()
{
	setSymbol(playerXSymbol);
	setFirst(true);
	setWinner(false);
}
bool Player::getWinner() const
{
	return winner;
}
bool Player::getFirst() const
{
	return first;
}
char Player::getSymbol() const
{
	return symbol;
}
void Player::setFirst(bool first)
{
	this->first = first;
}
void Player::setSymbol(char s)
{
	if (s == playerXSymbol || s == playerOSymbol)
		symbol = s;
	else
		symbol = playerOSymbol;
}
void Player::setWinner(bool winner)
{
	this->winner = winner;
}


Player::Player(char symbol, bool first)
{
	setSymbol(symbol);
	setFirst(first);
	setWinner(false);
}