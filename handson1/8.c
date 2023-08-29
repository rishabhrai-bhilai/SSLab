#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

int main(int argc, char *argv[])
{
    char *filename;
    int fileDescriptor;
    char buffer[1];

    if (argc != 2)
    {
        printf("Pass the file to be read as the argument\n");
        return 1; // Return an error status
    }
    else
    {
        filename = argv[1]; 
        fileDescriptor = open(filename, O_RDONLY);

        if (fileDescriptor == -1)
        {
            perror("Error while opening the file!");
            return 1; // Return an error status
        }
        else
        {
            while (read(fileDescriptor, buffer, 1) == 1)
            {
                if (buffer[0] == '\n')
                    write(STDOUT_FILENO, "\n\n", 2);
                else
                    write(STDOUT_FILENO, buffer, 1);
            }
            write(STDOUT_FILENO, "\n", 1);
            close(fileDescriptor);
        }
    }

    return 0; 
}

