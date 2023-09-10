/*
============================================================================
Name : 4.c
Author : Rishabh Kumar Rai
Description :  Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int x = open("newfile4.txt",O_RDWR|O_EXCL);
printf("%d",x);
return 0;
}
