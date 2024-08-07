# TCP Server and Client in C

This project demonstrates how to create a TCP server and client using the C programming language.

## Getting Started

### Building the Executables
To compile the project and create the executables, run:
```sh
make all
```
This will generate two files: `tcp_client` and `tcp_server`.

### Running the Server
Start the TCP server on port 8080 by running:
```sh
make run-server
```
The make command is configured to use port 8080 by default.

### Running the Client
Start the TCP client, which will connect to the server on port 8080, by running:
```sh
make run-client
```
If the connection is successful, the client CLI will display:
```
The message from the server:
Hello, this is a message from the server!
```

### Cleaning Up
To remove the generated executables, run:
```sh
make clean
```

## Notes on Server Implementation

### Socket Binding with IP Address and Port
1. **Creating the Socket:** Use the `socket()` function to create a socket.
2. **Binding the Socket:** Bind the socket to an IP address and port number using the `bind()` function.
3. **Listening for Connections:** After binding, use the `listen()` function to make the socket listen for incoming connections.
4. **Accepting Connections:** When a client attempts to connect, accept the connection using the `accept()` function.