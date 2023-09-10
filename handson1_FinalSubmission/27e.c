/*
============================================================================
Name : 27e.c
Author : Rishabh Kumar Rai
Description : Write a program to execute ls -Rl by the following system calls
	e. execvp
Date: 08th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void) {
	char* arr[] = {"ls", "-R", "-l", NULL};
	execvp("ls", arr); 

	return 0;
}
