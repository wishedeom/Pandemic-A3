#pragma once

#include <map>
#include <string>
#include <tuple>
#include <vector>

#include "City.h"
#include "Observable.h"

// Represents a game map - contains cities
class Map
	: public Observable
{
	using CityPtr = std::unique_ptr<City>;

public:
	// Constructs a map with a given file name
	Map(const std::string& name);

	// Accessors
	std::string name() const;						// Map file name
	City& city(const std::string& name) const;		// Find a city by name
	bool contains(const std::string& name) const;	// True iff map contains city of given name
	const std::vector<CityPtr>& cities() const;		// List of pointers to all contained cities

	// Mutators
	City& addCity(CityPtr city);					// Add city

private:
	std::string _name;
	std::vector<CityPtr> _cities;
};
