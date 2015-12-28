#ifndef ROOK_H_
#define ROOK_H_

#include "Tool.h"

class Rook : public Tool
{
public:
	Rook(Location ,bool);
	char getSymbol();
	int moveTool(string);
private:

};
#endif