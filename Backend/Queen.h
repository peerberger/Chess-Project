#ifndef QUEEN_H_
#define QUEEN_H_

#include "Tool.h"

class Queen : public Tool
{
public:
	Queen(Location, int, bool);
	char getSymbol();
	int moveTool(string);
private:

};

#endif