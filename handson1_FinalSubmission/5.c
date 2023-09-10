/*
============================================================================
Name : 5.c
Author : Rishabh Kumar Rai 
Description :  Write a program to create five new files with infinite loop. Execute the program in the background
	and check the file descriptor table at /proc/pid/fd.
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main() {
int fd1 = open("practice5_file1",O_CREAT,0644);
int fd2 = open("practice5_file2",O_CREAT,0644);
int fd3 = open("practice5_file3",O_CREAT,0644);
int fd4 = open("practice5_file4",O_CREAT,0644);
int fd5 = open("practice5_file5",O_CREAT,0644);
while(1);
return 0;
}
