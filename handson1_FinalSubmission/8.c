/*
============================================================================
Name : 8.c
Author : Rishabh Kumar Rai
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
	Close the file when end of file is reached.
Date: 20th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {

/*

char *fname = "practice8_file1";
int fd = open(fname,O_RDONLY);
if(fd == -1) {
printf("error");
}

ssize_t returnsize;
char buffer[1024];
returnsize = read(fd,buffer,sizeof(buffer));


for(int i=0;i<returnsize;i++){
printf("%c",buffer[i]);
}

*/

//OR

FILE* fp = fopen("practice8_file1","r");
char linebuf[1024];

if(fp == NULL) { perror("eroor openning file"); }

else {
while(fgets(linebuf,sizeof(linebuf),fp) != NULL) {
	printf("%s",linebuf);
}

}

return 0;
}
