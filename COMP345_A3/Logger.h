#pragma once

#include <iostream>
#include <ostream>

#include "Observer.h"
#include "TurnController.h"

class Logger :
	public Observer
{
public:
	virtual ~Logger() override = 0;
	virtual void update() override = 0;
	virtual void log(const std::string& msg) = 0;
	virtual TurnController& subject() = 0;
};
