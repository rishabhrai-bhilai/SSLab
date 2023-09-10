/*
============================================================================
Name : 11.c
Author : Rishabh Kumar Rai
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
	a. use dup
	b. use dup2
Date: 20th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main()  {

char data1[] = "first line";
char data2[] = "second line";


int fd1 = open("practice11_file1",O_RDWR|O_CREAT,0644);

if(fd1 == -1) perror("error opening file");

else {

ssize_t bytewritten = write(fd1,data1,sizeof(data1));
if(bytewritten>0) printf("file_des1 working no of char printed %ld", bytewritten);
bytewritten =0;


int fd2 = dup(fd1);
 bytewritten = write(fd2,data2,sizeof(data2));
 if(bytewritten>0) printf("file_des2 working no of char printed %ld", bytewritten);

//OR
/* USING DUP2
int fd2 = dup2(fd1,11);
 bytewritten = write(fd2,data2,sizeof(data2));
 if(bytewritten>0) printf("file_des2 working no of char printed %ld", bytewritten);
 */
 

}


close(fd1);
return 0;
}
