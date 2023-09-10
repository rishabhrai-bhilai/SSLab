/*
============================================================================
Name : 9.c
Author : Rishabh Kumar Rai
Description : Write a program to print the following information about a given file.
	a. inode
	b. number of hard links
	c. uid
	d. gid
	e. size
	f. block size
	g. number of blocks
	h. time of last access
	i. time of last modification
	j. time of last change
Date: 20th Aug, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main() {

char *fname = "practice9_file1";

struct stat fileStat;

if(stat(fname, &fileStat) == -1) {
perror("some error occured");
}

else {

printf("file info for :: %s\n\n",fname);
    printf("a. Inode number: %lu\n", fileStat.st_ino);
    printf("b. Number of hard links: %lu\n", fileStat.st_nlink);
    printf("c. UID: %u\n", fileStat.st_uid);
    printf("d. GID: %u\n", fileStat.st_gid);
    printf("e. Size: %ld bytes\n", fileStat.st_size);
    printf("f. Block size: %ld bytes\n", fileStat.st_blksize);
    printf("g. Number of blocks: %ld\n", fileStat.st_blocks);
    printf("h. Time of last access: %s", ctime(&fileStat.st_atime));
    printf("i. Time of last modification: %s", ctime(&fileStat.st_mtime));
    printf("j. Time of last change: %s", ctime(&fileStat.st_ctime));

}



return 0;
}
