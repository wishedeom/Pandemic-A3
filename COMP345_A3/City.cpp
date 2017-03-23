#include <algorithm>
#include <stdexcept>

#include "City.h"
#include "Colour.h"

City::City(const std::string& name, const Colour& colour)
	: _name(name)
	, _colour(colour)
{}

std::string City::name() const
{
	return _name;
}

Colour City::colour() const
{
	return _colour;
}

const std::vector<City*>& City::connections() const
{
	return _connections;
}

bool City::isConnectedTo(const City& target)
{
	return std::any_of(_connections.begin(), _connections.end(), [&](const City* city) -> bool { return city == &target; });
}

City& City::name(const std::string& name)
{
	_name = name;
	return *this;
}

City& City::colour(const Colour& colour)
{
	_colour = colour;
	return *this;
}

City& City::connectTo(City &target)
{
	if (!isConnectedTo(target))
	{
		_connections.push_back(&target);
	}
	if (!target.isConnectedTo(*this))
	{
		target._connections.push_back(this);
	}
	return *this;
}
