#include "Animals.h"
#include <cstdlib>
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

void mainProgram::menu()
{
	int choice;
	std::cout << "Welcome to Pet Shelter\n";
	std::cout <<"======================\n";
	std::cout <<"1. New Animals\n"
	                 <<"2. Available Animals\n"
	                 <<"3. Adopted Animals\n"
	                 <<"4. Exit\n\n";
	 std::cout <<"your choice: " ;
	 std::cin >>choice;

	 switch (choice)
	 {
	 	case 1:
	 	newAnimals();
	 	display();
	 	break;
	 	case 2:
       		 //display();
	 	//availableAnimals();
	 	break;
	 	case 3:
	 	//adoptedAnimals();
	 	break;
	 	case 4:
	 	exit(0);
	 	break;
	 	default:
	 	std::cout <<"please enter according to the menu";
	 	break;

	 }


}

void mainProgram::newAnimals()
{
	int choice;
	int a;
	std::cout <<"1. Dog\n"
	                <<"2. Cat\n"
	                <<"3. Rabbit\n"
	                <<"4. Bird\n\n";
   	 std::cout << "what kind of animal do you want: ";
  	 std::cin >> choice;
   	 std::cout <<"how much animal data do you want to enter: ";
  	 std::cin>> a;
  	 std::cin.ignore();


     	 for (int i = 0; i < a; i++)
         {
      //	Dogs dog;
      		std::string type;
      		int age;
      		float price;
      		int speed;
      		std::string gender;
      		std::string sick;
      		bool isMale;
      		bool isSick;

      		std::cout <<"Data Animal "<<i <<":\n";
      		std::cout <<"=======================\n";
      		std::cout <<"Type: " ;
      		getline(std::cin, type);
       		std::cout <<"Age : ";
		std::cin>>age;
          	std::cout <<"Price (USD) : ";
          	std::cin>>price;
          	std::cout <<"Speed : ";
          	std::cin>>speed;
          	std::cout <<"Gender (male/female): ";
          	std::cin>> gender;
          	std::cout <<"Condition (sick/fine) : ";
          	std::cin>>sick;
          	std::cin.ignore();
         	std::cout << std::endl;

         	 gender == "male" ? isMale = true : isMale = false;
         	 sick == "sick" ? isSick = true : isSick = false;

      		if(choice ==1)
		{
      	  		 Dogs dog(type,isMale,isSick, age, speed, price);
          		 dogs.push_back(dog);
      		}
      		else if (choice ==2)
      		{
      			Cats cat(type,isMale,isSick, age, speed, price);
            		cats.push_back(cat);
      		}
      			else if (choice ==3)
      		{
      		Rabbits rabbit(type,isMale,isSick, age, speed, price);
            	rabbits.push_back(rabbit);
      		}
      		else if (choice ==4)
      		{
      		Birds bird(type,isMale,isSick, age, speed, price);
           	birds.push_back(bird);
      		}

      	}

}

   void mainProgram::display()
   {
      //system("cls");
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

