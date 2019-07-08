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

	// Initialize the arrays size
	menu.updateSizeArrays();

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
		std::cout << "4. Exit\n";

		choice = userAnswer();

		switch (choice)
		{
		case 1:
			std::cout << "=========================\n";
			std::cout << "       New Animals       \n";
			std::cout << "=========================\n";
			menu.newAnimals();
			menu.updateSizeArrays();
			menu.updateAnimals();
			break;
		case 2:
			/*
				Bugs will appear when the arrays are empty
			*/
			std::cout << "=========================\n";
			std::cout << " Check Available Animals \n";
			std::cout << "=========================\n";
			menu.updateSizeArrays();
			menu.updateAnimals();
			menu.checkAnimals();
			break;
		case 3:
			std::cout << "=========================\n";
			std::cout << "      Adopt Animals      \n";
			std::cout << "=========================\n";
			//menu.animalsAdoption();
			std::cout << "Function are not ready!!\n";
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
