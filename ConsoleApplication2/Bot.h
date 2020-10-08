#pragma once
#include "Player.h"

class Bot : public Player
{
	bool isBotsTurn;

public:
	bool getIsBotsTurn() const;
	void setIsBotsTurn(bool turn);
	Bot(char symbol, bool first);
};