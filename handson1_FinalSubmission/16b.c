/*
============================================================================
Name : 16b.c
Author :Rishabh Kumar Rai
Description : Write a program to perform mandatory locking.
	b. Implement read lock
Date: 25th Aug, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void) {
	int fd = open("abc", O_RDONLY);
	struct flock fl;
	fl.l_type = F_RDLCK;
	fl.l_whence = SEEK_SET;
	fl.l_start = 0;
	fl.l_len = 0;
	fl.l_pid = getpid();

	printf("Before locking file\n");
	fcntl(fd, F_SETLKW, &fl);
	printf("Inside critical section\n");
	fl.l_type = F_UNLCK;
	printf("Press any key to unlock file\n");
	getchar();
	
	return 0;
}
