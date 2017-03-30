#pragma once

#include <ostream>

#include "TurnController.h"
#include "Logger.h"

class StreamLogger :
	public Logger
{
public:
	StreamLogger(TurnController& subject, std::ostream& stream);
	virtual ~StreamLogger() override;
	virtual TurnController& subject() override;
	virtual void log(const std::string& msg) override;
	virtual void update() override;

protected:
	TurnController& _subject;
	std::ostream& _stream;

private:
	size_t _lineNumber = 0;
};

