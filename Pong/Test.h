/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Diver.h"
#include "Level.h"
#include "Lives.h"
#define RATIO 22
#include <SFML/Audio.hpp>

using std::cout;
using std::endl;

class Test
{
public:
	void testAll();

private:
	void testCoralConstruct();
	void testDecrementLives();
	void testSharkSwim();
	void testJellyfishSwim();
	void testTreasurePickUp();
	void testEnemyCollision();
};
