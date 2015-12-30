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

int King::moveTool(string command)
{
	int valid = 0;
	int srcX = command[0] - 'a';
	int srcY = command[1] - '1';
	int dstX = command[2] - 'a';
	int dstY = command[3] - '1';
	if (!((abs(srcX - dstX) == 1) ^ (abs(srcY - dstY) == 1))) // Check a rook movement for only 1 tile.
	{
		valid = 6;
	}
	else if (abs(srcX - dstX) != abs(srcY - dstY) || abs(srcX-dstX)>1 || abs(srcY-dstY)>1)// Check a bishop movement for only one tile
	{
		valid = 6;
	}
	return valid;
}