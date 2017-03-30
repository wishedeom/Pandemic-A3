#include "LoggerDecorator.h"

LoggerDecorator::LoggerDecorator(Logger& inner)
	: _inner { inner }
{}

LoggerDecorator::~LoggerDecorator() {}

void LoggerDecorator::log(const std::string& msg)
{
	_inner.log(msg);
}

TurnController& LoggerDecorator::subject()
{
	return _inner.subject();
}
