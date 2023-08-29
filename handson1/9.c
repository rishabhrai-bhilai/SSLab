#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) == -1) {
        perror("Error getting file information");
        return 1;
    }

    printf("File Information for: %s\n", argv[1]);
    printf("Inode number: %lu\n", fileStat.st_ino);
    printf("Number of hard links: %lu\n", fileStat.st_nlink);
    printf("UID: %u\n", fileStat.st_uid);
    printf("GID: %u\n", fileStat.st_gid);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Block size: %ld bytes\n", fileStat.st_blksize);
    printf("Number of blocks: %ld\n", fileStat.st_blocks);

    printf("Time of last access: %s", ctime(&fileStat.st_atime));
    printf("Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("Time of last change: %s", ctime(&fileStat.st_ctime));

    return 0;
}

