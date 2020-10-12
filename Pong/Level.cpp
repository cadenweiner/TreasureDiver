/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Level.h"

Level::Level(ifstream &ncoral_file, ifstream& nenemy_file, ifstream& ntreasure_file, int width, sf::Texture &texture)
{
	// Read in the corals and dynamically allocate 
	// Put them into array
	int x;
	int y;
	string line;
	int index = 0;

	while (!nenemy_file.eof())
	{
		// Read from 
		std::getline(nenemy_file, line, '\t');
		x = stoi(line);
		std::getline(nenemy_file, line, '\t');
		y = stoi(line);
		std::getline(nenemy_file, line, '\n');
		if (line == "s")
		{
			this->enemy_locations[index] = new Shark(x, y, width);
			this->enemy_locations[index]->setTexture(&texture);
			this->enemy_locations[index]->setTextureRect(sf::IntRect(33, 0, 32, 32));
		}
		else if (line == "j")
		{
			this->enemy_locations[index] = new Jellyfish(x, y, width);
			this->enemy_locations[index]->setTexture(&texture);
			this->enemy_locations[index]->setTextureRect(sf::IntRect(65, 0, 32, 32));
		}
		index++;
	}
	numEnemies = index;
	index = 0;
	while (!ncoral_file.eof())
	{
		// Read from 
		std::getline(ncoral_file, line, '\t');
		x = stoi(line);
		std::getline(ncoral_file, line, '\n');
		y = stoi(line);

		this->coral_locations[index] = new Coral(x, y, width);
		this->coral_locations[index]->setTexture(&texture);
		this->coral_locations[index]->setTextureRect(sf::IntRect(0, 0, 32, 32));
		index++;
	}
	numCoral = index;
	index = 0;
	while (!ntreasure_file.eof())
	{
		// Read from 
		std::getline(ntreasure_file, line, '\t');
		x = stoi(line);
		std::getline(ntreasure_file, line, '\n');
		y = stoi(line);
		this->treasure_locations[index] = new Treasure(x, y, width);
		this->treasure_locations[index]->setTexture(&texture);
		this->treasure_locations[index]->setTextureRect(sf::IntRect(0, 33, 32, 32));
		index++;
	}
	numTreasure = index;

}


void Level::drawCoralEnemiesTreasure(sf::RenderWindow& window)
{
	//draw every coral
	for (int i = 0; i < numCoral; ++i)
	{
		window.draw(*coral_locations[i]);
	}
	//draw every enemy
	for (int i = 0; i < numEnemies; ++i)
	{
		window.draw(*enemy_locations[i]);
	}
	//draw treasure
	for (int i = 0; i < numTreasure; ++i)
	{
		window.draw(*treasure_locations[i]);
	}
}

int Level::getCoralCount()const
{
	return numCoral;
}

Block *const*Level::getCoralArrayStart()const
{
	return coral_locations;
}

void Level::makeEnemiesSwim()
{
	//for every enemy
	for (int i = 0; i < numEnemies; ++i)
	{
		enemy_locations[i]->swim(coral_locations, numCoral);
	}
}

int Level::getEnemyCount()const
{
	return numEnemies;
}
Enemy *const* Level::getEnemyArrayStart()const
{
	return enemy_locations;
}

int Level::getTreasureCount()const
{
	return numTreasure;
}

Treasure *const*Level::getTreasureArrayStart()const
{
	return treasure_locations;
}
