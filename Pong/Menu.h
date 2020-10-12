#pragma once
#include "Test.h"
#include <Windows.h>
class Menu
{
public:
	// public member functions
	void run(sf::RenderWindow &window); // function that runs the entire run application

	void rungame(sf::RenderWindow &window, int success); // function that runs the game option of the menu

	
private:
	// no private member attributes 
};