#pragma once
#include <iostream>
#include <vector>

// A simple class for all animals
struct Animals
{
protected:
	bool adopted;
	bool isMale;
	bool isSick;
	int price; // USD
	int age; // in month
	int speed; // mph
	std::string subspecies;
	std::string personality;

public:
	// Print the details about the animals, included their condition and information
	void printIdentity();
	// Animals will speak based on their condition and personality
	virtual void speak() = 0;
	// Get new information about the animals
	void newIdentity(std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed, int& price);
};

struct Dogs : public Animals
{
public:
	Dogs(std::string subspecies, std::string personality = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->subspecies = subspecies;
		this->personality = personality;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;
	}
	void speak();
};

struct Cats : public Animals
{
	Cats(std::string subspecies, std::string personality = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->subspecies = subspecies;
		this->personality = personality;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;
	}
	void speak();
};

struct Rabbits : public Animals
{
	Rabbits(std::string subspecies, std::string personality = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->subspecies = subspecies;
		this->personality = personality;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;
	}
	void speak();
};

struct Birds : public Animals
{
	Birds(std::string subspecies, std::string personality = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->subspecies = subspecies;
		this->personality = personality;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;
	}
	void speak();
};

class Interface
{
private:
	// Total animals from Database
	int dogTotalDBase;
	int catTotalDBase;
	int rabbitTotalDBase;
	int birdTotalDBase;

	// animals available to adopted
	std::vector<Dogs*>dogs;
	std::vector<Cats*>cats;
	std::vector<Rabbits*>rabbits;
	std::vector<Birds*>birds;

	//Animals were adopted
    std::vector<Dogs*>dogsAdopted;
    std::vector<Cats*>catsAdopted;
   	std::vector<Rabbits*>rabbitsAdopted;
	std::vector<Birds*>birdsAdopted;



public:
	// to get new animal
    void newAnimals();

	// to Animals adoption by random
    void animalsAdoption();

	// check current available animals
    void checkAnimals();

	// count every animal type on AnimalDatabase.bin to update the size of animal arrays
	void updateSizeArrays();

	// reading database to updating the animals
	void updateAnimals();

};

// Get an answer from the user and return it as an integer
int userAnswer();

// Give some information for the animals automatically
void generateData(std::string& type, std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed);

// Returns a random int that is better than rand
int randGenerator(int min, int max);



