#pragma once

#include "LoggerDecorator.h"

class PlayerLogger :
	public LoggerDecorator
{
public:
	PlayerLogger(std::unique_ptr<Logger> inner, const std::string& playerName);
	virtual ~PlayerLogger();
	virtual void update() override;

private:
	std::string _targetName;
	std::string _lastPlayer;
};

