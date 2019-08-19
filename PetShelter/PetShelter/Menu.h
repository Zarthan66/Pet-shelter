#pragma once
#include <iostream>
#include <vector>

class Menu
{
private:
	// available animals to adopted
	std::vector<std::unique_ptr<Dogs>>dogs;
	std::vector<std::unique_ptr<Cats>>cats;
	std::vector<std::unique_ptr<Rabbits>>rabbits;
	std::vector<std::unique_ptr<Birds>>birds;

	// Total animals from Database, not array.
	int dogTotalDBase;
	int catTotalDBase;
	int rabbitTotalDBase;
	int birdTotalDBase;

public:
	// create an animal and add it to the database
	void newAnimals();

	// delete the animal from animal arrays
	void animalsAdoption();

	// check current available animals
	void checkAnimals();

	// count every animal type on AnimalDatabase.bin to update the size of animal arrays
	void updateSizeArrays();

	// Syncronize the animal arrays with the database
	void updateAnimals();

	// Syncronize the database with the animal arrays
	void updateDatabase();
};