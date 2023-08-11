#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int x = open("newfile4.txt",O_RDWR);
printf("%d",x);
return 0;
}
