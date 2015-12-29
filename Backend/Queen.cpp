#include "Queen.h"

Queen::Queen(Location loc, int player, bool onBoard) : Tool(loc, player, onBoard)
{
}

char Queen::getSymbol()
{
	
	/*if (this == nullptr) // ->  Makes some problems, Tile::getToolSymbol helps to fix it
	{
		return '#';
	}*/
	
	return 'q' - this->_player * ( 'q' - 'Q' ); // Let's use it here as well
}

int Queen::moveTool(string command)
{
	// Let's firstly make it compound with 'if's and then nake it compact
	int valid = 6;
	int srcX = command [ 0 ] - 'a';
	int srcY = command [ 1 ] - '1';
	int dstX = command [ 2 ] - 'a';
	int dstY = command [ 3 ] - '1';

	//src == dst check has been made before calling this method
	if ( srcX == dstX || srcY == dstY /* A Rook movement check */
		 ||
		 abs (srcX - dstX) == abs (srcY - dstY) ) /* A Bishop movement check */
	{
		valid = 0;
	}
	
	return 0;
}