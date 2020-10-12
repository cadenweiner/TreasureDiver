#include "Menu.h"

/*************************************************************
* Function: void Menu::run(sf::RenderWindow &window)
* Date Created: 
* Date Last Modified: 4/21/19
* Description: runs the entire game application
* Input parameters: sf::RenderWindow &window
* Returns: nothing
* Preconditions: none
* Postconditions: none 
*************************************************************/

void Menu::run(sf::RenderWindow &window)
{

	int blockWidth2 = window.getSize().x / RATIO; //calculates the width of the block to make the menu options

	sf::Font myfont; 
	sf::Text t, // text for displaying the info 
		Menu, // text for displaying the menu 
		Exit, // text for displaying the exit 
		text, // text for displaying the text on the menu
		screen2,  // text for displaying exit on the next screen
		title; // text for for displaying the title on the menu


	myfont.loadFromFile("Roboto.ttf"); // opens the file for the font


	sf::RectangleShape menuoption1(*new sf::Vector2f(blockWidth2 * 19, blockWidth2 * 3)),
		menuoption2(*new sf::Vector2f(blockWidth2 * 19, blockWidth2 * 3)),
		menuoption3(*new sf::Vector2f(blockWidth2 * 19, blockWidth2 * 3)),
		menuoption4(*new sf::Vector2f(blockWidth2 * 19, blockWidth2 * 3)); // creates 4 blocks for our menu options
	menuoption1.setFillColor(sf::Color(206, 66, 244, 120)); // fills the color to purple
	menuoption2.setFillColor(sf::Color(206, 66, 244, 120)); // fills the color to purple
	menuoption3.setFillColor(sf::Color(206, 66, 244, 120)); // fills the color to purple
	menuoption4.setFillColor(sf::Color(206, 66, 244, 120)); // fills the color to purple

	title.setFont(myfont); // sets the font
	title.setString("TAKE A DIVE!");
	title.setCharacterSize(20); // sets the character size
 	title.setFillColor(sf::Color::White); // fills the color to white
	title.setPosition(280, 0); // sets the position


	Menu.setFont(myfont); // sets the font
	Menu.setString("1. PLAY GAME"); 
	Menu.setCharacterSize(50); // sets the character size
	Menu.setFillColor(sf::Color::White); // fills the color to white
	Menu.setPosition(195, 120); // sets the position

	t.setFont(myfont); // sets the font
	t.setString("2. INFO");
	t.setCharacterSize(50); // sets the character size
	t.setFillColor(sf::Color::White); // fills the color to white
	t.setPosition(270, 320); // sets the position

	Exit.setFont(myfont); // sets the font
	Exit.setString("3. EXIT"); 
	Exit.setCharacterSize(50); // sets the character size
	Exit.setFillColor(sf::Color::White); // fills the color to white
	Exit.setPosition(270, 520); // sets the position

	text.setFont(myfont); // sets the font
	text.setString("Enter the corresponding number for each option.");
	text.setFillColor(sf::Color::White); // fills the color to white
	text.setPosition(0, 40); // sets the position
	text.setCharacterSize(20); // sets the character size

	screen2.setFont(myfont); // sets the font
	screen2.setString("4. Exit"); 
	screen2.setFillColor(sf::Color::White); // fills the color to white
	screen2.setPosition(280, 520); // sets the position
	screen2.setCharacterSize(50); // sets the character size

	menuoption1.setPosition(40, 100); // sets the position
	menuoption2.setPosition(40, 300); // sets the position
	menuoption3.setPosition(40, 500); // sets the position
	menuoption4.setPosition(40, 500); // sets the position

	
	sf::Event event;
	sf::Text instructions1, instructions2, instructions3, instructions4, 
		instructions5, instructions6, instructions7, instructions8; // text for each part of the instructions on the instructions option
	instructions1.setFont(myfont); // sets the font
	instructions2.setFont(myfont); // sets the font
	instructions3.setFont(myfont); // sets the font
	instructions4.setFont(myfont); // sets the font
	instructions5.setFont(myfont); // sets the font
	instructions6.setFont(myfont); // sets the font
	instructions7.setFont(myfont); // sets the font
	instructions8.setFont(myfont); // sets the font

	instructions1.setString("Welcome Aboard Diver:");
	instructions2.setString("-You are a diver swimming in the Coral Sea located ");
	instructions3.setString("in Australia. Your primary goal is to collect all the");

	instructions4.setString("treasure chests while trying to stay alive.");
	
	instructions5.setString("- Ways to Die:\n");
	instructions6.setString("     ~ running out of oxygen");
	instructions7.setString("     ~hitting an enemy");
	instructions8.setString("You have three lives. Use them wisely!!");
		
	instructions1.setCharacterSize(30); // sets the character size
	instructions1.setFillColor(sf::Color::White); // fills the color to white
	instructions1.setPosition(5, 0); // sets the postion

	instructions2.setCharacterSize(30); // sets the character size
	instructions2.setFillColor(sf::Color::White); // fills the color to white
	instructions2.setPosition(5, 50); // sets the position

	instructions3.setCharacterSize(30); // sets the character size
	instructions3.setFillColor(sf::Color::White); // fills the color to white
	instructions3.setPosition(5, 90); // sets the position

	instructions4.setCharacterSize(30); // sets the character size
	instructions4.setFillColor(sf::Color::White); // fills the color to white
	instructions4.setPosition(5, 130); // sets the position

	instructions5.setCharacterSize(30); // sets the character size
	instructions5.setFillColor(sf::Color::White); // fills the color to white
	instructions5.setPosition(5, 200); // sets the position

	instructions6.setCharacterSize(30); // sets the character size
	instructions6.setFillColor(sf::Color::White); // fills the color to white
	instructions6.setPosition(5, 240); // sets the position
	
	instructions7.setCharacterSize(30); // sets the character size
	instructions7.setFillColor(sf::Color::White); // fills the color to white
	instructions7.setPosition(5, 280); // sets the position

	instructions8.setCharacterSize(30); // sets the character size
	instructions8.setFillColor(sf::Color::White); // fills the color to white
	instructions8.setPosition(5, 340); // sets the position


	while (window.isOpen()) // while the window is open it will continue to run the application
	{
		int success = 0, option = 0, exit = 0, play = 0, weout = 0;
		window.clear(); // clears the screen -- required to begin
		window.draw(Menu); // draws the menu text
		window.draw(t); // draws the info text
		window.draw(Exit); // draws the exit text
		window.draw(text); // draws the text for rules text
		window.draw(title); // draws the text for the title

		window.draw(menuoption1); // draws the playgame rectangle
		window.draw(menuoption2); // draws the instructions rectangle
		window.draw(menuoption3); // draws the exit rectangle


		window.display(); // displays everything drawn

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // if the keyboard input is 1 
		{
			if (sf::Event::KeyReleased) // then as the key is released..
			{
				success = 1; // set success to 1 to begin the event corresponding to it

			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) // if the keyboard input is 2
		{ 
			if (sf::Event::KeyReleased) // then as the key is released...
			{
				option = 1; // sets  option to 1 to begin the event corresponding to it
			}

		}


		while (option == 1) // while the keyboard input of Num1 is true 
		{
			window.clear(); // clears the screen -- required to for drawing the new objects 


			window.draw(instructions1); // draws the text the instructions
			window.draw(instructions2); // draws the text the instructions
			window.draw(instructions3); // draws the text the instructions
			window.draw(instructions4); // draws the text the instructions
			window.draw(instructions5); // draws the text the instructions
			window.draw(instructions6); // draws the text the instructions
			window.draw(instructions7); // draws the text the instructions
			window.draw(instructions8); // draws the text the instructions
			window.draw(screen2); // draws the text for the exit option
			window.draw(menuoption4); // draws the rectangle for the exit


			window.display(); // displays all the objects drawn

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) // if the keyboard input is num4
			{
				if (sf::Event::KeyReleased) // then as the key is released break out of the while loop
				{
					break;
				}
			}

		}



		if (success == 1) // if the menu option entered is 1 and the play is 1 then...
		{
			rungame(window, success); // calls the rungame(window, play, success) function to run the actual game 


		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) // if the keyboard input is 3
		{
			if (sf::Event::KeyReleased) // then as the key is released...
			{
				window.clear(); // clear the screen 
				window.close(); // close the window
				break; // and break out of the loop
			}
		}
	}
}

