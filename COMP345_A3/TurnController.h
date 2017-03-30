#pragma once

#include <array>
#include <string>
#include <vector>
#include <memory>

#include "TurnPhase.h"
#include "Observable.h"

class TurnController
	: public Observable
{
public:
	TurnController(const std::vector<std::string>& playerNames);
	size_t turn() const;
	std::string player() const;
	TurnPhase& phase() const;
	void nextPlayer();
	void nextPhase();
	void playTurns(const size_t count);

private:
	size_t _turnNumber = 1;
	std::vector<std::string> _playerNames;
	size_t _currentPlayer = 0;
	std::array<std::unique_ptr<TurnPhase>, 3> _phases;
	size_t _currentPhase = 0;
};
