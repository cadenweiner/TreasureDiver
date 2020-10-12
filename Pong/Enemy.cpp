/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Enemy.h"
bool Enemy::collision(Block **coral_locations, int numCoral)
{
	bool hit = false;
	for (int i = 0; i < numCoral; ++i)
	{
		hit = this->getGlobalBounds().intersects(coral_locations[i]->getGlobalBounds());
		if (hit == true)
		{
			i = numCoral; //to exit for loop
		}
	}

	return hit;
}

int Enemy::getSpeed()
{
	return speed;
}
void Enemy::setSpeed(int nSpeed)
{
	speed = nSpeed;
}
float Enemy::getDirection()
{
	return direction;
}
void Enemy::flipDirection()
{
	this->direction = -direction;
}