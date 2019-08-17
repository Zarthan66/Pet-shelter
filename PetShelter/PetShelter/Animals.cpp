#include "Animals.h"
#include "DataProvider.h"
#include <string>
#include <fstream>
#include <random>
#include <chrono>

// Available animal types for this program
namespace animal
{
	namespace types
	{
		const std::string Dog = "Dog", Cat = "Cat", Rabbit = "Rabbit", Bird = "Bird";
	}
	namespace personality
	{
		const std::string Aggresive = "Aggresive", Peacefull = "Peacefull", Grumpy = "Grumpy", Lazy = "Lazy";
	}
};

void Dogs::speak()
{
	log("A dog were speaking");
	std::cout << "(Animal Voice) ";

	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		using namespace animal::personality;

		if (personality == Grumpy)
		{
			std::cout << "Rrrrrgggghh BARK BARK BARK BARK!!! Rrrrggghhh BARK!!\n";
		}
		else if (personality == Aggresive)
		{
			std::cout << "Rrrrrgggghh Bark Bark!!\n";
		}
		else if (personality == Peacefull)
		{
			std::cout << "Bark Bark Bark!\n";
		}
		else if (personality == Lazy)
		{
			std::cout << "ZzzZzzZzz..\n";
		}
		else
		{
			log("Error, undefined personality");
		}
	}
}

void Cats::speak()
{
	log("A cat were speaking");
	std::cout << "(Animal Voice) ";

	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		using namespace animal::personality;

		if (personality == Grumpy)
		{
			std::cout << "Shrrriiieekkk..\n";
		}
		else if (personality == Aggresive)
		{
			std::cout << "Shriek...\n";
		}
		else if (personality == Peacefull)
		{
			std::cout << "Meow Meow!\n";
		}
		else if (personality == Lazy)
		{
			std::cout << "Meow..\n";
		}
		else
		{
			log("Error, undefined personality");
		}
	}
}

void Rabbits::speak()
{
	log("A rabbit were speaking");
	std::cout << "(Animal Voice) ...\n";
}

void Birds::speak()
{
	log("A bird were speaking");
	std::cout << "(Animal Voice) ";

	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		using namespace animal::personality;

		if (personality == Grumpy)
		{
			std::cout << "CUIIIIIT CUIIIIIIIITTTTTTT\n";
		}
		else if (personality == Aggresive)
		{
			std::cout << "CUIIIT CUIIIT\n";
		}
		else if (personality == Peacefull)
		{
			std::cout << "Cuit cuit cuit cuit\n";
		}
		else if (personality == Lazy)
		{
			std::cout << "cuit\n";
		}
		else
		{
			log("Error, undefined personality");
		}
	}
}

void Animals::printIdentity()
{
	log("Print the " + subspecies + " identity");
	std::cout << "===========================================\n";
	std::cout << "Subspecies\t: " << subspecies << "\n";

	if (age <= 0)
		std::cout << "Age\t\t: Under one years old\n";
	else
		std::cout << "Age\t\t: " << age << " years old\n";

	std::cout << "Gender\t\t: ";
	isMale == true ?
		std::cout << "Male" :
		std::cout << "Female";
	std::cout << "\n";

	std::cout << "Condition\t: ";
	isSick == true ?
		std::cout << "Sick" :
		std::cout << "Fine";
	std::cout << "\n";

	std::cout << "Speed\t\t: " << speed << " mph\n";
	std::cout << "Stats\t\t: " << personality << "\n";
	std::cout << "Price\t\t: " << price << " $\n";
	std::cout << "===========================================\n";
}

void Animals::newIdentity(std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed, int& price)
{
	this->subspecies = subspecies;
	this->personality = personality;
	this->isMale = isMale;
	this->isSick = isSick;
	this->age = age;
	this->speed = speed;
	this->price = price;
}

int userAnswer()
{
/*
	// This methode have some beneffit to avoid incorrect input
	// But also cause some bug while on the loop and poor perfomance
	std::string answer;
	std::cout << "Answer: ";
	getline(std::cin, answer);
	std::cin.ignore();
	std::cin.sync();
	std::cout << std::endl;
	return stoi(answer);
*/
	log("Waiting for the user input");

	int answer{ 0 };
	std::cout << "\nAnswer: ";
	std::cin >> answer;
	std::cin.ignore();
	std::cout << std::endl;
	return answer;
}

void generateData(std::string& type, std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed)
{
	log("Generating the identity for the animal");

	using namespace animal;

	// Subspecies section
	if (type == types::Dog)
	{
		std::string subspeciesDogs[5] = { "Bulldog", "Siberian Husky", "Doberman", "Rottweiler", "Chihuahua" };
		subspecies = subspeciesDogs[randGenerator(0, 4)];
	}
	else if (type == types::Cat)
	{
		std::string subspeciesCats[5] = { "Persian", "Toyger", "Munchkin", "Angora", "Birman" };
		subspecies = subspeciesCats[randGenerator(0, 4)];
	}
	else if (type == types::Rabbit)
	{
		std::string subspeciesRabbits[5] = { "Satin", "Deilenaar", "Fuzzy Lop", "Cottontail", "Rex" };
		subspecies = subspeciesRabbits[randGenerator(0, 4)];
	}
	else if (type == types::Bird)
	{
		std::string subspeciesBirds[5] = { "Lovebird", "Parakeet", "Owl", "Parrot", "Starling" };
		subspecies = subspeciesBirds[randGenerator(0, 4)];
	}
	else
	{
		log("Error, undefined animal type");
		exit(1);
	}

	// Personality section
	std::string availablePersonality[4] =
	{
		personality::Aggresive,
		personality::Grumpy,
		personality::Lazy,
		personality::Peacefull
	};
	personality = availablePersonality[randGenerator(0, 3)];

	// Gender section
	isMale = randGenerator(0, 1);

	// Health condition section
	isSick = randGenerator(0, 1);

	// Age and Speed section
	int maxSpeed;
	int minSpeed;

	if (type == types::Dog)
	{
		age = randGenerator(0, 15);
		maxSpeed = 36;
		minSpeed = 15;
	}
	else if (type == types::Cat)
	{
		age = randGenerator(0, 15);
		maxSpeed = 30;
		minSpeed = 18;
	}
	else if (type == types::Rabbit)
	{
		age = randGenerator(0, 10);
		maxSpeed = 25;
		minSpeed = 10;
	}
	else if (type == types::Bird)
	{
		age = randGenerator(0, 5);
		maxSpeed = 40;
		minSpeed = 20;
	}
	else
	{
		log("Error, undefined animal type");
		exit(1);
	}

	// Decrease the speed if the age still under one year or two year
	if (age == 0)
	{
		maxSpeed = 6;
		minSpeed = 3;
	}
	else if (age == 1)
	{
		maxSpeed = 9;
		minSpeed = 6;
	}

	speed = randGenerator(minSpeed, maxSpeed);
}

int randGenerator(int min, int max)
{	
	//std::random_device random;
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

void Animals::assignToDatabase()
{
	std::ofstream save(directory::database, std::ios::app);

	if (save.is_open())
	{
		log("Add the " + subspecies + " to AnimalDatabase.bin");
		save << this->type << "\n";
		save << this->subspecies << "\n";
		save << this->personality << "\n";
		save << this->isMale << "\n";
		save << this->isSick << "\n";
		save << this->age << "\n";
		save << this->speed << "\n";
		save << this->price << "\n";
		save.close();
	}
	else
	{
		log("Error, database failed to open when trying to save the data!");
		exit(1);
	}
}



