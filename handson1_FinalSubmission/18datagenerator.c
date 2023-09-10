/*
============================================================================
Name : 18_data_generator.c
Author : Rishabh Kumar Rai
Description : This program generate a data file which is used to complete the question 18.
Date: 25th Aug, 2023.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>

int main(void) {
	int fd = open("18Record", O_RDWR | O_CREAT, 0600);
	struct student {
		char* name;
		int roll_no;
	} a;

	for(int i = 110; i < 113; i++) {
		a.name = "Name";
		a.roll_no = i;
		write(fd, &a, sizeof(a));
	}

	return 0;
}
