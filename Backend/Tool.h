/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tool:
		An abstract class which represents a chess game instrument.
		The tool can be found on the board and also can be moved to other location on the board.
*/

#ifndef TOOL_H_
#define TOOL_H_

#include <string>

using namespace std;

typedef string Location;

class Board;


class Tool
{
	public:

	/**
	The class constructor.
	There is a check of location validity.
	Invalid location will throw an exception.

	Input:
		The location on the board which is represented as a string, the firse character represents the coloumn as lower alphabet (a-h)
																	the secon character represents the row as a number (1-8)
		On board state, boolean variable (set true to default value)
	*/
	Tool ( Location location, bool onBoard = true )
		:_onBoard ( onBoard )
	{
		if ( location.length () != 2 || location [ 0 ] > 'h' || location [ 0 ] < 'a' || location [ 1 ]> '8' || location [ 1 ] < '1' )
		{ //Is the given location invalid?
			string err = "Invalid location: ";
			err += location;
			throw exception ( err.c_str () );
		}

		this->_location = location;
	}


	/**
	The location getter.

	Input:
		None.
	
	Output:
		The instance's location, represented as a string (Note the constuctor).
	*/
	Location getLocation ( void )
	{
		return this->_location;
	}


	/**
	On board state setter.

	Input:
		The new On board state, represented as boolean variable.

	Output:
		None.
	*/
	void setOnBoard ( bool onBoard )
	{
		this->_onBoard = onBoard;
	}


	/**
	On board state getter.

	Input:
		None.

	Output:
		The current on board state, represented as a boolean variable.
	*/
	bool getOnBoard ( void )
	{
		return this->_onBoard;
	}


	
	//The derived classes whould implement the following two methods:
	

	/**
	Move the tool to another location on the board.
	The returned value is due the following rules:
		0:	Valid move, the tool has been moved.
		1:	----------------||-----------------, and also, the rival king is currently threatened by this tool.
		2:	Invalid move, trying to move NULL tool.
		3:	Invalid move, friendly tool at the destination location.
		4:	Invalid move, the move will threat the own king.
		5:	Invalid move, source or destination locations are out of the board.
		6:	Invalid move, the tool has no ability to move the destination location.
		7:	Invalid move, source and destination locations are the same location.
		8:	Valid move, CHECK-MATE! (Bonus)
	*/
	virtual int moveTool ( Location ) = 0;


	/*
	Get this tool character representation on the board:
		k:	king
		q:	queen
		r:	rook
		n:	knight
		b:	bishop
		p:	pawn
		#:	empty tile
		
		Lower case charcters represent black tools while the upper case represent white tools.
	*/
	virtual char getSymbol ( void ) = 0;
	
	protected:
	Board* _board;
	Location _location;
	bool _onBoard;
};

#endif