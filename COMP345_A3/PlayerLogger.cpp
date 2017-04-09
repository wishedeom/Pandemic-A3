#include "PlayerLogger.h"

PlayerLogger::PlayerLogger(Logger& inner, const std::string& playerName)
	: LoggerDecorator { inner }
	, _targetName { playerName }
{}

PlayerLogger::~PlayerLogger() {}

void PlayerLogger::update()
{
	_inner.update();
	const auto& currentPlayer = subject().player();
	if (_lastPlayer == currentPlayer)
	{
		return;
	}
	_lastPlayer = currentPlayer;
	if (currentPlayer == _targetName)
	{
		log(_targetName + "'s turn...\n");
	}
}
