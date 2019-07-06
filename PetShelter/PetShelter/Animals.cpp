#include "Animals.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

void Animals::printIdentity()
{
	std::cout << "===========================================\n";
	std::cout << "Type\t\t: " << subspecies << "\n";

	if (age <= 0)
		std::cout << "Age\t\t: Under one year \n";
	else
		std::cout << "Age\t\t: " << age << "\n";

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

void Dogs::speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (personality == "Crazy")
		{
			std::cout << "Rrrrrgggghh BARK BARK BARK BARK!!! Rrrrggghhh BARK!!\n";
		}
		else if (personality == "Aggresive")
		{
			std::cout << "Rrrrrgggghh Bark Bark!!\n";
		}
		else if (personality == "Peaceful")
		{
			std::cout << "Bark Bark Bark!\n";
		}
		else if (personality == "Lazy")
		{
			std::cout << "ZzzZzzZzz..\n";
		}
		else
		{
			std::cout << "Error, undefined personality\n";
		}
	}
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

void Cats::speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (personality == "Crazy")
		{
			std::cout << "Shrrriiieekkk, (Growl)..\n";
		}
		else if (personality == "Aggresive")
		{
			std::cout << "Shriek...\n";
		}
		else if (personality == "Peaceful")
		{
			std::cout << "Meow Meow!\n";
		}
		else if (personality == "Lazy")
		{
			std::cout << "ZzzZzzZzz..\n";
		}
		else
		{
			std::cout << "Error, undefined personality\n";
		}
	}
}

void Rabbits::speak()
{
	std::cout << "....\n";
}

void Birds::speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (personality == "Crazy")
		{
			std::cout << "CUIIIIIT CUIIIIIIIITTTTTTT\n";
		}
		else if (personality == "Aggresive")
		{
			std::cout << "CUIIIT CUIIIT\n";
		}
		else if (personality == "Peaceful")
		{
			std::cout << "Cuit cuit cuit cuit\n";
		}
		else if (personality == "Lazy")
		{
			std::cout << "cuit\n";
		}
		else
		{
			std::cout << "Error, undefined personality\n";
		}
	}
}

void Interface::newAnimals()
{
	// Variable to create an object based on their type
	std::string type;
	std::string subspecies;
	std::string personality;
	bool adopted;
	bool isMale;
	bool isSick;
	int age;
	int speed;

	int totalAnimal{ 0 };
	std::cout << "How much animal do you want?\n\n";
	totalAnimal = userAnswer();

	for (int i = 1; i <= totalAnimal; i++)
	{
		int choices;
		bool restart{ true };
		while (restart == true)
		{
			std::cout << "What type do you want for the animal number " << i << ".\n";
			std::cout << "1. Dog\n";
			std::cout << "2. Cat\n";
			std::cout << "3. Rabbit\n";
			std::cout << "4. Bird\n\n";

			choices = userAnswer();

			switch (choices)
			{
			case 1:
				type = "Dog";
				restart = false;
				break;
			case 2:
				type = "Cat";
				restart = false;
				break;
			case 3:
				type = "Rabbit";
				restart = false;
				break;
			case 4:
				type = "Bird";
				restart = false;
				break;
			default:
				std::cout << "Please try again, make sure you choose one of the options.\n";
				break;
			}
		}

		generateData(type, subspecies, personality, isMale, isSick, age, speed);

		std::cout << "Information about the Animal number " << i << "\n";
		std::cout << "=============================================\n";
		std::cout << "Type\t\t: " << subspecies << "\n";

		if (age <= 0)
			std::cout << "Age\t\t: Under one year \n";
		else
			std::cout << "Age\t\t: " << age << "\n";

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
		int price{ userAnswer() };

        // ofstream untuk membuat file txt yang menampung data hewan, setiap kelas hewan mempunyai file nya masing-masing
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
		}
		else
		{
			std::cout << "Database could not be opened for saving the data!\n";
			exit(1);
		}

		/*////////////////////////////////////////////////////////////////
			Unused method, ignore this but don't delete it
		//////////////////////////////////////////////////////////////////

		For Dog type
		if (choices == 1)
		{
			//Dogs dog(subspecies, personality, isMale, isSick, age, speed, price);
			file.open("Dogs.txt", std::ios::app);
			file << subspecies << "\n"<< personality <<"\n"<< isMale <<"\n"<< isSick <<"\n"<< age <<"\n"<< speed <<"\n"<< price ;
			file.close();
		}
		// For Cat type
		else if (choices == 2)
		{
			file.open("Cats.txt", std::ios::app);
			file << subspecies <<"\n"<< personality <<"\n"<< isMale <<"\n"<< isSick <<"\n"<< age <<"\n"<< speed <<"\n"<< price ;
			file.close();
		}
		// For Rabbit type
		else if (choices == 3)
		{
			file.open("Rabbits.txt", std::ios::app);
			file << subspecies <<"\n"<< personality <<"\n"<< isMale <<"\n"<< isSick <<"\n"<< age <<"\n"<< speed <<"\n"<< price ;
			file.close();
		}
		// For Bird type
		else if (choices == 4)
		{
			file.open("Birds.txt", std::ios::app);
			file << subspecies <<"\n"<< personality <<"\n"<< isMale <<"\n"<< isSick <<"\n"<< age <<"\n"<< speed <<"\n"<< price ;
			file.close();
		}
		*/
	}
}

