
/*
============================================================================
Name : 1.c
Author : Rishabh Kumar Rai
Description : Create the following types of a files using (i) shell command (ii) system call
	a. soft link (symlink system call)
	b. Hard Link
	c. Fifo
Date: 20th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int v = symlink("dest","destSL");
if(v<0) {
perror("failed");
return 1;
}

int f = link("dest","destHL");
if(f<0) {
perror("failed");
return 1;
}

int e= mknod("destFIFO",S_IFIFO,0);
if(e<0) 
perror("failed");
return 0;
}

