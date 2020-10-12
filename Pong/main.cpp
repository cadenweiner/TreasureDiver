/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/

#include "Menu.h"

/*************************************************************
* Function:
* Date Created:
* Date Last Modified:
* Description:
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/

int main()
{
	//Test t;
	//t.testTreasurePickUp();


	sf::RenderWindow window(sf::VideoMode(704, 704), "Take a dive"); //always make window divisible evenly by 32, set ratio to window/32

	Menu m;
	Test t;
	t.testAll();
	m.run(window);
																 

	return 0;
}
