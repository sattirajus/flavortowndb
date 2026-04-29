#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "logging.h"
#include "file_io.h"

struct Logger logger;

void panic(char *message, ...) {
    va_list args;
    va_start(args, message);

    char log_message[MAX_LOG_MESSAGE_LENGTH];
    vsprintf(log_message, message, args);

    log_to_file(LOG_LEVEL_ERROR, log_message);
    fprintf(stderr, "Error: %s\n", log_message);

    va_end(args);

    fclose(logger.log_file);
    exit(1);
}

void log_to_file(enum LogLevel level, char *message, ...) {
    va_list args;
    va_start(args, message);

    switch (level) {
        case LOG_LEVEL_INFO:
            fprintf(logger.log_file, "[INFO] ");
            break;
        case LOG_LEVEL_WARNING:
            fprintf(logger.log_file, "[WARNING] ");
            break;
        case LOG_LEVEL_ERROR:
            fprintf(logger.log_file, "[ERROR] ");
            break;
        default:
            panic("Invalid log level.");
    }

    vfprintf(logger.log_file, message, args);
    fprintf(logger.log_file, "\n");

    fflush(logger.log_file);

    va_end(args);
}

void open_log_file(void) {
    logger.log_file = open_file(LOG_FILE_PATH, "a");
}
