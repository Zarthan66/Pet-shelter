#pragma once
#include <iostream>
#include <vector>

// Available animal types for this program
namespace animal
{
	namespace types
	{
		extern const std::string Dog, Cat, Rabbit, Bird;
	}
	namespace personality
	{
		extern const std::string Aggresive, Peacefull, Grumpy, Lazy;
	}
};

// A simple class for all animals
class Animals
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
	// Animals will speak based on their condition and personality
	virtual void speak() = 0;

	// Print the details about the animals, included their condition and information
	void printIdentity();

	// Get new information about the animals
	void newIdentity(std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed, int& price);

	// Assign the animal to the database
	void assignToDatabase();
};

class Dogs : public Animals
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

class Cats : public Animals
{
public:
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

class Rabbits : public Animals
{
public:
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

class Birds : public Animals
{
public:
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



