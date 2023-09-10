/*
============================================================================
Name : 17_data_generator.c
Author : Rishabh Kumar Rai
Description : This program generate a data file which is used to complete the question 17.
Date: 25th Aug, 2023.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>

int main(void) {
	struct train {
		int train_no;
		int ticket_no;
	} record;

	int fd = open("train", O_CREAT | O_RDWR, 0600);
	record.train_no = 123;
	record.ticket_no = 56;

	write(fd, &record, sizeof(record));

	return 0;
}
