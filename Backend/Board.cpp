/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tile class implementation code.
*/

#include "Board.h"
#include "Rook.h"


Board::Board ( int starting_player )
	:_currPlayer ( starting_player )
{
	this->_tiles [ 0 ] [ 0 ] = new Tile ( "a1", new Rook ( "a1", true ) );
}