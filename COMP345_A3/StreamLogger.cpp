#include <iomanip>

#include "StreamLogger.h"

StreamLogger::StreamLogger(TurnController& subject, std::ostream& stream)
	: _subject { subject }
	, _stream { stream }
{
	//_subject.subscribe(*this);
}

StreamLogger::~StreamLogger() {}

TurnController& StreamLogger::subject()
{
	return _subject;
}

void StreamLogger::log(const std::string& msg)
{
	++_lineNumber;
	_stream << std::setfill('0') << std::setw(4) << _lineNumber << ":  " << msg;
}

void StreamLogger::update() {}
