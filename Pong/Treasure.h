/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once

#include "Block.h"

class Treasure : public Block
{
public:
	Treasure(int x, int y, int width) :Block(false, width, x, y) {};
	void setX(int nx);
	void setY(int ny);

private:

	int x;
	int y;
};