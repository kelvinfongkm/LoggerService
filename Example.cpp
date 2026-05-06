#include "LoggerService.h"
#include <string>

int main()
{
	logger_t* logger = logger_create();

	std::string m1 = "Hello World!";
	logger_log(logger, m1.c_str(), m1.size());

	std::string m2 = "Goodnight World...";
	logger_log(logger, m2.c_str(), m2.size());

	logger_destroy(logger);
	return 0;
}
