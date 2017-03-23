#pragma once

#include <vector>
#include <map>

#include "City.h"
#include "Colour.h"
#include "Map.h"
#include "Observer.h"

// Prints a report to the console whenever an observed map changes
class MapView
	: public Observer
{
public:
	// Constructs a MapView observing a given Map
	MapView(Map* const map = nullptr);

	// Dtor
	~MapView() override;

	// Report on the change of state
	void update() override;

	// The observed Map
	Map* subject() const;

private:
	Map* _subject;
};
