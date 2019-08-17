#include "DataProvider.h"
#include <fstream>
#include <chrono>
#include <ctime>

namespace date
{
	std::string day, month, year, localTime;
}

namespace directory
{
	std::string log, database;
}

void log(std::string message)
{
	//Disable warning, _CRT_SECURE_NO_WARNINGS
	#pragma warning(disable : 4996);

	time_t now{ time(0) };
	char buf[80];
	struct tm time { *localtime(&now) };

	strftime(buf, sizeof(buf), "%X", &time);

	std::ofstream log(directory::log, std::ios::app);

	if (log.is_open())
	{
		log << "[" << buf << "] " << message << std::endl;
		log.close();
	}
	else
	{
		std::cout << "Error, failed to open the log file\n";
	}
}

void initLocalDate()
{
	//Disable warning, _CRT_SECURE_NO_WARNINGS
	#pragma warning(disable : 4996);

	time_t now{ time(0) };
	char buf[80];
	struct tm time { *localtime(&now) };

	using namespace date;

	strftime(buf, sizeof(buf), "%d", &time);
	day = buf;

	strftime(buf, sizeof(buf), "%m", &time);
	month = buf;

	strftime(buf, sizeof(buf), "%Y", &time);
	year = buf;

	// Set the local time with format hours.minutes.seconds
	strftime(buf, sizeof(buf), "%H", &time);
	localTime += buf;

	strftime(buf, sizeof(buf), ".%M", &time);
	localTime += buf;

	strftime(buf, sizeof(buf), ".%S", &time);
	localTime += buf;
}

void initLog()
{
	using namespace date;
	using namespace directory;

	directory::log = "Pet-shelter-" + year + "." + month + "." + day + "-" + localTime + ".log";
	std::ofstream initLog(directory::log, std::ios::app);

	if (initLog.is_open())
	{
		// Disable warning, _CRT_SECURE_NO_WARNINGS
		#pragma warning(disable : 4996);

		auto start{ std::chrono::system_clock::now() };
		std::time_t date{ std::chrono::system_clock::to_time_t(start) };
		initLog << "Log created at " << std::ctime(&date) << std::endl;
		initLog.close();
	}
	else
	{
		std::cout << "Error, failed to create the log file\n";
	}
}