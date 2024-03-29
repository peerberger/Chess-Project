/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tile class implementation code.
*/

#include "Board.h"
#include "Rook.h"
#include "Queen.h"
//For Debbuging:
#include <iostream>

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
			buffer [ 0 ] = j + 'a';
			buffer [ 1 ] = i + '1';
			buffer [ 2 ] = '\0';
			this->_tiles [ i ] [ j ] = new Tile ( string (buffer), nullptr );
		}
	this->_tiles [ 2 ] [ 7 ]->setTool ( new Rook ( "h3", 0, true ) );


	//this->_tiles [ 0 ] [ 0 ]->setTool ( new Rook ( "a1", 0, true ) ); // White rook at a1
	//this->_tiles [ 0 ] [ 7 ]->setTool ( new Rook ( "h1", 0, true ) ); // White rook at h1

	//this->_tiles [ 7 ] [ 0 ]->setTool ( new Rook ( "a8", 1, true ) ); // Black rook at a8
	//this->_tiles [ 7 ] [ 7 ]->setTool ( new Rook ( "h8", 1, true ) ); // Black rook at h8

	//this->_tiles [ 0 ] [ 4 ]->setTool ( new Queen ( "e1", 0, true ) ); // White queen at e1
	//this->_tiles [ 7 ] [ 3 ]->setTool ( new Queen ( "d8", 1, true ) ); // Black queen at d8

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
	for ( int i = 7; i >= 0; i-- )
		for ( int j = 0; j < 8; j++ )
		{
			board += this->_tiles [ i ] [ j ]->getToolSymbol ();
		}
	board += "0";
	return board;
}


Tile* Board::getTile ( string tile ) const
{
	// "h3" -> [2][7]
	int tileJ = tile[0] - 'a';
	int tileI = tile[1] - '1';

	return this->_tiles [ tileI ] [ tileJ ];
}


int Board::play ( string move )
{
	if ( commandLengthCheck ( move ) )
	{
		return 5; // Invalid tiles indexes -> the input string length is invalid
	}
	
	cout << "Command length is valid" << endl;

	string src = move.substr ( 0, 2 );
	string dst = move.substr ( 2 );
	
	if ( tileIndexCheck ( src ) || tileIndexCheck ( dst ) )
	{
		return 5;
	}

	cout << "Command indexes are fine" << endl;

	if ( src == dst )
	{
		return 7; //source tile and destination tile are equal
	}

	cout << "Source and destination tiles are different" << endl;


	Tile* from = this->getTile ( src );
	Tile* to = this->getTile ( dst );
	
	if ( toolOwnerCheck ( from->getToolSymbol () , this->_currPlayer ))
	{
		return 2; // Source tile has no tool which belongs to the current player
	}

	cout << "Source tile conatains one of the current player's tools" << endl;

	
	if ( !toolOwnerCheck ( to->getToolSymbol (), this->_currPlayer ) )
	{
		return 3;
	}
	
	cout << "Destination tile does not contain one of the current player's tools" << endl;


	if ( 0 /* Check if the owner king is threatened */ ) //ToDo King..
	{
		return 4;
	}

	cout << "The current player's king would not be threatened by this move" << endl;


	int answer = from->getTool ()->moveTool ( move );

	if ( answer == 0 )
	{
		cout << "The tool move is valid " << endl;

		if ( 0 /* Check if the rival king is threatened */ ) //ToDo King..
		{
			answer = 1;

			if ( 0 /* Check if the rival king can't move*/ )
			{
				answer = 8;
			}

		}

		//Prevent a memory leak
		if ( to->getTool () != nullptr )
		{
			delete to->getTool ();
		}

		to->setTool ( from->getTool () ); //updating the dst tile.
		from->setTool ( nullptr );

		//Updating dst tile + currPlayer
		if (this->_currPlayer == 0)
		{
			this->_currPlayer = 1;
		}
		else
		{
			this->_currPlayer = 0;
		}
		//this->_currPlayer = !this->_currPlayer; // Change the current player
	}
	else
		cout << "The tool move is not valid" << endl;

	return answer;
}


bool commandLengthCheck ( string move )
{
	return move.length() != 4;
}


bool tileIndexCheck ( string tile )
{
	return ( tile [ 0 ] < 'a' || tile [ 0 ] > 'h' || tile [ 1 ] <'1' || tile [ 1 ] > '8' );
}


bool toolOwnerCheck ( char symbol, int player )
{
	//WTF?
	// I'm glad that you asked:
	//	Instead of using 'if's, this expression says that 'a' would stay 'a' if player is 0, else, it is considered as 'A'
	//	Did you understand why? WOW! I Liked It. BRILLIANT!
	return
		(
		symbol < 'a' - player*( 'a' - 'A' )
		||
		symbol > 'z' - player*( 'z' - 'Z' )
		);
}