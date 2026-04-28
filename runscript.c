#include <stdio.h>
#include "logging.h"
#include "runscript.h"

void runscript(char *file_path) {
    FILE *script_file = open_file(file_path, "r");

    log_to_file(LOG_LEVEL_INFO, "Running script: %s", file_path);

    fclose(script_file);
}
