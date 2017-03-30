#include "TurnLogger.h"

TurnLogger::TurnLogger(Logger& inner)
	: LoggerDecorator { inner }
{}

TurnLogger::~TurnLogger() {}

void TurnLogger::update()
{
	_inner.update();
	const auto turn = subject().turn();
	if (turn != _lastTurn)
	{
		_lastTurn = turn;
		log("Turn #" + std::to_string(turn) + "\n");
	}
}
