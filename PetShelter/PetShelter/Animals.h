#pragma once
#include <iostream>
#include <vector>

// A simple class for all animals
struct Animals
{
protected:
	bool adopted ;
	bool isMale;
	bool isSick;
	float price; // USD
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
	Dogs(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, float price = 0)
	{
		this->type = type;
		this->emotion = emotion;
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
	Cats(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, float price = 0)
	{
		this->type = type;
		this->emotion = emotion;
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
	Rabbits(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, float price = 0)
	{
		this->type = type;
		this->emotion = emotion;
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

struct Birds : public Animals
{
	Birds(std::string type, std::string emotion = "", bool isMale = true, bool isSick = false, int age = 5, int speed = 10, float price = 0)
	{
		this->type = type;
		this->emotion = emotion;
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

struct MainProgram
{
	// animals available
    std::vector<Dogs>dogs;
    std::vector<Cats>cats;
    std::vector<Rabbits>rabbits;
    std::vector<Birds>birds;
    //Animals was adopted
    std::vector<Dogs>dogsAdopted;
    std::vector<Cats>catsAdopted;
    std::vector<Rabbits>rabbitsAdopted;
    std::vector<Birds>birdsAdopted;

    public:
	// menu() to main menu of program
    void menu();

	//newAnimals for make data to Animals
    void newAnimals();

	// to Animals adoption by random
    void animalsAdoption();

	//display() to display all data
    void display();
};

