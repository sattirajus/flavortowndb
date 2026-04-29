#include <stdio.h>
#include <sys/stat.h>
#include "file_io.h"
#include "logging.h"

// Requires the caller to close the file after use.
FILE *open_file(char *file_path, char *mode) {
    struct stat file_stats;

    if (stat(file_path, &file_stats) != 0) {
        panic("File '%s' does not exist.", file_path);
    }

    FILE *file = fopen(file_path, mode);

    if (file == NULL) {
        panic("Could not open file '%s' with mode '%s'.", file_path, mode);
    }

    return file;
}

long file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return size;
}
