#include "Animals.h"
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <memory>
#include <chrono>
#include <ctime>


namespace app
{
	namespace date
	{
		std::string day, month, year, localTime;
	}
	namespace log
	{
		std::string address;
	}
};

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

void Interface::newAnimals()
{
	std::cout << "=========================\n";
	std::cout << "    Get More Animals     \n";
	std::cout << "=========================\n";

	std::cout << "How much animal do you want?\n";
	std::cout << "(Insert '-1' to get back to the main menu)\n";
	int totalAnimal{ userAnswer() };

	if (totalAnimal != -1)
	{
		// Temporary variables
		std::string type;
		std::string subspecies;
		std::string personality;
		bool isMale;
		bool isSick;
		int age;
		int speed;

		for (int i = 1; i <= totalAnimal; i++)
		{
			int animalType;
			bool restart{ true };
			while (restart == true)
			{
				std::cout << "What kind of animal do you want for the animal number " << i << ".\n";
				std::cout << "1. Dog\n";
				std::cout << "2. Cat\n";
				std::cout << "3. Rabbit\n";
				std::cout << "4. Bird\n";
				std::cout << "5. Previous menu\n";

				animalType = userAnswer();

				using namespace animal::types;

				switch (animalType)
				{
				case 1:
					log("The user are trying to get more " + Dog);
					type = Dog;
					restart = false;
					break;
				case 2:
					log("The user are trying to get more " + Cat);
					type = Cat;
					restart = false;
					break;
				case 3:
					log("The user are trying to get more " + Rabbit);
					type = Rabbit;
					restart = false;
					break;
				case 4:
					log("The user are trying to get more " + Bird);
					type = Bird;
					restart = false;
					break;
				case 5:
					newAnimals();
					restart = false;
					return;
					break;
				default:
					std::cout << "Please try again, make sure you choose one of the options.\n";
					break;
				}
			}

			generateData(type, subspecies, personality, isMale, isSick, age, speed);

			std::cout << "Information about the Animal number " << i << "\n";
			std::cout << "=============================================\n";
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
			std::cout << "=============================================\n";

			std::cout << "What is the price for this animal? (USD)\n";
			std::cout << "(Insert '-1' to cancel the animal creation)\n";

			int price{ userAnswer() };

			if (price != -1)
			{
				log("Saving the animal to the database");

				std::ofstream save("AnimalDatabase.bin", std::ios::app);

				if (save.is_open())
				{
					save << type << "\n";
					save << subspecies << "\n";
					save << personality << "\n";
					save << isMale << "\n";
					save << isSick << "\n";
					save << age << "\n";
					save << speed << "\n";
					save << price << "\n";
					save.close();
				}
				else
				{
					log("Error, database failed to open when trying to save the data!");
					exit(1);
				}
			}
			else
			{
				newAnimals();
			}
		}
	}
}

