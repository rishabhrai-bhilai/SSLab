#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *filename;
    int fileDescriptor, dupFileDescriptor;
    ssize_t writeByteCount;

    if (argc != 2)
    {
        printf("Pass the file name as the argument!\n");
        return 1; // Return an error status
    }
    else
    {
        filename = argv[1];
        fileDescriptor = open(filename, O_WRONLY | O_APPEND);
        if (fileDescriptor == -1)
        {
            perror("Error while opening file");
            return 1; // Return an error status
        }
        else
        {
            dupFileDescriptor = dup(fileDescriptor);

            // Writing using original file descriptor
            writeByteCount = write(fileDescriptor, "Using original FD\n", 18);
            if (writeByteCount == -1)
            {
                perror("Error while writing file using original FD");
                return 1; // Return an error status
            }

            // Writing using duplicate file descriptor
            writeByteCount = write(dupFileDescriptor, "Using duplicate FD\n", 19);
            if (writeByteCount == -1)
            {
                perror("Error while writing file using duplicate FD");
                return 1; // Return an error status
            }

            close(fileDescriptor);
            close(dupFileDescriptor);
        }
    }

    return 0; // Return a success status
}

