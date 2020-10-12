/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include "Coral.h"
#include "JellyFish.h"
#include "Shark.h"
#include "Treasure.h"
using std::string;
using std::ifstream;

class Level
{
public:
	Level(ifstream &ncoral_file, ifstream& nenemy_file, ifstream& ntreasure_file, int width, sf::Texture &texture);
	void drawCoralEnemiesTreasure(sf::RenderWindow& window);
	void makeEnemiesSwim();
	int getCoralCount()const;
	Block *const*getCoralArrayStart()const;
	int getEnemyCount()const;
	Enemy *const*getEnemyArrayStart()const;
	int getTreasureCount()const;
	Treasure *const*getTreasureArrayStart()const;

private:
	Treasure * treasure_locations[100];
	Block * coral_locations[200];
	Enemy * enemy_locations[100];
	int numTreasure;
	int numCoral;
	int numEnemies;
};

