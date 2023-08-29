#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Declare the environment variable array

int main() {
    char **env = environ; // Pointer to traverse the environment variable array

    printf("Environment variables:\n");
    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}