/*************************************************************
* Function: void Menu::rungame(sf::RenderWindow &window, int success, int play)
* Date Created:
* Date Last Modified: 4/21/19
* Description: runs the game part of the menu
* Input parameters: sf::RenderWindow &window, int success, int play
* Returns: nothing
* Preconditions: none
* Postconditions: none
*************************************************************/

void Menu::rungame(sf::RenderWindow &window, int success)
{
	int blockWidth = window.getSize().x / RATIO; // calculates the block width 
	
	window.setFramerateLimit(60); 

	Diver d(sf::Vector2f(blockWidth - 2, blockWidth / 2)); // creates a diver

	int airDepth = blockWidth * 3; // calculates the amount of air space
	sf::RectangleShape air(*new Vector2f(window.getSize().x, airDepth)); // makes a rectangle for the air
	air.setFillColor(sf::Color(255, 255, 255, 200)); // fills the color 

	// Loading in texture
	sf::Texture texture; // creates a texture 
	texture.loadFromFile("All_Critters.png"); // opens the file for the critters

	d.setTexture(&texture); // sets the text for the diver
	d.setTextureRect(sf::IntRect(97, 10, 32, 22)); 
	d.setOrigin(blockWidth / 2, blockWidth / 2); // sets the the divers origin


	sf::Font font; 
	font.loadFromFile("Roboto.ttf"); // opens the file for the font type

	sf::Text deathMessage("You are dead, you lose!", font, 50); // creates a message for when you lose
	deathMessage.setFillColor(sf::Color::Black); // sets the message color to black
	deathMessage.setPosition(blockWidth * 3, blockWidth); // sets the position of the message

	sf::Text winMessage("YOU WIN!", font, 50); // creates a message for when you win
	winMessage.setFillColor(sf::Color::Black); // sets the message color to black 
	winMessage.setPosition(blockWidth * 3, blockWidth); // sets the position of the message

	sf::Text oxygenLabel("Oxygen Tank: ", font, 20); // creates a message for the oxygen tank timer
	oxygenLabel.setFillColor(sf::Color::Black); // sets the color to black
	oxygenLabel.setPosition(blockWidth * 12, blockWidth / 2); // sets the position of the message
	sf::Text countDown("40", font, 20); // creates the number count down for the timer
	countDown.setFillColor(sf::Color::Black); // sets the color to black
	countDown.setPosition(blockWidth * 15.75, blockWidth / 2); // sets the position of the message

	sf::Text TreasureLabel("Treasure Count: ", font, 20); // creates a message to keep track of the treasures
	TreasureLabel.setFillColor(sf::Color::Black); // sets the color to black
	TreasureLabel.setPosition(blockWidth * 6, blockWidth / 2); // sets the position of the treasure tracker
	sf::Text TreasureLabelNum("0", font, 20); // the treasure tracker
	TreasureLabelNum.setFillColor(sf::Color::Black); // sets the color to black
	TreasureLabelNum.setPosition(blockWidth * 10 + 16, blockWidth / 2); // position of the treasure tracker

	Lives hearts(blockWidth); // makes an instance of the hearts displayed in the game

	sf::Clock oxygen; // clock
 	int tankTime = 45; // sets the tank time for the diver underwater to 45 sec

	ifstream CoralIn("corals.txt"), EnemiesIn("enemies.txt"), TreasureIn("Treasure.txt"); // opens the files for all the objects
	Level level1(CoralIn, EnemiesIn, TreasureIn, blockWidth, texture); // makes a level with the corresponding objects and textures
	CoralIn.close(); // closes the file of the corals
	EnemiesIn.close(); // closes the file of the enemies
	TreasureIn.close(); // closes the file of the treasure

	int diverSpeed = 3; // sets the speed of the diver to 3 
	
	int treasureCount = 0; // initializes the treasure count
	treasureCount = level1.getTreasureCount(); // sets the treasure count to the level1's treasure count
	sf::Event event;

	
	while (success == 1) // if the num1 key is inputted
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // if the right key is inputted then...
		{
			// left key is pressed: move our character
			if (d.getPosition().x + d.getSize().x / 2 < window.getSize().x)  // gets the divers position (x coordinate) and size (x coordinate) to ensure he is less than the window's size
			{
				d.move(diverSpeed, 0); // let the diver move
				d.setScale({ 1,1 });
				if (d.diverCoralCollision(level1)) // checks to see if the diver collides with the coral 
				{
					d.move(-diverSpeed, 0); // if true, move diver

				}
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // if the left key is inputted then 
		{
			// left key is pressed: move our character
			if (d.getPosition().x >  d.getSize().x / 2) // get the divers position (x coordinate) and ensure it is greater than the size of the diver divided by 2
				d.move(-diverSpeed, 0); // move the diver -3, 0
			d.setScale({ -1,1 }); // set the scale
			if (d.diverCoralCollision(level1)) // check if the diver collides with the coral. if so...
			{
				d.move(diverSpeed, 0);  // if true, move the diver

			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // if the down key is inputted then...
		{
			// Down key is pressed: move our character
			if (d.getPosition().y < window.getSize().y) // get the divers position (y coordinate) and ensure it is less then the windows y coordinate
				d.move(0, diverSpeed); // if it is, then move the diver

			if (d.diverCoralCollision(level1)) // check if the diver collides with the coral
			{
				d.move(0, -diverSpeed); // if true, then move the dier

			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // if the up key is inputted then..
		{
			// Up key is pressed: move our character
			if (d.getPosition().y - d.getSize().y / 2 > airDepth) //top height is floating of water (part way into air)
				d.move(0, -diverSpeed); // move diver

			if (d.diverCoralCollision(level1)) // check is the diver collides with the coral
			{
				d.move(0, diverSpeed); // if true, move diver

			}
		}


		if (d.enemyCollision(level1)) //if hit an enemy, lose a life and send to top
		{
			d.setPosition(blockWidth / 2, blockWidth*3.25);
			hearts.decrementLives();
		}
		else if (d.diverTreasureCollision(level1)) // if the diver collides with the treasure
		{
			treasureCount--; // decrement the treasure count
			TreasureLabelNum.setString(std::to_string(level1.getTreasureCount() - treasureCount)); // then subtract the treasure count from th eget treasure 
		}
		else if (d.getPosition().y <= airDepth + blockWidth / 4) //if above water, reset oxygen
		{
			oxygen.restart(); // reset the oxygen
		}
		else if (oxygen.getElapsedTime().asSeconds() > tankTime) //if out of oxygen, lose life and send to top
		{
			d.setPosition(blockWidth / 2, blockWidth*3.25); // set the diver position
			hearts.decrementLives(); // decrement the lives
		}
		//set countdown time string
		countDown.setString(std::to_string(tankTime - (int)oxygen.getElapsedTime().asSeconds()));
		if (oxygen.getElapsedTime().asSeconds() > tankTime - 5) // check the elapsed time
		{
			//low on oxygen -- change font color to warn player
			countDown.setFillColor(sf::Color::Red); 
		}
		else // otherwise leave the color black because it isn't cutting it close yet
		{
			countDown.setFillColor(sf::Color::Black);
		}

		//drawing
		window.clear(sf::Color(9, 155, 196, 255)); // clear the screen to the color
		window.draw(air); // draw the air rectangle
		if (hearts.getLives() <= 0) // check the status of the lives -- if they're less than or equal to 0, end the game
		{
			window.draw(deathMessage); // draws message on screen
			window.display(); // displays the message
			Sleep(1200); // sleeps the screen for 20 sec
			break; // breaks out of the loop and goes back to the main menu
			
		}
		else if (treasureCount == 0) // check whether the total treasurecount is equal to 0 (meaning all the treasures were collected). if so.. the player wins
		{
			window.draw(winMessage); // draws the win message to the screen
			window.display(); // displays the message
			Sleep(1200); // sleeps  the screen for 20 sec
			break; // breaks ouf of the loop and goes back to the main menu
		}
		else // otherwise continue the game
		{
			level1.makeEnemiesSwim(); // let enemies swim
			level1.drawCoralEnemiesTreasure(window); // draw the treasures
			window.draw(d); // draw the diver
			hearts.drawLives(window); // draw the lives
			window.draw(oxygenLabel); //oxygen label
			window.draw(countDown); //oxygen label time
			window.draw(TreasureLabel); //treasure label
			window.draw(TreasureLabelNum); //treasure label number

		}
		window.display(); // display it all onto the screen

	}
}