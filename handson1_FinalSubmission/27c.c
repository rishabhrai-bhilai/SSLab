/*
============================================================================
Name : 27c.c
Author : Rishabh Kumar Rai
Description : Write a program to execute ls -Rl by the following system calls
	c. execle
Date: 08th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void) {
	char* envp[] = {NULL};
	execle("/bin/ls", "ls", "-R", "-l", NULL, envp);

	return 0;
}
