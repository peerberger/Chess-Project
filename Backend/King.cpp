#include "King.h"

King::King(Location loc, int player, bool onBoard) : Tool(loc, player, onBoard)
{

}

char King::getSymbol()
{
	//According to the last commits the # makes problems so we wont return it.
	char symbol = 'k';
	if (this->_player == 0)
	{
		symbol = 'K';
	}
	return symbol;
}

int King::moveTool(string move)
{

}