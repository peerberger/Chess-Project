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
		{
			char buffer [ 3 ];
			buffer [ 0 ] = i + 'a';
			buffer [ 1 ] = j + '1';
			buffer [ 2 ] = '\0';
			this->_tiles [ i ] [ j ] = new Tile ( string (buffer), nullptr );
		}

	this->_tiles [ 0 ] [ 0 ] = new Tile ( "a1", new Rook ( "a1", 1, true ) );
	this->_tiles [ 0 ] [ 7 ] = new Tile ( "a8", new Rook ( "a8", 1, true ) );
	this->_tiles [ 7 ] [ 0 ] = new Tile ( "h1", new Rook ( "h1", 0, true ) );
	this->_tiles [ 7 ] [ 7 ] = new Tile ( "h8", new Rook ( "h8", 0, true ) );
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
	int tileJ = tile[0] - 'a';
	int tileI = tile[1] - '1';
	return this->_tiles [ tileI ] [ tileJ ];
}


int Board::play ( string move )
{
	string src = move.substr ( 0, 2 );
	string dst = move.substr ( 2 );

	Tile* tile = this->getTile ( src );
	if ( tile->isOccupied () )
	{
		
		Tool* tool = tile->getTool ();
		return tool->moveTool ( move );
		// return this->getTile ( src )->getTool ()->moveTool ( dst );
	}
	return 2;
}