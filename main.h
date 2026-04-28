enum LogLevel {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

struct Logger {
    FILE *log_file;
};

#define LOG_FILE_PATH "db_log.txt"
#define MAX_LOG_MESSAGE_LENGTH 1024

int main(int argc, char *argv[]);
void show_help_message(char *executable_name);
void panic(char *message, ...);
void runscript(char *file_path);
void log_to_file(enum LogLevel level, char *message, ...);
void open_log_file();
FILE *open_file(char *file_path, char *mode);

struct Logger logger;
