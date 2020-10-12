/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#include "Block.h"

class Enemy :public Block
{
public:
	Enemy(double nSpeed, int width, int x, int y) :Block(true, width, x, y) { speed = nSpeed; direction = 1;};
	bool collision(Block **coral_locations, int numCoral); //can't pass in level because level relies on enemy class
	virtual void swim(Block **coral_locations, int numCoral) = 0;

	int getSpeed();
	void setSpeed(int nSpeed);
	float getDirection();
	void flipDirection();
private:
	double speed; //changed speed to a double because 1 is moving very fast, but they don't move at all with decimel values
	float direction;
};

