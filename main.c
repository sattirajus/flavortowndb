#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/stat.h>
#include "main.h"

int main(int argc, char *argv[]) {
    open_log_file();

    if(argc == 0) {
        panic("argc is 0.");
    }

    if(argc == 1) {
        show_help_message(argv[0]);
    } else if(argc == 2) {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            show_help_message(argv[0]);
        } else {
            panic("Incorrect usage of command line arguments.");
        }
    } else if(argc == 3) {
        if(strcmp(argv[1], "runscript") == 0) {
            runscript(argv[2]);
        } else {
            panic("Incorrect usage of command line arguments.");
        }
    } else {
        panic("Too many arguments.");
    }

    fclose(logger.log_file);
}

void show_help_message(char *executable_name) {
    printf("Usage: %s [options]\n", executable_name);
    printf("Options:\n");
    printf("  -h, --help    Show this help message and exit\n");
}

void panic(char *message, ...) {
    va_list args;
    va_start(args, message);

    char log_message[MAX_LOG_MESSAGE_LENGTH];
    vsprintf(log_message, message, args);

    log_to_file(LOG_LEVEL_ERROR, log_message);
    printf("%s\n", log_message);

    va_end(args);

    fclose(logger.log_file);
    exit(1);
}

void runscript(char *file_path) {
    FILE *script_file = open_file(file_path, "r");

    log_to_file(LOG_LEVEL_INFO, "Running script: %s", file_path);

    fclose(script_file);
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

void open_log_file() {
    logger.log_file = open_file(LOG_FILE_PATH, "a");
}

FILE *open_file(char *file_path, char *mode) {
    struct stat file_stats;

    if(stat(file_path, &file_stats) != 0) {
        panic("File '%s' does not exist.", file_path);
    }

    FILE *file = fopen(file_path, mode);

    if(file == NULL) {
        panic("Could not open file '%s' with mode '%s'.", file_path, mode);
    }

    return file;
}
