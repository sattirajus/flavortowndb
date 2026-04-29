#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>

FILE *open_file(char *file_path, char *mode);
long file_size(FILE *file);

#endif
