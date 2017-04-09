#pragma once

#include <string>

class TurnPhase
{
public:
	virtual ~TurnPhase() = 0;
	virtual std::string name() const = 0;
	//virtual void data() = 0;
	bool operator==(const TurnPhase& rhs);
};
