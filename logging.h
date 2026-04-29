#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>
#include <stdarg.h>

enum LogLevel {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

struct Logger {
    FILE *log_file;
};

#define LOG_FILE_PATH "db_log.txt"
#define MAX_LOG_MESSAGE_LENGTH 1024

extern struct Logger logger;

void panic(char *message, ...);
void log_to_file(enum LogLevel level, char *message, ...);
void open_log_file(void);

#endif