void Interface::checkAnimals()
{
	for (int i = 0; i < dogs.size(); i++)
	{
		dogs[i]->printIdentity();
	}

	for (int i = 0; i < cats.size(); i++)
	{
		cats[i]->printIdentity();
	}

	for (int i = 0; i < rabbits.size(); i++)
	{
		rabbits[i]->printIdentity();
	}

	for (int i = 0; i < birds.size(); i++)
	{
		birds[i]->printIdentity();
	}
    /*//////////////////////////////////////////////////////
		Unused method, ignore this but don't delete it
	////////////////////////////////////////////////////////

		// membaca file Dogs.txt
		data.open("Dogs.txt");
		if (data.is_open())
        {
            std::cout << "Dogs Data" << std::endl;
            std::cout << "======================" << std::endl;
                // memakai getline untuk mengambil data species ysng memiliki spaci seperti "Liberian Husky"
                while(getline(data,subspecies) && data >> personality >> isMale >> isSick >> age >> speed >> price )
                {
                    Dogs dog (subspecies, personality, isMale, isSick, age, speed, price);
                    dog.printIdentity();
                    std::cout << "\n";

                }
                   data.close();
        }

        // membaca file Cats.txt
        data.open("Cats.txt");
		if (data.is_open())
        {
            std::cout << "Cats Data" << std::endl;
            std::cout << "======================" << std::endl;
                while(getline(data,subspecies) && data >> personality >> isMale >> isSick >> age >> speed >> price )
                {
                    Cats cat (subspecies, personality, isMale, isSick, age, speed, price);
                    cat.printIdentity();
                    std::cout << "\n";

                }
                   data.close();
        }

        //// membaca file Rabbits.txt
        data.open("Rabbits.txt");
		if (data.is_open())
        {
            std::cout << "Rabbits Data" << std::endl;
            std::cout << "======================" << std::endl;
                while(getline(data,subspecies) && data >> personality >> isMale >> isSick >> age >> speed >> price )
                {
                    Rabbits rabbit (subspecies, personality, isMale, isSick, age, speed, price);
                    rabbit.printIdentity();
                    std::cout << "\n";

                }
                   data.close();
        }

        //mwmbaca file birds.txt
        data.open("Birds.txt");
		if (data.is_open())
        {
            std::cout << "Birds Data" << std::endl;
            std::cout << "======================" << std::endl;
                while(getline(data,subspecies) && data >> personality >> isMale >> isSick >> age >> speed >> price )
                {
                    Birds bird(subspecies, personality, isMale, isSick, age, speed, price);
                    bird.printIdentity();
                    std::cout << "\n";

                }
                   data.close();
				   
        }
		*/
		
}

