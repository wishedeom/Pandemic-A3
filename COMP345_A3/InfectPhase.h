#pragma once

#include "TurnPhase.h"

class InfectPhase :
	public TurnPhase
{
public:
	virtual ~InfectPhase() override;
	virtual std::string name() const override;
};

