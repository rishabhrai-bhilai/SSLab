/*
============================================================================
Name : 7.c
Author : Rishabh Kumar Rai
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {

char buffer[1024];

char *fname1 = "practice7_file1";
char *fname2 = "practice7_file2";
int fd1 = open(fname1,O_RDWR);
int fd2 = open(fname2,O_RDWR);

printf("running");
if(fd1 == -1 || fd2 == -1) {
printf("erroer opening file");
}


ssize_t returnsize = read(fd1,buffer,sizeof(buffer));

if(returnsize > 0) {
//write(2,buffer,returnsize);
write(fd2,buffer,returnsize);
printf("task completed");
}



return 0;
}
