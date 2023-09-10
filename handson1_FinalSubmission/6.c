/*
============================================================================
Name : 6.c
Author : Rishabh Kumar Rai
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
char  buffer[1024];

ssize_t returnsize = read(1,buffer,sizeof(buffer));
if(returnsize > 0) {
write(2,buffer,returnsize);
}


return 0;
}

