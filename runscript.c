#include <stdio.h>
#include <stdlib.h>
#include "logging.h"
#include "runscript.h"

void runscript(char *file_path) {
    FILE *script_file = open_file(file_path, "r");

    log_to_file(LOG_LEVEL_INFO, "Running script: %s", file_path);

    long script_length = file_size(script_file);

    char *script = malloc(script_length + 1);
    if (!script) {
        panic("Failed to allocate memory for script.");
    }

    long bytes_read = fread(script, 1, script_length, script_file);
    script[bytes_read] = '\0';

    free(script);
    fclose(script_file);
}

long file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}
