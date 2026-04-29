#include <stdio.h>
#include <stdlib.h>
#include "logging.h"
#include "file_io.h"
#include "runscript.h"

void runscript(char *file_path) {
    FILE *script_file = open_file(file_path, "r");

    log_to_file(LOG_LEVEL_INFO, "Running script: %s", file_path);

    char *script = read_file_to_string(script_file);

    printf("Script content:\n%s\n", script);

    free(script);
    fclose(script_file);
}
