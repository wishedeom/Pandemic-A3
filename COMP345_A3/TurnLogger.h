#pragma once

#include "LoggerDecorator.h"

class TurnLogger :
	public LoggerDecorator
{
public:
	TurnLogger(Logger& inner);
	virtual ~TurnLogger();
	virtual void update() override;

private:
	size_t _lastTurn;
};

