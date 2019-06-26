#include "Animals.h"

void Animals::print_identity()
{
    if(isMale==true)
    {
        std::cout <<"Gender: "<< "Male\n";
    }
    else
    {
        std::cout <<"Gender: "<< "female\n";
    }

    std::cout << "Price: "<<price<<std::endl;
    std::cout << "type: "<< type <<std:: endl;

}
void Dogs::speak()
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
		else if (emotion == "Peacefull")
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

void Cats::speak()
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
		else if (emotion == "Peacefull")
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

void Rabbits::speak()
{
	if (isSick == true)
	{
		std::cout << "...\n";
	}
	else
	{
		if (emotion == "Crazy")
		{
			std::cout << "\n";
		}
		else if (emotion == "Aggresive")
		{
			std::cout << "\n";
		}
		else if (emotion == "Peacefull")
		{
			std::cout << "\n";
		}
		else if (emotion == "Calm")
		{
			std::cout << "\n";
		}
		else if (emotion == "")
		{
			std::cout << "\n";
		}
		else
		{
			std::cout << "Error, undefined emotion\n";
		}
	}
}

void Birds::speak()
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
		else if (emotion == "Peacefull")
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


