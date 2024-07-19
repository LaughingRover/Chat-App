#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

#define PORT 8080

char *OPENSOCKET_ERR = (char *)"ERROR opening socket\n";
char *READSOCKET_ERR = (char *)"ERROR reading from socket\n";
char *WRITESOCKET_ERR = (char *)"ERROR writing to socket\n";
char *BIND_ERR = (char *)"ERROR on binding";
char *ACCEPT_ERR = (char *)"ERROR on accept";
char *CONNECT_ERR = (char *)"ERROR on connect";

void error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
