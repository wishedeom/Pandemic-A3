#pragma once

#include "Logger.h"

class LoggerDecorator :
	public Logger
{
public:
	LoggerDecorator(Logger& inner);
	virtual ~LoggerDecorator() = 0;

protected:
	Logger& _inner;
	virtual void log(const std::string& msg) override;
	virtual TurnController& subject() override;
};

