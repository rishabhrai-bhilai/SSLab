/*
============================================================================
Name : 22a.c
Author : Rishabh Rai 
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 13th Oct, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
    int buff[80];
    int fd = open("fifo", O_WRONLY);
    printf("Enter the text: ");
    scanf("%[^\n]", buff);
    write(fd, buff, sizeof(buff));

    return 0;
}
