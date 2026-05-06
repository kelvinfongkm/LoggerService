#include "LoggerService.h"
#include <format>
#include <iostream>
#include <string>

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
	std::string str(message, len);
	std::clog << std::format("{}\n", str);
}
