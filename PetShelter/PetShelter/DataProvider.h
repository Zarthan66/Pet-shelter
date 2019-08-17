#pragma once
#include <iostream>

namespace date
{
	extern std::string day, month, year, localTime;
}

namespace directory
{
	extern std::string log, database;
}

// Get an answer from the user and return it as an integer
int userAnswer();

// Give some information for the animals automatically
void generateData(std::string& type, std::string& subspecies, std::string& personality, bool& isMale, bool& isSick, int& age, int& speed);

// Returns a random int that is better than rand
int randGenerator(int min, int max);

// A log feature, contains a record of events.
void log(std::string message);

// Initialize the log feature.
void initLog();

// Initialize the local date.
void initLocalDate();
