#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytesRead;

    // Read data from standard input using STDIN_FILENO == 0
    bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (bytesRead > 0) {
        // Print the read data to standard output == 1
        write(STDOUT_FILENO, buffer, bytesRead);
    }

    return 0;
}


//remarks

//READ()
/*  SYNTAX :: bytesRead = read(STDIN_FILENO, buffer, count);
    fd: The file descriptor from which to read data.
    buf: A pointer to the buffer where the read data will be stored.
    count: The maximum number of bytes to read.

The read() function returns the number of bytes read, or -1 if an error occurs. If the return value is 0, it generally indicates that the end of the file has been reached or the input source has been closed (for example, in the case of sockets or pipes).*/

//WRITE()
/*  SYNTAX :: ssize_t bytesWritten = write(fileDescriptor, buf, count);
    fd: The file descriptor to which data will be written.
    buf: A pointer to the buffer containing the data to be written.
    count: The number of bytes to write from the buffer.

The write() function returns the number of bytes written, or -1 if an error occurs. 
*/

//SSIZE_T datatype
/*ssize_t is a data type used in C and C++ programming languages to represent the sizes of objects, typically used for representing the sizes of data blocks or the results of I/O operations. .
In this example, ssize_t is used to store the number of bytes read and written during the I/O operations. It's crucial to use ssize_t to handle potential error conditions where these values might be negative (indicating an error) or non-negative (indicating success).*/
