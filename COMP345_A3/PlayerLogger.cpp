#include "PlayerLogger.h"

PlayerLogger::PlayerLogger(Logger& inner, const std::string& playerName)
	: LoggerDecorator { inner }
	, _playerName { playerName }
{}

PlayerLogger::~PlayerLogger() {}

void PlayerLogger::update()
{
	_inner.update();
	if (subject().player() == _playerName)
	{
		log(_playerName + "'s turn...\n");
	}
}
