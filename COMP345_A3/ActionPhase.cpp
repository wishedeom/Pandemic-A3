#include <iostream>

#include "ActionPhase.h"

ActionPhase::~ActionPhase() {}

std::string ActionPhase::name() const
{
	return "Action Phase";
}
