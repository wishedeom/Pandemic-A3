#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Colour.h"

// Represents a single city.
// Each city should belong to a map. A city has a name and a coloured "region" that it belongs to, for the purposes of disease classification.
// A city can be connected to other cities that belong to its same map.
class City
{
public:
	// Constructs a city with a given name and colour
	City(const std::string& name = "", const Colour& colour = Colour::Black);

	// The city's name
	std::string name() const;

	// Changes the city's name
	City& name(const std::string& name);

	// The coloured "region" the city belongs to
	Colour colour() const;
	
	// Changes the city's region
	City& colour(const Colour& colour);
	
	// Declares that this city is connected to another given city
	City& connectTo(City& target);

	// The cities that this city is connected to
	const std::vector<City*>& connections() const;

	// True iff the city is connected to another given city
	bool isConnectedTo(const City& target);

private:
	std::string _name;
	Colour _colour;
	std::vector<City*> _connections;
};
