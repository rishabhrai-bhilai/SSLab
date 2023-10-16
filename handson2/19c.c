/*
============================================================================
Name : 19c.c
Author : Rishabh Rai 
Description : Create a FIFO file by
    mknod system call
Date: 11th Oct, 2023.
============================================================================
*/

#include<unistd.h>
#include<sys/stat.h>

int main(void) {
    mknod("fifo", S_IFIFO | 0666, 0);

    return 0;
}
