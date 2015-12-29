/*
	This header file is a part from Chess project by:
		Yehuda Chikvashvili
		Meny Menasherov
		Pe'er Berger
	
	Tile class implementation code.
*/

#include "Tile.h"


Tile::Tile ( Location location, Tool* tool )
	:_location ( location ), _tool ( tool )
{
}


Tile::~Tile ()
{
	this->_location = "";
	this->setTool ( nullptr );
}


bool Tile::isOccupied () const
{
	return (this->_tool != nullptr);
}


Location Tile::getLocation () const
{
	return this->_location;
}


Tool* Tile::getTool () const
{
	if ( this == nullptr )
	{
		return nullptr;
	}
	return this->_tool;
}

char Tile::getToolSymbol () const
{
	if ( this->_tool == nullptr )
	{
		return '#';
	}
	
	return this->_tool->getSymbol ();
}

void Tile::setLocation ( Location location )
{
	this->_location = location;
}


void Tile::setTool ( Tool* tool )
{
	if ( this->_tool != nullptr )
	{
		delete this->_tool;
	}

	this->_tool = tool;
}