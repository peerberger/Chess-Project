#include "Rook.h"
#include <string>

using namespace std;

Rook::Rook(Location loc, int player ,bool onBoard) : Tool(loc, player, onBoard)
{
	
}

char Rook::getSymbol()
{
	char ans;
	if (this == nullptr)
	{
		return '#';
	}
	else if (this->_player == 0)
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
	int ans = 0;
	string srcTile = command.substr(0, 2);
	string dstTile = command.substr(2);
	if (srcTile == dstTile)
	{
		ans = 7; //hello
	}
	else if (command[0] != command[2] && command[1] != command[3])
	{
		ans = 6;
	}
	else if ((command[0] > 'h' || command[0] < 'a') || (command[2] > 'h' || command[2] < 'a') || (command[1] < '1' || command[1] > '8') || (command[3] < '1' || command[3] > '8'))
	{
		ans = 5;
	}
	return ans;
}