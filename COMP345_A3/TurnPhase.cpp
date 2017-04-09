#include "TurnPhase.h"

TurnPhase::~TurnPhase() {}

bool TurnPhase::operator==(const TurnPhase & rhs)
{
	return name() == rhs.name();
}
