#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1; // Return an error status
    }

    char *filename = argv[1];
    int fileDescriptor = open(filename, O_RDONLY); // Open the file in read-only mode

    if (fileDescriptor == -1)
    {
        perror("Error while opening file");
        return 1; // Return an error status
    }
    else
    {
        // Use fcntl with F_GETFL to retrieve the file status flags
        int flags = fcntl(fileDescriptor, F_GETFL);

        if (flags == -1)
        {
            perror("Error while retrieving file status flags");
            close(fileDescriptor);
            return 1; // Return an error status
        }

        // Check the opening mode based on the flags
        if ((flags & O_ACCMODE) == O_RDONLY)
            printf("File '%s' is opened in read-only mode.\n", filename);
        else if ((flags & O_ACCMODE) == O_WRONLY)
            printf("File '%s' is opened in write-only mode.\n", filename);
        else if ((flags & O_ACCMODE) == O_RDWR)
            printf("File '%s' is opened in read-write mode.\n", filename);

        close(fileDescriptor);
    }

    return 0; // Return a success status
}