/* 
// belum di perbarui, untuk sementara fungsi ini belum bisa di pake , masih code lama masih make vector
void Interface::animalsAdoption()
{
	int answer;
	std::cout << "1. Animals Adoption \n";
	std::cout << "2. See Animals Adopted \n";
	std::cout << "Choice: ";
	std::cin >> answer;

	switch (answer)
	{
	case 1:
		int choices;
		std::cout << "1. Dog\n";
		std::cout << "2. Cat\n";
		std::cout << "3. Rabbit\n";
		std::cout << "4. Bird\n\n";
		std::cout << "What kind of animal do you want to adoption: ";
		std::cin >> choices;

		if (choices == 1 && !dogs.empty())
		{
			int random = rand() % dogs.size();
			dogsAdopted.push_back(dogs[random]);
			dogs.erase(dogs.begin() + random);
		}
		else if (choices == 2 && !cats.empty())
		{
			int random = rand() % cats.size();
			catsAdopted.push_back(cats[random]);
			cats.erase(cats.begin() + random);
		}
		else if (choices == 3 && !rabbits.empty())
		{
			int random = rand() % rabbits.size();
			rabbitsAdopted.push_back(rabbits[random]);
			rabbits.erase(rabbits.begin() + random);
		}
		else if (choices == 4 && !birds.empty())
		{
			int random = rand() % birds.size();
			birdsAdopted.push_back(birds[random]);
			birds.erase(birds.begin() + random);
		}
		else
		{
			std::cout << "There is no Animals Available or Incorrect Choice!" << std::endl;
		}
	case 2:
		if (!dogsAdopted.empty())
		{
			std::cout << "Dogs Data" << std::endl;
			std::cout << "======================" << std::endl;
			std::vector<Dogs>::iterator it;

			for (it = dogsAdopted.begin(); it != dogsAdopted.end(); ++it)
			{
				it->printIdentity();
				std::cout << std::endl;
			}

			if (!catsAdopted.empty())
			{
				std::cout << "Cats Data" << std::endl;
				std::cout << "======================" << std::endl;
				std::vector<Cats>::iterator it;

				for (it = catsAdopted.begin(); it != catsAdopted.end(); ++it)
				{
					it->printIdentity();
					std::cout << std::endl;
				}
			}

			if (!rabbitsAdopted.empty())
			{
				std::cout << "Rabbits Data" << std::endl;
				std::cout << "======================" << std::endl;
				std::vector<Rabbits>::iterator it;

				for (it = rabbitsAdopted.begin(); it != rabbitsAdopted.end(); ++it)
				{
					it->printIdentity();
					std::cout << std::endl;
				}
			}
			if (!birdsAdopted.empty())
			{
				std::cout << "Birds Data" << std::endl;
				std::cout << "======================" << std::endl;
				std::vector<Birds>::iterator it;

				for (it = birdsAdopted.begin(); it != birdsAdopted.end(); ++it)
				{
					it->printIdentity();
					std::cout << std::endl;
				}
			}
		}
	}
}
*/

int userAnswer()
{
/*  This methode have some beneffit to avoid some bug
	But also cause some bug while on the loop

	std::string answer{"0"};
	std::cout << "Answer: ";
	getline(std::cin, answer);
	std::cout << std::endl;
	std::cin.sync();
	return stoi(answer);
*/

	int answer{ 0 };
	std::cout << "Answer: ";
	std::cin >> answer;
	std::cout << std::endl;
	return answer;
}

