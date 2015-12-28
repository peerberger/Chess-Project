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
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			this->_tiles [ i ] [ j ] = nullptr;

	this->_tiles [ 0 ] [ 0 ] = new Tile ( "a1", new Rook ( "a1", 0, true ) );
	this->_tiles [ 7 ] [ 0 ] = new Tile ( "h1", new Rook ( "h1", 0, true ) );
	this->_tiles [ 0 ] [ 7 ] = new Tile ( "a8", new Rook ( "a8", 1, true ) );
	this->_tiles [ 7 ] [ 7 ] = new Tile ( "h8", new Rook ( "h8", 1, true ) );
}


Board::~Board ()
{
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
			if ( this->_tiles [ i ] [ j ] != nullptr )
			{
				this->_tiles [ i ] [ j ] ->~Tile ();
				delete this->_tiles [ i ] [ j ];
				this->_tiles [ i ] [ j ] = nullptr;
			}
}


string Board::getBoard () const
{
	string board = "";
	for ( int i = 0; i < 8; i++ )
		for ( int j = 0; j < 8; j++ )
		{
			if ( this->_tiles [ i ] [ j ]->getTool () != nullptr )
			{
				board += this->_tiles [ i ] [ j ]->getTool ()->getSymbol ();
			}
			else board += '#';
		}
	board += "0";
	return board;
}


Tile* Board::getTile ( string tile ) const
{
	return this->_tiles [ tile [ 0 ] - 'a' ] [ tile [ 1 ] - '0' ];
}


int Board::play ( string )
{
	return 0;
}