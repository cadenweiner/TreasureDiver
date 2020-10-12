/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Test.h"

void Test::testAll()
{
	this->testCoralConstruct();
	this->testDecrementLives();
	this->testSharkSwim();
	this->testJellyfishSwim();
	this->testTreasurePickUp();
	this->testEnemyCollision();
}

void Test::testCoralConstruct()
{
	cout << "test coral Construct results: " << endl;
	Coral c(1, 1, 32); //location should be x =32, y =32, with width and height 32.
	if (c.getPosition().x == 32 && c.getPosition().y == 32 && c.getSize().x == 32 && c.getSize().y == 32)
	{
		cout << "\tCoral correctly constructed" << endl;
	}
	else
	{
		cout << "\tCoral NOT constructed correctly" << endl;
		if (c.getPosition().x != 32)
			cout << "\tx position not set correctly" << endl;
		if (c.getPosition().y != 32)
			cout << "\ty position not set correctly" << endl;
		if (c.getSize().x != 32)
			cout << "\tx size not set correctly" << endl;
		if (c.getSize().y != 32)
			cout << "\ty size not set correctly" << endl;
	}

}

void Test::testDecrementLives()
{
	cout << "Test Decrement Lives Results: " << endl;
	Lives hearts(32);
	//lose first life
	hearts.decrementLives();
	if (hearts.getLives() == 2)
	{
		cout << "\tfirst life decremented properly" << endl;
	}
	else
	{
		cout << "\tfirst NOT decremented properly" << endl;
	}
	hearts.decrementLives();
	if (hearts.getLives() == 1)
	{
		cout << "\tsecond life decremented properly" << endl;
	}
	else
	{
		cout << "\tsecond life NOT decremented properly" << endl;
	}
	hearts.decrementLives();
	if (hearts.getLives() == 0)
	{
		cout << "\tlast life decremented properly" << endl;
	}
	else
	{
		cout << "\tlast life NOT decremented properly" << endl;
	}

}

void Test::testSharkSwim()
{
	cout << "Test shark swim Results: " << endl;
	Shark bob(4, 4, 32);
	Block *corals[2];
	corals[0] = new Coral(2, 4, 32); //directly to shark's right
	corals[1] = new Coral(5, 4, 32); //directly to shark's left
	sf::Vector2f initial = bob.getPosition();

	bob.swim(corals, 2); //not colliding, so moves to right
	if (bob.getPosition().x > initial.x)
	{
		cout << "\tshark swim correctly moved shark to the right" << endl;
	}
	else
	{
		cout << "\tShark swim did NOT correctly move shark to the right" << endl;
	}
	bob.swim(corals, 2); //has collided, so moves left
	if (bob.getSpeed() == -2)
	{
		cout << "\tShark swim correctly changed direction from right to left" << endl;
	}
	else
	{
		cout << "\tShark swim did NOT correctly change direction from right to left" << endl;
	}

	initial = bob.getPosition();
	bob.swim(corals, 2); //won't collide so continues so move left
	if (bob.getPosition().x < initial.x)
	{
		cout << "\tshark swim correctly moved shark to the left" << endl;
	}
	else
	{
		cout << "\tShark swim did NOT correctly move shark to the left" << endl;
	}
}

void Test::testJellyfishSwim()
{
	cout << "Test jellyfish swim Results: " << endl;
	Jellyfish bob(4, 4, 32);
	Block *corals[2];
	corals[0] = new Coral(4, 5, 32); //directly to shark's right
	corals[1] = new Coral(4, 3, 32); //directly to shark's left
	sf::Vector2f initial = bob.getPosition();

	bob.swim(corals, 2); //not colliding, so moves to right
	if (bob.getPosition().y > initial.y)
	{
		cout << "\tjellyfish swim correctly moved jellyfish downwards" << endl;
	}
	else
	{
		cout << "\tjellyfish swim did NOT correctly move shark downwards" << endl;
	}
	bob.swim(corals, 2); //has collided, so moves left
	if (bob.getSpeed() == -1)
	{
		cout << "\tjellyfish swim correctly changed direction from down to up" << endl;
	}
	else
	{
		cout << "\tjellyfish swim did NOT correctly change direction from down to up" << endl;
	}

	initial = bob.getPosition();
	bob.swim(corals, 2); //won't collide so continues so move left
	if (bob.getPosition().y < initial.y)
	{
		cout << "\tjellyfish swim correctly moved shark up" << endl;
	}
	else
	{
		cout << "\tjellyfish swim did NOT correctly move up" << endl;
	}
}

void Test::testTreasurePickUp()
{
	cout << "Test treasure pick-up Results:" << endl;
	//make normal level of game
	sf::Texture texture;
	texture.loadFromFile("All_Critters.png");
	ifstream CoralIn("corals.txt"), EnemiesIn("enemies.txt"), TreasureIn("Treasure.txt");
	Level level1(CoralIn, EnemiesIn, TreasureIn, 32, texture);
	CoralIn.close();
	EnemiesIn.close();
	TreasureIn.close();

	//make diver
	Diver dude(sf::Vector2f(32, 26));
	//move diver to know location of treasure on the map
	dude.setPosition(32, 32 * 15);

	if (dude.diverTreasureCollision(level1))
	{
		cout << "\tDiver treasure collision detection successful" << endl;
	}
	else
	{
		cout << "\tDiver treasure collison NOT detected when collided" << endl;
	}
}

void Test::testEnemyCollision()
{
	cout << "Test enemy collision Results:" << endl;
	//make normal level of game
	sf::Texture texture;
	texture.loadFromFile("All_Critters.png");
	ifstream CoralIn("corals.txt"), EnemiesIn("enemies.txt"), TreasureIn("Treasure.txt");
	Level level1(CoralIn, EnemiesIn, TreasureIn, 32, texture);
	CoralIn.close();
	EnemiesIn.close();
	TreasureIn.close();

	//make diver
	Diver dude(sf::Vector2f(32, 26));
	//move diver to know location of enemy on the map
	dude.setPosition(32 * 11, 32 * 6);

	if (dude.enemyCollision(level1))
	{
		cout << "\tDiver enemy collision detection successful" << endl;
	}
	else
	{
		cout << "\tDiver enemy collison NOT detected when collided" << endl;
	}
}
