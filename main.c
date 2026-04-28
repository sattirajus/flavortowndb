#include <stdio.h>
#include <string.h>
#include "main.h"
#include "logging.h"
#include "runscript.h"
#include "help.h"

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

