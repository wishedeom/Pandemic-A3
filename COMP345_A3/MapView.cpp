#include <iostream>
#include <sstream>

#include "MapView.h"

MapView::MapView(Map* const map)
	: _subject { map }
{
	if (_subject)
	{
		_subject->subscribe(*this);
	}
}

MapView::~MapView() {}

void MapView::update()
{
	// Prepare regions
	std::map<Colour, std::vector<City*>> regions;
	for (const auto& city : _subject->cities())
	{
		regions[city->colour()].push_back(city.get());
	}

	// Prepare regions for display
	std::stringstream ss;
	ss << "Map report:\n";
	for (const auto& region : regions)
	{
		ss << "Region " << colourToString(region.first) << "\n";
		for (const auto& city : region.second)
		{
			ss << "\t" << city->name() << " connected to ";
			const auto& connections = city->connections();
			if (connections.empty())
			{
				ss << "nothing";
			}
			ss << "\n";
			for (const auto& c : connections)
			{
				ss << "\t\t" << c->name() << "\n";
			}
		}
	}
	std::cout << ss.str();
}

Map* MapView::subject() const
{
	return _subject;
}
