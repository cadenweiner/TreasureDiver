/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Lives.h"

void Lives::setUpHeart(sf::ConvexShape& heart, int blockwidth)
{
	heart.setPointCount(6);
	heart.setPoint(0, sf::Vector2f(blockwidth / 4, 0));
	heart.setPoint(1, sf::Vector2f(blockwidth / 2, blockwidth / 4));
	heart.setPoint(2, sf::Vector2f(blockwidth - blockwidth / 4, 0));
	heart.setPoint(3, sf::Vector2f(blockwidth, blockwidth / 4));
	heart.setPoint(4, sf::Vector2f(blockwidth / 2, blockwidth));
	heart.setPoint(5, sf::Vector2f(0, blockwidth / 4));
	heart.setOutlineColor(sf::Color(200, 10, 10));
	heart.setOutlineThickness(4);
	heart.setFillColor(sf::Color(200, 10, 10));
}

Lives::Lives(int blockwidth)
{
	lives = 3;
	this->setUpHeart(heart1, blockwidth);
	this->setUpHeart(heart2, blockwidth);
	this->setUpHeart(heart3, blockwidth);
	heart1.setPosition(32 * 17, 8);
	heart2.setPosition(32 * 18 + 16, 8);
	heart3.setPosition(32 * 20, 8);
}

int Lives::getLives()
{
	return lives;
}

void Lives::decrementLives()
{
	lives--;
	switch (lives)
	{
	case 2: //lost first heart
		heart1.setFillColor(sf::Color::Transparent);
		break;
	case 1: //lost second heart
		heart2.setFillColor(sf::Color::Transparent);
		break;
	case 0: //lost last heart
		heart3.setFillColor(sf::Color::Transparent);
		break;
	}

}

void Lives::drawLives(sf::RenderWindow& window)
{
	window.draw(heart1);
	window.draw(heart2);
	window.draw(heart3);
}