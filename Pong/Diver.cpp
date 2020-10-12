/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Diver.h"

Diver::Diver(sf::Vector2f size)
{
	this->setPosition(size.x / 2, size.y*6.5);
	this->setSize(size);
}

bool Diver::diverCoralCollision(Level &l)
{
	bool hit = false;
	for (int i = 0; i < l.getCoralCount(); ++i)
	{
		hit = this->getGlobalBounds().intersects(l.getCoralArrayStart()[i]->getGlobalBounds());
		if (hit == true)
		{
			i = l.getCoralCount(); //to exit for loop
		}
	}
	return hit;
}

bool Diver::enemyCollision(Level &l)
{
	bool hit = false;
	for (int i = 0; i < l.getEnemyCount(); ++i)
	{
		hit = this->getGlobalBounds().intersects(l.getEnemyArrayStart()[i]->getGlobalBounds());
		if (hit == true)
		{
			break;
		}
	}
	return hit;
}

bool Diver::diverTreasureCollision(Level &l)
{
	bool hit = false;
	for (int i = 0; i < l.getTreasureCount(); ++i)
	{
		hit = this->getGlobalBounds().intersects(l.getTreasureArrayStart()[i]->getGlobalBounds());
		if (hit == true)
		{
			l.getTreasureArrayStart()[i]->move(1000, 0); //moving treasure off of screen

			i = l.getTreasureCount(); //to exit for loop
		}
	}
	return hit;
}
