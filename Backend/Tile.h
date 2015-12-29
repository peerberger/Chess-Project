/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tool:
		A class that represents a tile on the chess board.
		The tile is a container for a single tool and has certain location on the board.
*/

#ifndef TILE_H_
#define TILE_H_

#include "Tool.h"

class Tile
{
	public:

	/**
	Add documentation here.
	*/
	Tile ( Location, Tool* = nullptr );
	~Tile ();

	bool isOccupied ( void ) const;

	//Getters:
	Location getLocation ( void ) const;
	Tool* getTool ( void ) const;

	char getToolSymbol ( void ) const;

	//Setters:
	void setLocation ( Location );
	void setTool ( Tool* );

	private:
	Location _location;
	Tool* _tool;
};

#endif