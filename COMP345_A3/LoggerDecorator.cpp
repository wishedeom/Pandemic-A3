#include "LoggerDecorator.h"

LoggerDecorator::LoggerDecorator(std::unique_ptr<Logger> inner)
	: _inner { std::move(inner) }
{}

LoggerDecorator::~LoggerDecorator() {}

void LoggerDecorator::log(const std::string& msg)
{
	_inner->log(msg);
}

TurnController& LoggerDecorator::subject()
{
	return _inner->subject();
}
