#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    if (ferror(source)) {
        perror("Error reading from source file");
    }

    if (ferror(destination)) {
        perror("Error writing to destination file");
    }

    fclose(source);
    fclose(destination);

    return 0;
}

