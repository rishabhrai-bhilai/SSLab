/*
============================================================================
Name : 12.c
Author : Rishabh Kumar Rai
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 20th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {

int fd = open("practice12_file1",O_RDWR|O_CREAT,0644);
if(fd == -1) perror("error opening file");

else{

int flag = fcntl(fd,F_GETFL);
if(flag == -1) perror("error getting file status");

else if((flag & O_ACCMODE) == O_RDONLY) printf("opening mode is read only");
else if((flag & O_ACCMODE) == O_WRONLY) printf("opening mode is write only");
else if((flag & O_ACCMODE) == O_RDWR) printf("opening mode is read/write only");
else  printf("opening mode is unknown");
}

return 0;
}

