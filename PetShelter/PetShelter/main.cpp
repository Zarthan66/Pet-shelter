#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Animals.h"

int main()
{
	srand(time(nullptr));
	Interface menu;
	initLocalDate();
	initLog();

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
		std::cout << "1. Get more Animals\n";
		std::cout << "2. Check Available Animals\n";
		std::cout << "3. Adopt Animals\n";
		std::cout << "4. Exit\n";

		choice = userAnswer();

		switch (choice)
		{
		case 1:
			log("Get more animals...");
			menu.newAnimals();
			menu.updateSizeArrays();
			menu.updateAnimals();
			break;
		case 2:
			log("Check available animals...");
			menu.checkAnimals();
			break;
		case 3:
			log("Adopt some animals...");
			menu.animalsAdoption();
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
