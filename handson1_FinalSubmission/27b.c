/*
============================================================================
Name : 27b.c
Author : Rishabh Kumar Rai
Description : Write a program to execute ls -Rl by the following system calls
	b. execlp
Date: 08th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void) {
	execlp("ls", "ls", "-R", "-l", NULL);

	return 0;
}
