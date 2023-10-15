
/*
============================================================================
Name : 33a.c
Author : Rishabh Rai
Description : Write a program to communicate between two machines using socket.
Date: 10th OCT, 2023.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(void) {
    struct sockaddr_in server, client;
    int sd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(33546);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        perror("Binding failed");
        return 1;
    }

    listen(sd, 5);
    printf("Waiting for client...\n");
    int size = sizeof(client);
    int nsd = accept(sd, (struct sockaddr*) &client, &size);

    printf("Client connected\n");
    char buff[80];
    read(nsd, buff, sizeof(buff));
    printf("Message from client: %s\n", buff);
    write(nsd, "ACK\n", 4);

    close(nsd);
    close(sd);

    return 0;
}

