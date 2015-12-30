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
	char symbol = 'q';

	if ( this->_player == 0 )
	{
		symbol = 'Q';
	}

	return symbol;
}

int Queen::moveTool(string command)
{
	// Let's firstly make it compound with 'if's and then nake it compact
	int valid = 0;
	int srcX = command [ 0 ] - 'a';
	int srcY = command [ 1 ] - '1';
	int dstX = command [ 2 ] - 'a';
	int dstY = command [ 3 ] - '1';

	if (!( (srcX == dstX) ^ (srcY == dstY) )) // Check a rook movement
	{
		valid = 6;
	}
	else if ( abs ( srcX - dstX ) != abs ( srcY - dstY ) ) // Check a bishop movement
	{
		valid = 6;
	}

	
	return valid;
}