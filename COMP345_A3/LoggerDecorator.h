#pragma once

#include <memory>

#include "Logger.h"

class LoggerDecorator :
	public Logger
{
public:
	LoggerDecorator(std::unique_ptr<Logger> inner);
	virtual ~LoggerDecorator() = 0;

protected:
	std::unique_ptr<Logger> _inner;
	virtual void log(const std::string& msg) override;
	virtual TurnController& subject() override;
};

