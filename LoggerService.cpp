#include "LoggerService.h"
#include <chrono>
#include <iostream>
#include <string>

static const std::chrono::time_zone* timezone = std::chrono::current_zone();

struct LogRecord
{
	std::chrono::system_clock::time_point timestamp;
	std::string message;
};

typedef struct logger_t
{
} logger_t;

logger_t* logger_create()
{
	return new logger_t();
}

void logger_destroy(logger_t* logger)
{
	if (logger == NULL) return;
	delete logger;
}

void logger_log(logger_t* logger, const char* message, size_t len)
{
	if (logger == NULL) return;

	LogRecord record;

	record.timestamp = std::chrono::system_clock::now();

	if (message != NULL) record.message.assign(message, len);

	std::clog << std::chrono::zoned_time(timezone, record.timestamp)
		<< '\t'
		<< record.message
		<< '\n';
}
