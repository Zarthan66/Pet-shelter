#pragma once
#include <iostream>

// A simple class for all animals
struct Animals
{
protected:
	bool adopted = false;
	bool isMale;
	bool isSick;
	int price;
	int age;
	float speed;
	std::string type;
	std::string availableEmotion[6] = { "Calm", "Aggresive", "Peacefull", "Crazy", "Lazy" };
	std::string emotion;

	// Animals speak were depended on their condition and emotion
	virtual void speak() = 0;
};

// A class for all kind of dogs
struct Dogs : public Animals
{
public:
	Dogs(bool isMale, int price, std::string type)
	{
		this->isMale = isMale;
		this->price = price;
		this->type = type;
	}

	void speak();
};

// A class for all kind of cats
struct Cats : public Animals
{
	Cats(bool isMale, int price, std::string type)
	{
		this->isMale = isMale;
		this->price = price;
		this->type = type;
	}

	void speak();
};