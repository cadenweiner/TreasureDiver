/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once

#include <SFML/Graphics.hpp>

class Lives
{
public:
	Lives(int blockwidth);
	int getLives();
	void decrementLives();
	void drawLives(sf::RenderWindow& window);
private:
	void setUpHeart(sf::ConvexShape& heart, int blockwidth);

	int lives;
	sf::ConvexShape heart1;
	sf::ConvexShape heart2;
	sf::ConvexShape heart3;
};