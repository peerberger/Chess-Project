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
	/*
		The only check that must be performed here is the movement availabilty for a rook.
	*/
	/*
	int ans = 0;
	string srcTile = command.substr(0, 2);
	string dstTile = command.substr(2);
	if (srcTile == dstTile)
	{
		ans = 7; //hello? For Yehuda
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
	*/

	// If The the columns are equal xor the the rows ar equal, this is an available rook move so return 6 * 0 (=0), else, return 1 * 6 (=6)
	// Quite simple ha?... ( :D )
	return 6 * !( ( command [ 0 ] != command [ 2 ] ) ^ ( command [ 1 ] != command [ 3 ] ) );
	
}