#include "Animals.h"
#include <cstdlib>

void Animals::PrintIdentity()
{
	std::cout << "Type \t: " << type << "\n";
	std::cout << "Age \t: " << age << " years old\n";
	
	std::cout << "Gender \t: ";
	isMale == true ? 
		std::cout << "Male" :
		std::cout << "Female";
	std::cout << "\n";

	std::cout << "Speed \t: " << speed << " km/h\n";
	std::cout << "Stats \t: " << emotion << "\n";
	std::cout << "Price \t: " << price << " USD\n";
}

std::string Animals::EmotionalGenerator()
{
	std::string availableEmotion[5] = { "Calm", "Aggresive", "Peacefull", "Crazy", "Lazy" };	
	return availableEmotion[rand() % 5];
}

void Dogs::Speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (emotion == "Crazy")
		{
			std::cout << "Rrrrrgggghh BARK BARK BARK BARK!!! Rrrrggghhh BARK!!\n";
		}
		else if (emotion == "Aggresive")
		{
			std::cout << "Rrrrrgggghh Bark Bark!!\n";
		}
		else if (emotion == "Peaceful")
		{
			std::cout << "Bark Bark Bark!\n";
		}
		else if (emotion == "Calm")
		{
			std::cout << "Bark\n";
		}
		else if (emotion == "Lazy")
		{
			std::cout << "ZzzZzzZzz..\n";
		}
		else
		{
			std::cout << "Error, undefined emotion\n";
		}
	}
}

void Cats::Speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (emotion == "Crazy")
		{
			std::cout << "Shrrriiieekkk, (Growl)..\n";
		}
		else if (emotion == "Aggresive")
		{
			std::cout << "Shriek...\n";
		}
		else if (emotion == "Peaceful")
		{
			std::cout << "Meow Meow Meow!\n";
		}
		else if (emotion == "Calm")
		{
			std::cout << "Mew mew..\n";
		}
		else if (emotion == "Lazy")
		{
			std::cout << "ZzzZzzZzz..\n";
		}
		else
		{
			std::cout << "Error, undefined emotion\n";
		}
	}
}

void Rabbits::Speak()
{
	std::cout << "....\n";
}

void Birds::Speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (emotion == "Crazy")
		{
			std::cout << "CUIIIIIT CUIIIIIIIITTTTTTT\n";
		}
		else if (emotion == "Aggresive")
		{
			std::cout << "CUIIIT CUIIIT\n";
		}
		else if (emotion == "Peaceful")
		{
			std::cout << "Cuit cuit cuit cuit\n";
		}
		else if (emotion == "Calm")
		{
			std::cout << "cit cuiit\n";
		}
		else if (emotion == "Lazy")
		{
			std::cout << "cuit\n";
		}
		else
		{
			std::cout << "Error, undefined emotion\n";
		}
	}
}


