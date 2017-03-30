#pragma once

#include "LoggerDecorator.h"

class PlayerLogger :
	public LoggerDecorator
{
public:
	PlayerLogger(Logger& inner, const std::string& playerName);
	virtual ~PlayerLogger();
	virtual void update() override;

private:
	std::string _playerName;
};

