/*
============================================================================
Name : 14.c
Author : Rishabh Rai 
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 10th OCT, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(void) {
    int fd[2];
    int i = pipe(fd);
    char buff[10];
    if (i == -1) {
        perror("pipe build failed");
        return 1;
    }
    //printf("i =%d",i);
    int count = write(fd[1], "abcdef\n", 7);
    read(fd[0], buff, count);
    write(1, buff, count);
    return 0;
}
