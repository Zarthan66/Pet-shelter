#include "Animals.h"
#include <cstdlib>
#include <string>
#include <vector>

void Animals::PrintIdentity()
{
	std::cout << "Type\t : " << type << "\n";
	std::cout << "Age\t : " << age << "\n";

	std::cout << "Gender\t : ";
	isMale == true ?
		std::cout << "Male" :
		std::cout << "Female";
	std::cout << "\n";

	std::cout << "Condition\t : ";
	isSick == true ?
		std::cout << "Sick" :
		std::cout << "Fine";
	std::cout << "\n";

	std::cout << "Speed\t : " << speed << " km/h\n";
	std::cout << "Stats\t : " << emotion << "\n";
	std::cout << "Price\t : " << price << "USD\n";
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

void MainProgram::menu()
{
    char isContinue;
    do
    {
        //system("cls");  untuk membersihkam layar jika player kembali ke menu
        int choice;
        std::cout << "Welcome to Pet Shelter\n";
        std::cout << "======================\n";
        std::cout << "1. New Animals\n";
        std::cout << "2. Animals available\n";
        std::cout << "3. Animals adoption\n";
        std::cout << "4. Exit\n\n";
        std::cout << "choice: " ;
        std::cin >> choice;

        switch (choice)
        {
                case 1:
                newAnimals();
                display();
                break;
                case 2:
                display();
                break;
                case 3:
                animalsAdoption();
                break;
                case 4:
                exit(0);
                break;
                default:
                std::cout <<"please enter according to the menu";
                break;
        }
        //do while untuk jika lanjut kembali ke menu , jiga tidak , program terhenti
        std::cout << "do you want continue(y/n): ";
        std::cin >> isContinue;
    }while (isContinue == 'y');

}

void MainProgram::newAnimals()
{
	int choice;
	int a;
	std::cout << "1. Dog\n";
	std::cout << "2. Cat\n";
	std::cout << "3. Rabbit\n";
	std::cout <<"4. Bird\n\n";
	std::cout << "what kind of animal do you want: ";
	std::cin >> choice;
	std::cout <<"how much animal data do you want to enter: ";
	std::cin >> a;
	std::cin.ignore();

	for (int i = 0; i < a; i++)
	{
		bool adopted;
		bool isMale;
		bool isSick;
		float price; // USD
		int age; // in month
		int speed; // km/h
		std::string gender; // karena isGender type data boolean , tak bisa di input male/female. jadi untuk sementara menggunakan untuk menampung inputan user
		std::string condition; // karena isSick type data boolean , tak bisa di input male/female. jadi untuk sementara menggunakan untuk menampung inputan user
		std::string type;
		std::string emotion;

		std::cout << "Data Animal " << i << ":\n";
		std::cout << "=======================\n";
		std::cout << "Type: ";
		getline(std::cin, type);
		std::cout << "Age : ";
		std::cin >> age;
		std::cout << "Speed : ";
		std::cin >> speed;
		std::cout << "Gender (male/female): ";
		std::cin >> gender;
		std::cout << "Condition (sick/fine) : ";
		std::cin >> condition;
		std::cout << "Emotional Condition: ";
		std::cin >> emotion;
		std::cout << "Price (USD) : ";
		std::cin >> price;
		std::cin.ignore();
		std::cout << std::endl;

		//ternary untuk mengubah masukan user ke tipe boolean, kalo user masukin "female" maka isMale menjadi false
		gender == "male" ? isMale = true : isMale = false;
		//ternary untuk mengubah masukan user ke tipe boolean, kalo user masukin "sick" maka isSick menjadi true
		condition == "sick" ? isSick = true : isSick = false;

		if (choice == 1)
		{
			//(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, float price = 0)
			Dogs dog(type, emotion, isMale, isSick, age, speed, price);
			dogs.push_back(dog);
		}
		else if (choice == 2)
		{
			Cats cat(type, emotion, isMale, isSick, age, speed, price);
			cats.push_back(cat);
		}
		else if (choice == 3)
		{
			Rabbits rabbit(type, emotion, isMale, isSick, age, speed, price);
			rabbits.push_back(rabbit);
		}
		else if (choice == 4)
		{
			Birds bird(type, emotion, isMale, isSick, age, speed, price);
			birds.push_back(bird);
		}
	}
}

void MainProgram::display()
{
	if(!dogs.empty())
	{
		std::cout << "Dogs Data" << std::endl;
		std::cout << "======================" << std::endl;
		std::vector<Dogs>::iterator it;

		for ( it = dogs.begin(); it != dogs.end(); ++it )
		{
		    it->PrintIdentity();
		    std::cout << std::endl;
		}
	}
	if(!cats.empty())
	{
		std::cout << "Cats Data" << std::endl;
		std::cout << "======================" << std::endl;
		std::vector<Cats>::iterator it;

		for ( it = cats.begin(); it != cats.end(); ++it )
		{
		    it->PrintIdentity();
		    std::cout << std::endl;
		}
	}
	if(!rabbits.empty())
	{
		std::cout << "Rabbits Data" << std::endl;
		std::cout << "======================" << std::endl;
		std::vector<Rabbits>::iterator it;

		for ( it = rabbits.begin(); it != rabbits.end(); ++it )
		{
		    it->PrintIdentity();
		    std::cout << std::endl;
		}
	}
	if(!birds.empty())
	{
		std::cout << "Birds Data" << std::endl;
		std::cout << "======================" << std::endl;
		std::vector<Birds>::iterator it;

		for ( it = birds.begin(); it != birds.end(); ++it )
		{
		    it->PrintIdentity();
		    std::cout << std::endl;
		}
	}
}

void MainProgram::animalsAdoption()
{
	int answer;
	std::cout << "1. Animals Adoption \n";
	std::cout << "2. See Animals Adopted \n";
	std::cout << "Choice: ";
	std::cin >> answer;

	switch (answer)
	{
	case 1:
		int choice;
		std::cout << "1. Dog\n";
		std::cout << "2. Cat\n";
		std::cout << "3. Rabbit\n";
		std::cout << "4. Bird\n\n";
		std::cout << "What kind of animal do you want to adoption: ";
		std::cin >> choice;

		if (choice == 1 && !dogs.empty())
		{
			int random = rand() % dogs.size();
			dogsAdopted.push_back(dogs[random]);
			dogs.erase(dogs.begin() + random);
		}
		else if (choice == 2 && !cats.empty())
		{
			int random = rand() % cats.size();
			catsAdopted.push_back(cats[random]);
			cats.erase(cats.begin() + random);
		}
		else if (choice == 3 && !rabbits.empty())
		{
			int random = rand() % rabbits.size();
			rabbitsAdopted.push_back(rabbits[random]);
			rabbits.erase(rabbits.begin() + random);
		}
		else if (choice == 4 && !birds.empty())
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
				it->PrintIdentity();
				std::cout << std::endl;
			}

			if (!catsAdopted.empty())
			{
				std::cout << "Cats Data" << std::endl;
				std::cout << "======================" << std::endl;
				std::vector<Cats>::iterator it;

				for (it = catsAdopted.begin(); it != catsAdopted.end(); ++it)
				{
					it->PrintIdentity();
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
					it->PrintIdentity();
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
					it->PrintIdentity();
					std::cout << std::endl;
				}
			}
		}
	}
}
