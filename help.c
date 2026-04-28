#include <stdio.h>
#include "help.h"

void show_help_message(char *executable_name) {
    printf("Usage: %s [options]\n", executable_name);
    printf("Options:\n");
    printf("  -h, --help           Show this help message and exit\n");
    printf("  runscript <file>     Run a database script\n");
}
