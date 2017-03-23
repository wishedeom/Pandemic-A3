#pragma once

#include <vector>

class Observer;

// Abstract class for an observer's subject
class Observable
{
public:
	virtual ~Observable() = 0;

	// Add an observer to the subscription list, if not already subscribed
	void subscribe(Observer& observer);

	// Remove an observer from the subscription list, if possible
	void unsubscribe(Observer& observer);

	// Notify all observers of a state change
	void notify() const;

private:
	std::vector<Observer*> _observers;
};
