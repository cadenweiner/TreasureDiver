/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>

class Block : public sf::RectangleShape
{
public:
	Block(bool nLethal, int width, int x, int y);
	bool isLethal();

private:
	bool lethal;
};