void generateData(std::string& type, std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed)
{
	// List of subspecies based on their type
	std::string subspeciesDogs[5] = { "Bulldog", "Siberian Husky", "Doberman", "Rottweiler", "Chihuahua" };
	std::string subspeciesCats[5] = { "Persian", "Toyger", "Munchkin", "Angora", "Birman" };
	std::string subspeciesRabbits[5] = { "Stain", "Deilenaar", "Fuzzy Lop", "Cottontail", "Rex" };
	std::string subspeciesBirds[5] = { "Lovebird", "Parakeet", "Owl", "Parrot", "Starling" };

	// Subspecies section
	if (type == "Dog")
	{
		subspecies = subspeciesDogs[rand() % 5];
	}
	else if (type == "Cat")
	{
		subspecies = subspeciesCats[rand() % 5];
	}
	else if (type == "Rabbit")
	{
		subspecies = subspeciesRabbits[rand() % 5];
	}
	else if (type == "Bird")
	{
		subspecies = subspeciesBirds[rand() % 5];
	}
	else
	{
		std::cout << "Error, the type are undifined.\n";
	}

	// Personality section
	std::string availablePersonality[4] = { "Aggresive", "Peacefull", "Crazy", "Lazy" };
	personality = availablePersonality[rand() % 4];

	// Gender section
	isMale = rand() % 1;

	// Health condition section
	isSick = rand() % 1;

	// Age and Speed section
	int maxSpeed;
	int minSpeed;

	if (type == "Dog")
	{
		age = rand() % 15;
		maxSpeed = 36;
		minSpeed = 15;
	}
	else if (type == "Cat")
	{
		age = rand() % 15;
		maxSpeed = 30;
		minSpeed = 18;
	}
	else if (type == "Rabbit")
	{
		age = rand() % 10;
		maxSpeed = 25;
		minSpeed = 10;
	}
	else if (type == "Bird")
	{
		age = rand() % 5;
		maxSpeed = 40;
		minSpeed = 20;
	}
	else
	{
		std::cout << "Error, the type are undifined.\n";
		maxSpeed = 0;
		minSpeed = 0;
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
	else
	{
		int range{ maxSpeed - minSpeed + 1 };
		speed = rand() % range + minSpeed;
	}
}

void Interface::updateSizeArrays()
{
	std::ifstream load("AnimalDatabase.bin", std::ios::app);
	
	if (load.is_open())
	{
		while (load)
		{
			std::string type;
			getline(load, type);
			if (type == "Dog")
				++dogTotal;
			else if (type == "Cat")
				++catTotal;
			else if (type == "Rabbit")
				++rabbitTotal;
			else if (type == "Bird")
				++birdTotal;
		}
	}
	else
	{
		std::cout << "Can't open the database to update the total of animals\n";
		exit(1);
	}
}

void Interface::updateAnimals()
{
	std::ifstream load("AnimalDatabase.bin", std::ios::app);

	if (load.is_open())
	{
		// to get the right objects while updating it from the database
		int dogIndex{ 0 };
		int catIndex{ 0 };
		int rabbitIndex{ 0 };
		int birdIndex{ 0 };

		// temporary variables
		std::string type{ "Dog" };
		std::string subspecies{ "Siberian Husky" };
		std::string personality{ "Peacefull" };
		bool isMale{ true };
		bool isSick{ false };
		int price{ 0 };
		int age{ 0 };
		int speed{ 0 };

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

			if (type == "Dog")
			{
				if (dogs.size() < dogTotal)
					dogs.push_back(new Dogs(subspecies, personality, isMale, isSick, age, speed, price));
				else
					dogs[dogIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				dogIndex++;
			}
			else if (type == "Cat")
			{
				if (cats.size() < catTotal)
					cats.push_back(new Cats(subspecies, personality, isMale, isSick, age, speed, price));
				else
					cats[catIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				catIndex++;
			}
			else if (type == "Rabbit")
			{
				if (rabbits.size() < rabbitTotal)
					rabbits.push_back(new Rabbits(subspecies, personality, isMale, isSick, age, speed, price));
				else
					rabbits[rabbitIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				rabbitIndex++;
			}
			else if (type == "Bird")
			{
				if (birds.size() < birdTotal)
					birds.push_back(new Birds(subspecies, personality, isMale, isSick, age, speed, price));
				else
					birds[birdIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				birdIndex++;
			}
			else
			{
				std::cout << "Something went wrong while updating the animals\n";
				exit(1);
			}
		}
	}
	else
	{
		std::cout << "Can't open the database to update the animals\n";
		exit(1);
	}
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		Unused method, ignore this but don't delete it
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// If didn't used getline on type, a bug can be occured
			getline(load, type);
			getline(load, subspecies);
			load >> personality;
			load >> isMale;
			load >> isSick;
			load >> age;
			load >> speed;
			load >> price;

			using namespace animalArrays;

			if (type == "Dog")
			{
				if (dogs.size() > dogIndex)
					dogs[dogIndex]->push_back(new Dogs(subspecies, personality, isMale, isSick, age, speed, price));
				else
					dogs[dogIndex]->newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				dogIndex++;
			}
			else if (type == "Cat")
			{
				cats[catIndex].newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				catIndex++;
			}
			else if (type == "Rabbit")
			{
				rabbits[rabbitIndex].newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				rabbitIndex++;
			}
			else if (type == "Bird")
			{
				birds[birdIndex].newIdentity(subspecies, personality, isMale, isSick, age, speed, price);
				birdIndex++;
			}
			else
			{
				std::cout << "Something went wrong while refreshing" << std::endl;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/