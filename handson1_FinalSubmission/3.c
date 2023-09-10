/*
============================================================================
Name : 3.c
Author : Rishabh Kumar Rai
Description :  Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int filedesc = creat("newFile",S_IRUSR);
printf("%d",filedesc);
return 0;
}
