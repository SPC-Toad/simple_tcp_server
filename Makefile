CC = gcc
all:
	make tcp_client && make tcp_server
tcp_client:
	$(CC) tcp_client.c -o tcp_client
tcp_server:
	$(CC) tcp_server.c -o tcp_server
run-server:
	./tcp_server 8080
run-client:
	./tcp_client 8080
clean:
	rm -f tcp_server tcp_client