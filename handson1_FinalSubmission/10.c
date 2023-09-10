/*
============================================================================
Name : 10.c
Author : Rishabh Kumar Rai
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
	a. check the return value of lseek
Date: 20th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
 
int main() {

int fd = open("practice10_file1",O_RDWR | O_CREAT, 0644);

char *data1 = "abcdefghij";
char *data2 = "1234567890";


if(fd == -1) perror("error opening file");

ssize_t bytewritten = write(fd,data1,10);
off_t ofset = lseek(fd,10,SEEK_CUR);
printf("after 1st lseek value= %ld \n",ofset);
bytewritten = write(fd,data2,10);
ofset = lseek(fd,0,SEEK_CUR);
printf("after 2nd lseek value= %ld",ofset);

close(fd);


return 0;
}
