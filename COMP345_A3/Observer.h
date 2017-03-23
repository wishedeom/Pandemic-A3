#pragma once

class Observable;

// Interface
// Can subscribe to an Observable to be notified when there is a state change.
class Observer
{
public:
	virtual ~Observer() = 0 {};

	// Called by an Observable's notify method.
	virtual void update() = 0;
};
