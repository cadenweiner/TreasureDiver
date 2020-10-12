/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#include "Enemy.h"

class Jellyfish :public Enemy
{
public:
	Jellyfish(int x, int y, int width):Enemy(1, width, x, y) {};
	void swim(Block **coral_locations, int numCoral);

private:

};

