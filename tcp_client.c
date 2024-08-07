#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

void function1 () {}

int main(int argc, char* argv[]) {
    // Take in the port number from command line argument.
    int port = atoi(argv[1]);
    printf("you have entered port: %d\n", port);

    // Create or initialize the connection on a socket
    int net_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    // IN_LOOPBACKNET for the localhost
    server_addr.sin_addr.s_addr = INADDR_ANY;


    int conn_status = connect(net_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    // Checks the connection status
    if (conn_status == -1) {
        printf("Socket connection error: line 26");
    }

    // Receiving data from the server
    // send and recv calls
    char server_response[256];
    recv(net_socket, &server_response, sizeof(server_response), 0);
    printf("The message from the server:\n%s\n", server_response);
 
    // then close the socket when done
    close(net_socket);
    return 0;
}
