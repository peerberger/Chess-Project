/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Board:
		A class that represents the chess playing board.
		The board is a container of 64 (8 x 8) tiles.
		The board can convert the current game state into string of 66 characters.
		Board can also operate a player's movement on itself and return the movement status (Refer to Tool moveTool function documentation).
*/

#ifndef BOARD_H_
#define BOARD_H_

#include "Tile.h"

/*
	TODO:
		Include all the Tool deriving classes header fils.
*/

class Board
{
	public:

	/**
	Add documentation here.
	*/
	Board ( int );
	~Board ();

	string getBoard () const;

	int play ( string );


	private:
	Tile* _tiles [ 8 ] [ 8 ];
	int _currPlayer;
};

#endif