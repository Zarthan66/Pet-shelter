#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Animals.h"

//	Bugs, duplicate information when assign the animal arrays from the database (At Adoption Function)

int main()
{
	srand(time(nullptr));
	Interface menu;

	// Initialize the log, created and reset automatically when run the program.
	std::ofstream initLog("PetShelter.log", std::ios::trunc | std::ios::out);

	if (initLog.is_open())
	{
		// Disable warning, _CRT_SECURE_NO_WARNINGS
		#pragma warning(disable : 4996);

		auto start{ std::chrono::system_clock::now() };
		std::time_t date{ std::chrono::system_clock::to_time_t(start) };
		initLog << "Log created at " << std::ctime(&date) << std::endl;
		initLog.close();
	}
	else
	{
		std::cout << "Error, failed to create the log file\n";
	}

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
			log("Create new animals...");
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
