#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);  // Clear the set
    FD_SET(STDIN_FILENO, &readfds); // Add STDIN to the set

    timeout.tv_sec = 10;  // 10 seconds
    timeout.tv_usec = 0;

    printf("Waiting for data on STDIN for up to 10 seconds...\n");

    int result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select error");
        return 1;
    } else if (result == 0) {
        printf("No data available on STDIN within 10 seconds.\n");
    } else {
        printf("Data is available on STDIN.\n");
    }

    return 0;
}

