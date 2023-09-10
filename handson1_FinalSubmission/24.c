/*
============================================================================
Name : 24.c
Author : Rishabh Kumar Rai
Description : Write a program to create an orphan process.
Date: 09th Sept, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void) {
	if(fork()) {
		//sleep(50);
		printf("Parent process id: %d\n", getpid());
		sleep(1);
	} else {
		printf("Child process id : %d\n", getpid());
		printf("Parent process id : %d\n", getppid());
		//getchar();
		sleep(5);
		printf("Parent process id : %d\n", getppid());
	}
	return 0;
}