void Interface::checkAnimals()
{
	std::cout << "=========================\n";
	std::cout << "    Available Animals    \n";
	std::cout << "=========================\n";

	// Total animal from database
	int totalAnimalDBase{ dogTotalDBase + catTotalDBase + rabbitTotalDBase + birdTotalDBase };

	if (totalAnimalDBase > 0)
	{
		if (dogs.size() > 0)
		{
			std::cout << "Dogs :\n";
			for (size_t i = 0; i < dogs.size(); i++)
				dogs[i]->printIdentity();

			std::cout << "\n";
		}
		if (cats.size() > 0)
		{
			std::cout << "Cats :\n";
			for (size_t i = 0; i < cats.size(); i++)
				cats[i]->printIdentity();

			std::cout << "\n";
		}
		if (rabbits.size() > 0)
		{
			std::cout << "Rabbits :\n";
			for (size_t i = 0; i < rabbits.size(); i++)
				rabbits[i]->printIdentity();

			std::cout << "\n";
		}
		if (birds.size() > 0)
		{
			std::cout << "Birds :\n";
			for (size_t i = 0; i < birds.size(); i++)
				birds[i]->printIdentity();

			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "Sorry, there are no animals are available\n\n";
	}
}

int userAnswer()
{
/*
	// This methode have some beneffit to avoid incorrect input
	// But also cause some bug while on the loop and poor perfomance
	std::string answer;
	std::cout << "Answer: ";
	getline(std::cin, answer);
	std::cout << std::endl;
	std::cin.sync();
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

void Interface::updateSizeArrays()
{
	log("Updating the arrays size");

	// Initialize the value before starting the count
	dogTotalDBase = 0;
	catTotalDBase = 0;
	rabbitTotalDBase = 0;
	birdTotalDBase = 0;

	std::ifstream load("AnimalDatabase.bin", std::ios::app);

	if (load.is_open())
	{
		while (load)
		{
			std::string type;
			getline(load, type);

			using namespace animal::types;

			if (type == Dog)
				++dogTotalDBase;
			else if (type == Cat)
				++catTotalDBase;
			else if (type == Rabbit)
				++rabbitTotalDBase;
			else if (type == Bird)
				++birdTotalDBase;
		}
		load.close();
	}
	else
	{
		log("Error, failed to open the database when trying to update the total of animals");
		exit(1);
	}
}

void Interface::updateAnimals()
{
	log("Updating the animal database");
	std::ifstream load("AnimalDatabase.bin", std::ios::in);

	if (load.is_open())
	{
		// to get the right objects while updating it from the database
		int dogIndex{ 0 };
		int catIndex{ 0 };
		int rabbitIndex{ 0 };
		int birdIndex{ 0 };

		// temporary variables
		std::string type;
		std::string subspecies;
		std::string personality;
		bool isMale;
		bool isSick;
		int price;
		int age;
		int speed;

		while (load)
		{
			getline(load, type);

			// Skip every blank input to avoid a bug
			if (type == "")
				continue;

			getline(load, subspecies);
			getline(load, personality);
			load >> isMale;
			load >> isSick;
			load >> age;
			load >> speed;
			load >> price;

			using namespace animal::types;

			// Create the animal object directly to the animal array
			if (type == Dog)
			{
				if (dogs.size() < dogTotalDBase)
					dogs.emplace_back(std::unique_ptr<Dogs>(new Dogs(subspecies, personality, isMale, isSick, age, speed, price)));
				else
					dogs[dogIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				dogIndex++;
			}
			else if (type == Cat)
			{
				if (cats.size() < catTotalDBase)
					cats.emplace_back(std::unique_ptr<Cats>(new Cats(subspecies, personality, isMale, isSick, age, speed, price)));
				else
					cats[catIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				catIndex++;
			}
			else if (type == Rabbit)
			{
				if (rabbits.size() < rabbitTotalDBase)
					rabbits.emplace_back(std::unique_ptr<Rabbits>(new Rabbits(subspecies, personality, isMale, isSick, age, speed, price)));
				else
					rabbits[rabbitIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				rabbitIndex++;
			}
			else if (type == Bird)
			{
				if (birds.size() < birdTotalDBase)
					birds.emplace_back(std::unique_ptr<Birds>(new Birds(subspecies, personality, isMale, isSick, age, speed, price)));
				else
					birds[birdIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				birdIndex++;
			}
			else
			{
				log("Error, undefined type while updating the animal");
				exit(1);
			}
			log("A " + subspecies + " has been added");
		}
		load.close();
	}
	else
	{
		log("Error, failed to open the database when trying to update the animals");
		exit(1);
	}
}

int randGenerator(int min, int max)
{	
	//std::random_device random;
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

void Interface::animalsAdoption()
{
	std::cout << "=========================\n";
	std::cout << "      Adopt Animals      \n";
	std::cout << "=========================\n";
	std::cout << "What kind of animal do you want to adopt:\n";
	std::cout << "1. Dog\n";
	std::cout << "2. Cat\n";
	std::cout << "3. Rabbit\n";
	std::cout << "4. Bird\n";
	std::cout << "5. Main menu\n";
	int animalType{ 0 };
	animalType = userAnswer();

	if (animalType != 5)
	{
		// show the animals based on the chosen animal type
		std::cout << "Information about the animals :\n";
		switch (animalType)
		{
		case 1:
			if (dogs.size() > 0)
			{
				for (size_t i = 0; i < dogs.size(); i++)
				{
					std::cout << "Dog number [" << i + 1 << "]\n";
					dogs[i]->printIdentity();
					dogs[i]->speak();
					std::cout << "\n";
				}
			}
			else
			{
				std::cout << "Currently, dogs are not available\n";
				animalsAdoption();
			}
			break;
		case 2:
			if (cats.size() > 0)
			{
				for (size_t i = 0; i < cats.size(); i++)
				{
					std::cout << "Cat number [" << i + 1 << "]\n";
					cats[i]->printIdentity();
					cats[i]->speak();
					std::cout << "\n";
				}
			}
			else
			{
				std::cout << "Currently, cats are not available.\n";
				animalsAdoption();
			}
			break;
		case 3:
			if (rabbits.size() > 0)
			{
				for (size_t i = 0; i < rabbits.size(); i++)
				{
					std::cout << "Rabbit number [" << i + 1 << "]\n";
					rabbits[i]->printIdentity();
					rabbits[i]->speak();
					std::cout << "\n";
				}
			}
			else
			{
				std::cout << "Currently, rabbits are not available.\n";
				animalsAdoption();
			}
			break;
		case 4:
			if (birds.size() > 0)
			{
				for (size_t i = 0; i < birds.size(); i++)
				{
					std::cout << "Bird number [" << i + 1 << "]\n";
					birds[i]->printIdentity();
					birds[i]->speak();
					std::cout << "\n";
				}
			}
			else
			{
				std::cout << "Currently, the birds are not available.\n";
				animalsAdoption();
			}
			break;
		default:
			std::cout << "Please try again, make sure you chose of one the options.\n";
			animalsAdoption();
		}

		bool restart{ true };
		while (restart == true)
		{
			std::cout << "Which animal you want to adopt\n";
			std::cout << "(Insert '-1' to get back to the previous menu)\n";

			int chosenAnimal{ userAnswer() };

			// Decrease value by one since the user's answer are decreased by one
			if (chosenAnimal == -1)
			{
				log("Go to the previous menu");

				// Call the function and disabled restarting to get back to the previous menu
				animalsAdoption();
				restart = false;
				return;
			}
			else
			{
				// decrement it to be an iterator for animal arrays
				--chosenAnimal;

				switch (animalType)
				{
				case 1:
					log("Adopting a dog...");
					dogs.erase(dogs.begin() + chosenAnimal);
					dogs.shrink_to_fit();
					updateDatabase();
					restart = false;
					break;
				case 2:
					log("Adopting a cat...");
					cats.erase(cats.begin() + chosenAnimal);
					cats.shrink_to_fit();
					updateDatabase();
					restart = false;
					break;
				case 3:
					log("Adopting a rabbit...");
					rabbits.erase(rabbits.begin() + chosenAnimal);
					rabbits.shrink_to_fit();
					updateDatabase();
					restart = false;
					break;
				case 4:
					log("Adopting a bird...");
					birds.erase(birds.begin() + chosenAnimal);
					birds.shrink_to_fit();
					updateDatabase();
					restart = false;
					break;
				default:
					std::cout << "Please try again, make sure you chose one of the animals\n";
				}
			}
		}
	}
}

void Animals::assignToDatabase()
{
	std::ofstream save("AnimalDatabase.bin", std::ios::app);

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

void Interface::updateDatabase()
{
	std::ofstream clear("AnimalDatabase.bin", std::ios::out | std::ios::trunc);

	// Saving all the dogs data to the database
	for (int i = 0; i < dogs.size(); i++)
		dogs[i]->assignToDatabase();

	// Saving all the cats data to the database
	for (int i = 0; i < cats.size(); i++)
		cats[i]->assignToDatabase();

	// Saving all the rabbits data to the database
	for (int i = 0; i < rabbits.size(); i++)
		rabbits[i]->assignToDatabase();

	// Saving all the birds data to the database
	for (int i = 0; i < birds.size(); i++)
		birds[i]->assignToDatabase();
}

void log(std::string message)
{
	//Disable warning, _CRT_SECURE_NO_WARNINGS
	#pragma warning(disable : 4996);

	time_t now{ time(0) };
	char buf[80];
	struct tm time{ *localtime(&now) };

	strftime(buf, sizeof(buf), "%X", &time);

	std::ofstream log(app::log::address, std::ios::app);

	if (log.is_open())
	{
		log << "[" << buf << "] " << message << std::endl;
		log.close();
	}
	else
	{
		std::cout << "Error, failed to open the log file\n";
	}
}

void initLocalDate()
{
	//Disable warning, _CRT_SECURE_NO_WARNINGS
	#pragma warning(disable : 4996);

	time_t now{ time(0) };
	char buf[80];
	struct tm time { *localtime(&now) };

	using namespace app::date;

	strftime(buf, sizeof(buf), "%d", &time);
	day = buf;

	strftime(buf, sizeof(buf), "%m", &time);
	month = buf;

	strftime(buf, sizeof(buf), "%Y", &time);
	year = buf;

	// Set the local time with format hours.minutes.seconds
	strftime(buf, sizeof(buf), "%H", &time);
	localTime += buf;
	
	strftime(buf, sizeof(buf), ".%M", &time);
	localTime += buf;
	
	strftime(buf, sizeof(buf), ".%S", &time);
	localTime += buf;
}

void initLog()
{
	using namespace app::date;
	app::log::address = "Pet-shelter-" + year + "." + month + "." + day + "-" + localTime + ".log";
	std::ofstream initLog(app::log::address, std::ios::app);

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
}

