#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; // Return an error status
    }

    char *filename = argv[1];
    struct stat fileStats;

    if (stat(filename, &fileStats) == -1) {
        perror("Error while getting file information");
        return 1; // Return an error status
    }

    if (S_ISREG(fileStats.st_mode)) {
        printf("%s is a regular file.\n", filename);
    } else if (S_ISDIR(fileStats.st_mode)) {
        printf("%s is a directory.\n", filename);
    } else if (S_ISLNK(fileStats.st_mode)) {
        printf("%s is a symbolic link.\n", filename);
    } else if (S_ISCHR(fileStats.st_mode)) {
        printf("%s is a character special file.\n", filename);
    } else if (S_ISBLK(fileStats.st_mode)) {
        printf("%s is a block special file.\n", filename);
    } else if (S_ISFIFO(fileStats.st_mode)) {
        printf("%s is a FIFO/pipe.\n", filename);
    } else if (S_ISSOCK(fileStats.st_mode)) {
        printf("%s is a socket.\n", filename);
    } else {
        printf("%s is of unknown type.\n", filename);
    }

    return 0; // Return a success status
}

