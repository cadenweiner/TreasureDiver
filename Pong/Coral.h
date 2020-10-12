/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once

#include "Block.h"

class Coral : public Block
{
public:
	Coral(int x, int y, int width) :Block(false, width, x, y) {};
private:
	int x;
	int y;
};
 