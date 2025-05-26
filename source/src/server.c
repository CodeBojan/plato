#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#define PORT 8080

int main()
{
    int socketfd, connectionfd, length;
    struct sockaddr_in server_address, client;
    char buffer[80] = {0};

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1){
        printf("socket creation failed\n");
        return -1;
    }
    printf("socket created\n");

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if(bind(socketfd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0){
        printf("socket binding failed\n");
        return -1;
    }
    printf("socket binding successful\n");

    if(listen(socketfd, 5) != 0){
        printf("listening failed\n");
        return -1;
    }
    printf("server is listening...\n");
    length = sizeof(client);

    //blocking
    connectionfd = accept(socketfd, (struct sockaddr *)&client, (socklen_t *__restrict__)&length);
    if (connectionfd < 0){
        printf("server receiving failed\n");
    }
    printf("server accepted a connection");

    read(connectionfd, buffer, sizeof(buffer));
    printf("message from client: %s\n", buffer);

    close(socketfd);
    return 0;
}