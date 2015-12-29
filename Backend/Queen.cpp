#include "Queen.h"

Queen::Queen(Location loc, int player, bool onBoard) : Tool(loc, player, onBoard)
{
}

char Queen::getSymbol()
{
	char ans;
	if (this == nullptr)
	{
		return '#';
	}
	else if (this->_player == 0)
	{
		ans = 'Q';
	}
	else
	{
		ans = 'q';
	}
	return ans;
}

int Queen::moveTool(string command)
{
	return 0;
}