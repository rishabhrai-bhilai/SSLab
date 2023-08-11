#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int filedesc = creat("newFile",S_IRUSR);
printf("%d",filedesc);
return 0;
}
