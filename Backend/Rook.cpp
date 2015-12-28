#include "Rook.h"
#include <string>
#include <iostream>

using namespace std;

Rook::Rook(Location loc, int player ,bool onBoard) : Tool(loc, player, onBoard)
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
	string dstTile = command[2] + "" + command[3];
	/*if (this->_board->getTile(dstTile)->isOccupied() == false)
	{
		cout << dstI << " ," << dstJ << endl;
	}*/
	return 0;
}