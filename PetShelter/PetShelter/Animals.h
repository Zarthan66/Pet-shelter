#pragma once
#include <iostream>
#include <vector>

// Available animal types for this program
namespace animal
{
	namespace types
	{
		const std::string Dog{ "Dog" }, Cat{ "Cat" }, Rabbit{ "Rabbit" }, Bird{ "Bird" };
	}
	namespace personality
	{
		const std::string Aggresive{ "Aggresive" }, Peacefull{ "Peacefull" }, Grumpy{ "Grumpy" }, Lazy{ "Lazy" };
	}
};


// A simple class for all animals
struct Animals
{
protected:
	std::string type;
	std::string subspecies;
	std::string personality;
	bool isMale;
	bool isSick;
	int age; // in month
	int speed; // mph
	int price; // USD

public:
	// Print the details about the animals, included their condition and information
	void printIdentity();
	// Animals will speak based on their condition and personality
	virtual void speak() = 0;
	// Get new information about the animals
	void newIdentity(std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed, int& price);
	// Assign the animal to the database
	void assignToDatabase();
};

struct Dogs : public Animals
{
public:
	Dogs(std::string subspecies, std::string personality = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->type = animal::types::Dog;
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
		this->type = animal::types::Cat;
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
		this->type = animal::types::Rabbit;
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
		this->type = animal::types::Bird;
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

	// available animals to adopted
	std::vector<std::unique_ptr<Dogs>>dogs;
	std::vector<std::unique_ptr<Cats>>cats;
	std::vector<std::unique_ptr<Rabbits>>rabbits;
	std::vector<std::unique_ptr<Birds>>birds;

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

// Get an answer from the user and return it as an integer
int userAnswer();

// Give some information for the animals automatically
void generateData(std::string& type, std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed);

// Returns a random int that is better than rand
int randGenerator(int min, int max);

// A log feature, to know the current process and error messages
void log(std::string message);


