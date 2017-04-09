#pragma once

#include "LoggerDecorator.h"

class TurnLogger :
	public LoggerDecorator
{
public:
	TurnLogger(std::unique_ptr<Logger> inner);
	virtual ~TurnLogger();
	virtual void update() override;

private:
	size_t _lastTurn;
};

