/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Block.h"

Block::Block(bool nLethal, int width, int x, int y)
{
	lethal = nLethal;
	this->setPosition(sf::Vector2f(x*width, y*width));
	this->setSize(sf::Vector2f(width, width));
}

bool Block::isLethal()
{
	return lethal;
}