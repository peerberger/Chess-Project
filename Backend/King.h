#ifndef KING_H_
#define KING_H_

#include "Tool.h"

class King : public Tool
{
public:
	King(Location, int, bool);
	char getSymbol();
	int moveTool(string);
private:
};

#endif