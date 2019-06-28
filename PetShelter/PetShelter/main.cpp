#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Animals.h"

int main()
{
	// To avoid the object get the same emotion
	srand(time(NULL));

	MainProgram a;
	a.menu();
}
