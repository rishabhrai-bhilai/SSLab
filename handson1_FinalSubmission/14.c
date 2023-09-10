/*
============================================================================
Name : 14.c
Author : Rishabh Kumar Rai
Description : Write a program to find the type of a file.
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(int argc , char *argv[] ) {

if(argc !=2) perror("please give file name");

else {
struct stat fileStats;
char *filename = argv[1];
int returnval = stat(argv[1],&fileStats);
if(returnval == -1) perror("some eror occured");
else{

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
        printf("%s is of an unknown type.\n", filename);
    }


}
}

return 0;
}
