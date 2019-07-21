#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Animals.h"

//	Bugs, duplicate information when assign the animal arrays from the database (At Adoption Function)

int main()
{
	srand(time(NULL));
	Interface menu;

	// Keep the animals syncronized with the database
	menu.updateSizeArrays();
	menu.updateAnimals();

	bool exitProgram{ false };
	while (exitProgram == false)
	{
		int choice{ 0 };
		std::cout << "=========================\n";
		std::cout << "       Pet Shelter       \n";
		std::cout << "=========================\n";
		std::cout << "1. Get new Animals\n";
		std::cout << "2. Check Available Animals\n";
		std::cout << "3. Adopt Animals\n";
		std::cout << "4. Exit\n";

		choice = userAnswer();

		switch (choice)
		{
		case 1:
			menu.newAnimals();
			menu.updateSizeArrays();
			menu.updateAnimals();
			break;
		case 2:
			menu.checkAnimals();
			break;
		case 3:
			menu.animalsAdoption();
			menu.updateSizeArrays();
			menu.updateAnimals();
			break;
		case 4:
			exitProgram = true;
			break;
		default:
			std::cout << "Please try again, make sure you choose one of the options.\n\n";
			break;
		}
	}
}
