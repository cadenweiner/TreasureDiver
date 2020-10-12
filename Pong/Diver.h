/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
using sf::Vector2f;


class Diver : public sf::RectangleShape
{
public:
	Diver(sf::Vector2f size);
	bool diverCoralCollision(Level &l);
	bool enemyCollision(Level &l);
	bool diverTreasureCollision(Level &l);

private:

};