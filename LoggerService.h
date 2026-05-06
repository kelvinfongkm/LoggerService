#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct logger_t logger_t;

// Creates a logger instance.
logger_t* logger_create();

// Destroys a logger instance.
void logger_destroy(logger_t* logger);

// Logs a message.
void logger_log(logger_t* logger, const char* message, size_t len);
