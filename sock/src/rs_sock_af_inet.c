/*
 * server.c
 * domain: AF_INET
 * type: SOCK_STREAM
 * protocol: 0
 */
// netstat -A inet
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#include "rs_sock_af_inet.h"


int af_inet_server(void)
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

/*  Create an unnamed socket for the server.  */
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket.  */
    server_address.sin_family = AF_INET;
    /* 使用INADDR_ANY来允许到达服务器任意网络接口的连接 */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    // server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(2018);
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */
    listen(server_sockfd, 5);
    printf("server listen\n");
    while(1)
    {
        char ch;

/*  Accept a connection.  */
    client_len = sizeof(client_address);
    client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */
    read(client_sockfd, &ch, 1);
    printf("ch from client = %c\n", ch);
    ch++;
    write(client_sockfd, &ch, 1);
    close(client_sockfd);
    }


}
int af_inet_client(void)
{
    int client_sockfd;
    int client_len;
    struct sockaddr_in client_address;
    int result;
    char ch = 'A';

/*  Create a socket for the client.  */
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);

/*  Name the socket, as agreed with the server.  */
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    client_address.sin_port = htons(2018);
    client_len = sizeof(client_address);

/*  Now connect our socket to the server's socket.  */
    result = connect(client_sockfd, (struct sockaddr*)&client_address, client_len);

    if(result == -1)
    {
        perror("oops: client2");
        exit(1);
    }

/*  We can now read/write via sockfd.  */
    write(client_sockfd, &ch, 1);
    read(client_sockfd, &ch, 1);
    printf("char form server = %c\n", ch);

    close(client_sockfd);
    exit(0);
}