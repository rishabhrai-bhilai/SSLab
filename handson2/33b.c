/*
============================================================================
Name : 33b.c
Author : Rishabh Rai
Description : Write a program to communicate between two machines using socket.
Date: 15th OCT, 2023.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>  // Include this for string functions

int main(void) {
    struct sockaddr_in server;
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Waiting for server...\n");
    
    if (connect(sd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Connection failed");
        return 1;
    }
    
    printf("Connected to server\n");

    char buff[80];
    write(sd, "Hello\n", 6);
    read(sd, buff, sizeof(buff));
    printf("Message from Server: %s\n", buff);
    
    close(sd); // Close the socket when done

    return 0;
}


