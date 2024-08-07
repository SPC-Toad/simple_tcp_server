#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main(int argc, char* argv[]) {
    // Take in the port number from command line argument.
    int port = atoi(argv[1]);
    printf("you have entered port: %d\n", port);

    char server_message[1000] = "Hello, this is a message from the server!";

    // Create or initialize the connection on a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    // IN_LOOPBACKNET for the localhost
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_addr, sizeof(server_addr));

    listen(server_socket, 10);

    int client_socket = accept(server_socket, NULL, NULL);

    send(client_socket, server_message, sizeof(server_message), 0);

    close(server_socket);
    return 0;
}
