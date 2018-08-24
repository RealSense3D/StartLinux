/*
 * server.c
 * domain: AF_UNIX
 * type: SOCK_STREAM
 * protocol: 0
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>

#include "rs_sock_af_unix.h"

int af_unix_server(void)
{
    int server_sockfd, client_sockfd;
    int server_len, clinet_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    // unlink
    unlink("unix_server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // name
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "unix_server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    // listen
    listen(server_sockfd, 5);
        printf("server linsten\n");
    
    while(1){
        char ch;

        // accept
        clinet_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&clinet_len);
        
        // read & write
        read(client_sockfd, &ch, 1);
        printf("char from client = %c\n", ch);
        ch++;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
    
}

int af_unix_client(void)
{

    // create and config
    int sockfd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // name
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "unix_server_socket");
    len = sizeof(address);

    // connect
    result = connect(sockfd, (struct sockaddr *)&address, len);

    if (result == -1)
    {
        perror("oops: client1");
        exit(1);
    }

    // read and write
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);
    exit(0);
}
