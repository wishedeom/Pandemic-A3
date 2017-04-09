#include "TurnLogger.h"

TurnLogger::TurnLogger(std::unique_ptr<Logger> inner)
	: LoggerDecorator { std::move(inner) }
{}

TurnLogger::~TurnLogger() {}

void TurnLogger::update()
{
	_inner->update();
	const auto turn = subject().turn();
	if (turn != _lastTurn)
	{
		_lastTurn = turn;
		log("Turn #" + std::to_string(turn) + "\n");
	}
}
