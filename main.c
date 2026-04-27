#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

int main(int argc, char *argv[]) {
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
            // Process the runscript command with the provided file path
        } else {
            panic("Incorrect usage of command line arguments.");
        }
    } else {
        panic("Too many arguments.");
    }
}

void show_help_message(char *executable_name) {
    printf("Usage: %s [options]\n", executable_name);
    printf("Options:\n");
    printf("  -h, --help    Show this help message and exit\n");
}

void panic(char *message, ...) {
    va_list args;
    va_start(args, message);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, message, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}
