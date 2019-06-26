#pragma once
#include <iostream>

// A simple class for all animals
struct Animals
{
protected:
	bool adopted = false;
	bool isMale;
	bool isSick;
	int price; // USD
	int age; // in month
	int speed; // km/h
	std::string type;
	std::string emotion;

public:
	// Print the details about the animals, included their condition and information
	void PrintIdentity();
	// Give random emotional condition if we didn't specify for it
	std::string EmotionalGenerator();
	// Animals speak were depended on their condition and emotion
	virtual void Speak() = 0;
};

struct Dogs : public Animals
{
public:
	Dogs(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->type = type;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;

		if(emotion == "")
			this->emotion = EmotionalGenerator();
	}
	void Speak();
};

struct Cats : public Animals
{
	Cats(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->type = type;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;

		if (emotion == "")
			this->emotion = EmotionalGenerator();
	}
	void Speak();
};

struct Rabbits : public Animals
{
	Rabbits(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->type = type;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;

		if (emotion == "")
			this->emotion = EmotionalGenerator();
	}	
	void Speak();
};

struct Birds :public Animals
{
	Birds(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, int price = 0)
	{
		this->type = type;
		this->isMale = isMale;
		this->isSick = isSick;
		this->age = age;
		this->speed = speed;
		this->price = price;

		if (emotion == "")
			this->emotion = EmotionalGenerator();
	}
	void Speak();
};
