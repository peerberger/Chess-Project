#include "Rook.h"

Rook::Rook(Location loc, bool onBoard) : Tool(loc,onBoard)
{
	
}

char Rook::getSymbol()
{
	char ans;
	if (this->_player == 0)
	{
		ans = 'R';
	}
	else
	{
		ans = 'r';
	}
	return ans;
}

int Rook::moveTool(string command)
{
	int dstJ = command[2] - 97;
	int dstI = command[3] - 48;
	if (this->_board->getTile()->isOccupied() == false)
	{

	}
	return 0;
}