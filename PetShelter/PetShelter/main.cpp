#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Animals.h"

int main()
{
	// To avoid the object get the same emotion
	srand(time(NULL));

	Interface menu;

	bool exitProgram{ false };
	while (exitProgram == false)
	{
		int choice{ 0 };
		std::cout << "=========================\n";
		std::cout << "       Pet Shelter       \n";
		std::cout << "=========================\n";
		std::cout << "1. New Animals\n";
		std::cout << "2. Check Available Animals\n";
		std::cout << "3. Adopt Animals\n";
		std::cout << "4. Exit\n\n";

		choice = userAnswer();

		switch (choice)
		{
		case 1:
			std::cout << "=========================\n";
			std::cout << "       New Animals       \n";
			std::cout << "=========================\n";
			menu.newAnimals();
			break;
		case 2:
			std::cout << "=========================\n";
			std::cout << " Check Available Animals \n";
			std::cout << "=========================\n";
			menu.checkAnimals();
			break;
		case 3:
			std::cout << "=========================\n";
			std::cout << "      Adopt Animals      \n";
			std::cout << "=========================\n";
			menu.animalsAdoption();
			break;
		case 4:
			exitProgram = true;
			break;
		default:
			std::cout << "Please try again, make sure you choose one of the options.\n";
			break;
		}
	}
}
