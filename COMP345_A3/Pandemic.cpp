// Pandemic
//
// Authored by Michael Deom - 29549641
// Submitted 17/03/2017
//
// Assignment 2 for the course COMP 345 - Advanced Program Design with C++
// with Prof. Nora Houari at Concordia University.
//
// An implementation of the board game "Pandemic" by Z-Man Games.
// Added MapView observer.

//  ----    Inclusions    ----
#include <iostream>
#include <fstream>

#include "City.h"
#include "Map.h"
#include "MapView.h"
#include "TurnController.h"
#include "TurnLogger.h"
#include "PlayerLogger.h"
#include "StreamLogger.h"

Map readMapFromFile(const std::string& fileName);

//	----    Program entry point    ----  //
void main()
{
	TurnController tc { { "Wishe", "Jonny", "Edip", "Kechun" } };
	std::ofstream fs { "log.txt" };
	StreamLogger l { tc, fs };
	TurnLogger tl { l };
	PlayerLogger pl { tl, "Wishe" };
	tc.subscribe(pl);

	tc.playTurns(10);

	//// Title display
	//std::cout << "    --------    O B S E R V E R   P A T T E R N    --------\n\n\n";

	//// Setup - Construct sample map from file
	//auto map = readMapFromFile("earth.map");

	//// Construct MapView
	//MapView mapView { &map };

	//// Add a city to show off my fancy MapView
	//auto milwaukee = std::make_unique<City>("Milwaukee", Colour::Yellow);
	//milwaukee->connectTo(map.city("London"));
	//map.addCity(std::move(milwaukee));

	//std::cout << std::endl;
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
