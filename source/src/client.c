#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#define PORT 8080

int main()
{
    int socket_fd;
    struct sockaddr_in server_address;
    char buffer[80] = "something";

    // socket create and verification
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("client socket creation failed\n");
        return -1;
    }
    printf("Socket successfully created..\n");

    // assign IP, PORT
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // connect the client socket to server socket
    if (connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address))
        != 0) {
        printf("connection with the server failed\n");
        return -1;
    }
    printf("connected to the server..\n");

    write(socket_fd, buffer, sizeof(buffer));    

    // close the socket
    close(socket_fd);
    return 0;
}