#include <iostream>
#include <memory>

#include "TurnController.h"
#include "ActionPhase.h"
#include "DrawPhase.h"
#include "InfectPhase.h"

TurnController::TurnController(const std::vector<std::string>& playerNames)
	: _playerNames { playerNames }
	, _phases { std::make_unique<ActionPhase>(), std::make_unique<InfectPhase>(), std::make_unique<DrawPhase>() }
{
	std::cout << "Loading players...\n";
	for (const auto& name : _playerNames)
	{
		std::cout << "\t" << name << "\n";
	}
	
	std::cout << "Loading phases...\n";
	for (const auto& phase : _phases)
	{
		std::cout << "\t" << phase->name() << "\n";
	}

	std::cout << "Starting game...\n";
}

size_t TurnController::turn() const
{
	return _turnNumber;
}

std::string TurnController::player() const
{
	return _playerNames[_currentPlayer];
}

TurnPhase& TurnController::phase() const
{
	return *_phases[_currentPhase].get();
}

void TurnController::nextPlayer()
{
	++_currentPlayer;
	if (_currentPlayer >= _playerNames.size())
	{
		++_turnNumber;
		//std::cout << "Turn #" << _turnNumber << "\n";
		_currentPlayer = 0;
	}
	notify();
	//std::cout << player() << "'s turn.\n";
}

void TurnController::nextPhase()
{
	++_currentPhase;
	if (_currentPhase >= _phases.size())
	{
		_currentPhase = 0;
		nextPlayer();
	}
	notify();
	//std::cout << phase().name() << "\n";
}

void TurnController::playTurns(const size_t count)
{
	const size_t lastTurn = _turnNumber + count;
	while (_turnNumber <= lastTurn)
	{
		nextPhase();
	}
}
