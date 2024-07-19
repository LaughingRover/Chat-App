#include "util.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sockfd, portno, newsockfd, clilen, n;
	struct sockaddr_in serv_addr, cli_addr;
	char buffer[256];

	if (argc < 2)
	{
		portno = PORT;
		printf("Server is listening on port 8080...\n");
	}
	else
	{
		portno = atoi(argv[1]);
	}

	// Create a socket with the socket() system call
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error(OPENSOCKET_ERR);

	bzero((char *)&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	// Specify the local IP address and port no which the server would listen to
	// for incoming connections
	if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
		error(BIND_ERR);

	// Listen for incoming connections with the listen() system call
	listen(sockfd, 5);

	// Accept a connection with the accept() system call
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);
	if (newsockfd < 0)
		error(ACCEPT_ERR);

	// Send and receive data using the read() and write() system calls
	bzero(buffer, 256);
	n = read(newsockfd, buffer, 255);
	if (n < 0)
		error(READSOCKET_ERR);
	printf("Here is the message: %s", buffer);

	n = write(newsockfd, "I got your message\n", 19);
	if (n < 0)
		error(WRITESOCKET_ERR);

	return 0;
}
