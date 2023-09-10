/*
============================================================================
Name : 22.c
Author : Rishabh Kumar Rai
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 09th Sept, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(void) {
	int fd = open("abc", O_RDWR | O_TRUNC);
	char* str;

	if(fork()) {
		str = "Child write\n";
		write(fd, str, strlen(str));
	} else {
		str = "Parent write\n";
		write(fd, str, strlen(str));
	}

	return 0;
}
