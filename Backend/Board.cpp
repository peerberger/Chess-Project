/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tile class implementation code.
*/

#include "Board.h"
#include "Rook.h"

// Side functions
bool commandLengthCheck ( string move );
bool tileIndexCheck ( string tile );
bool toolOwnerCheck ( char symbol, int player );



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
			board += this->_tiles [ i ] [ j ]->getToolSymbol ();
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
	if ( commandLengthCheck ( move ) )
	{
		return 5; // Invalid tiles indexes -> the input string length is invalid
	}

	string src = move.substr ( 0, 2 );
	string dst = move.substr ( 2 );
	
	if ( tileIndexCheck ( src ) || tileIndexCheck ( dst ) )
	{
		return 5;
	}

	if ( src == dst )
	{
		return 7; //source tile and destination tile are equal
	}

	Tile* from = this->getTile ( src );
	Tile* to = this->getTile ( dst );
	
	if ( toolOwnerCheck ( from->getToolSymbol () , this->_currPlayer ))
	{
		return 2; // Source tile has no tool which belongs to the current player
	}

	if ( !toolOwnerCheck ( to->getToolSymbol (), this->_currPlayer ) )
	{
		return 3;
	}

	if ( 0 /* Check if the owner king is threatened */ )
	{
		return 4;
	}

	int answer = from->getTool ()->moveTool ( dst );

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

		to->setTool ( from->getTool () );
		from->setTool ( nullptr );
		this->_currPlayer = !this->_currPlayer; // Change the current player
	}
	
	return answer;
}


bool commandLengthCheck ( string move )
{
	return move.length() != 4;
}


bool tileIndexCheck ( string tile )
{
	return ( tile [ 0 ] < 'a' || tile [ 0 ] > 'z' || tile [ 1 ] <'0' || tile [ 1 ] > '9' );
}


bool toolOwnerCheck ( char symbol, int player )
{
	return
		(
		symbol < 'a' - player*( 'a' - 'A' )
		||
		symbol > 'z' - player*( 'z' - 'Z' )
		);
}