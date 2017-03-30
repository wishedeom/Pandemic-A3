#pragma once
#include "TurnPhase.h"
class ActionPhase :
	public TurnPhase
{
public:
	virtual ~ActionPhase() override;
	virtual std::string name() const override;
};
