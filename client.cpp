#include "util.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s hostname port\nPort defaults to 8080",
				argv[0]);
		exit(0);
	}

	if (argc == 2)
		portno = PORT;
	else
		portno = atoi(argv[2]);

	// Create a socket with the socket() system call
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error(OPENSOCKET_ERR);

	server = gethostbyname(argv[1]);
	if (server == NULL)
	{
		fprintf(stderr, "ERROR, no such host\n");
		exit(0);
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr,
		  (char *)&serv_addr.sin_addr.s_addr,
		  server->h_length);
	serv_addr.sin_port = htons(portno);

	// Connect the client socket to a server's address and port
	// using the connect() system call
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error(CONNECT_ERR);

	// Send and receive data using the read() and write() system calls
	printf("please enter the message: ");
	bzero(buffer, 256);
	fgets(buffer, 255, stdin);
	n = write(sockfd, buffer, strlen(buffer));
	if (n < 0)
		error(WRITESOCKET_ERR);

	bzero(buffer, 256);
	n = read(sockfd, buffer, 255);
	if (n < 0)
		error(READSOCKET_ERR);
	printf("%s", buffer);

	return 0;
}
