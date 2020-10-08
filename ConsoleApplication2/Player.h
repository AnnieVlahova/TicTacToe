#pragma once



class Player
{

protected:
	bool first;
	bool winner;
	char symbol;

public:
	static const char playerXSymbol = 'X';
	static const char playerOSymbol = 'O';
	bool getWinner() const;
	bool getFirst() const;
	char getSymbol() const;
	void setWinner(bool winner);
	void setFirst(bool first);
	void setSymbol(char s);
	Player();
	Player(char symbol, bool first);

};