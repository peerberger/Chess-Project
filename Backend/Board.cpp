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


/************************
* TODO:					*
*	MAKE IT MODULAR!!!	*
*************************/
int Board::play ( string move )
{
	int answer = 0;
	if ( move.length () != 4 )
	{
		answer = 5;
	}
	else
	{
		string source = move.substr ( 0, 2 );
		string destination = move.substr ( 2 );

		if ( source == destination )
		{
			answer = 7;
		}
		else
		{
			Tile* srcTile = this->getTile ( source );
			Tile* dstTile = this->getTile ( destination );

			if	(
					!( 
						srcTile->getTool ()->getSymbol () > 'a' - this->_currPlayer*( 'a' - 'A' )
						&&
						srcTile->getTool ()->getSymbol () < 'z' - this->_currPlayer * ( 'a' - 'A' )
					) 
				)
			{
				answer = 2;
			}
			else if (
					dstTile->getTool ()->getSymbol () > 'a' - this->_currPlayer*( 'a' - 'A' )
					&&
					dstTile->getTool ()->getSymbol () < 'z' - this->_currPlayer * ( 'a' - 'A' )
					)
			{
				answer = 3;
			}
			else if ( 0 /* Check if the owner king is threatened */ )
			{
				answer = 4;
			}
			else
			{
				answer = srcTile->getTool ()->moveTool ( destination );

				if ( answer == 0 )
				{
					if ( 0 /* Check if the rival king is threatened */ )
					{
						answer = 1;

						if ( 0 /* Check if the rival king can't move*/ )
						{
							answer = 8;
						}

					}
				}
			}
		}
	}

	return answer;
}