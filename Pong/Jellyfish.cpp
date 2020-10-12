/*******************************************************************************
* Programmer: Iris Jones, John Hadish, Angela Stefoglo, Caden Weiner
* Class: CptS 122; Lab Section 12
* Programming Assignment: 9
* Date: April 20th, 2019
* Description: "Take a Dive" graphical game
******************************************************************************/
#include "Jellyfish.h"

void Jellyfish::swim(Block **coral_locations, int numCoral)
{
	if (collision(coral_locations, numCoral))
	{
		setSpeed(-getSpeed());
	}
	move(0, getSpeed());
}