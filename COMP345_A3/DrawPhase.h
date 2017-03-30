#pragma once
#include "TurnPhase.h"
class DrawPhase :
	public TurnPhase
{
public:
	virtual ~DrawPhase() override;
	virtual std::string name() const override;
};
