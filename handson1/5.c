#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
int a = creat("f1",S_IRUSR);
int b = creat("f2",S_IRUSR);
int c = creat("f3",S_IRUSR);
int d = creat("f4",S_IRUSR);
int e = creat("f5",S_IRUSR);

while(1);
return 0;
}
