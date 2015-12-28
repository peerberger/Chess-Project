#ifndef ROOK_H_
#define ROOK_H_

#include "Tool.h"
#include "Board.h"

class Rook : public Tool
{
public:
	Rook(Location ,int, bool);
	char getSymbol();
	int moveTool(string);
private:

};
#endif