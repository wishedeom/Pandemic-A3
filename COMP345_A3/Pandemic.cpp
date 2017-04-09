// Pandemic
//
// Authored by Michael Deom - 29549641
// Submitted 17/03/2017
//
// Assignment 3 for the course COMP 345 - Advanced Program Design with C++
// with Prof. Nora Houari at Concordia University.
//
// An implementation of the board game "Pandemic" by Z-Man Games.
// Added loggers using Observer and Decorator design patterns.

//  ----    Inclusions    ----
#include <iostream>
#include <fstream>

#include "City.h"
#include "Map.h"
#include "TurnController.h"
#include "TurnLogger.h"
#include "PlayerLogger.h"
#include "StreamLogger.h"
#include "PhaseLogger.h"

Map readMapFromFile(const std::string& fileName);

//	----    Program entry point    ----  //
void main()
{
	TurnController turnController( { "Wishe", "Jonny", "Edip", "Kechun" } );
	std::ofstream fileStream("log.txt");
	auto logger =
		std::make_unique<PhaseLogger>
		(
			std::make_unique<PlayerLogger>
			(
				std::make_unique<TurnLogger>
				(
					std::make_unique<StreamLogger>(turnController, fileStream)
				),
				"Wishe"
			)
			, "Action Phase"
		);
	turnController.subscribe(*logger.get());

	turnController.playTurns(10);
}

Map readMapFromFile(const std::string& fileName)
{
	std::vector<std::string> playerNames;
	std::map<std::string, std::string> playerLocations;
	std::vector<std::string> cityNames;
	std::map<std::string, std::string> colours;
	std::map<std::string, std::vector<std::string>> connections;
	std::ifstream stream { fileName };
	if (!stream)
	{
		throw std::runtime_error { "File not found!" };
	}
	while (!stream.eof())
	{
		std::string line;
		std::getline(stream, line);
		if (line[0] == '/' || line.empty())
		{
			// Skip comments started with "/" or blank lines
			continue;
		}
		else if (line.back() == ':')
		{
			playerNames.push_back(line.substr(0, line.size() - 1));
		}
		else if (line.front() == '@')
		{
			playerLocations[playerNames.back()] = line.substr(1);
		}
		else if (line[0] == '\t')
		{
			connections[cityNames.back()].push_back(line.substr(1));
		}
		else
		{
			const auto idx = line.find_last_of(' ');
			const auto cityName = line.substr(0, idx);
			const auto colour = line.substr(idx + 1);
			cityNames.push_back(cityName);
			connections[cityName];
			colours[cityName] = colour;
		}
	}
	stream.close();

	Map map(fileName);

	// Add cities
	for (const auto& pair : connections)
	{
		const auto& name = pair.first;
		map.addCity(std::make_unique<City>(name, stringToColour(colours[name])));
	}

	// Add connections
	for (const auto& pair : connections)
	{
		auto& source = map.city(pair.first);
		for (const auto& targetName : pair.second)
		{
			auto& target = map.city(targetName);
			source.connectTo(target);
		}
	}

	return map;
}
