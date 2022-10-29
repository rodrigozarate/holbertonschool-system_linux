#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PENDING 10

/**
 * errorX - custom error
 * @socketN: socket number identifier
 * @message: mesage
*/
void errorX(int socketN, char *message)
{
	if (close(socketN) != 0)
	{
		perror("serverZero: closing error");
		exit(EXIT_FAILURE);
	}

	if (message)
		perror(message);

	exit(EXIT_FAILURE);
}

/**
 * serverZero - socket simple demo
 * Return: int
*/
int serverZero(void)
{
	int serverN, clientN;
	struct sockaddr_in serverA = {0}, clientA = {0};
	socklen_t clientAZise = sizeof(struct sockaddr_in);

	serverN = socket(PF_INET, SOCK_STREAM, 0);
	if (serverN == -1)
	{
		perror("serverZero: id -1");
		return (EXIT_FAILURE);
	}
	serverA.sin_family = AF_INET;
	serverA.sin_port = htons(12345);
	serverA.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(serverN, (struct sockaddr *)&serverA,
				sizeof(struct sockaddr_in)) == -1)
		errorX(serverN, "serverZero: bind failed");

	if (listen(serverN, MAX_PENDING) == -1)
		errorX(serverN, "serverZero: listen");

	printf("Server listening on port: %i\n",
			__builtin_bswap16((uint16_t)(serverA.sin_port)));

	clientN = accept(serverN, (struct sockaddr *)&clientA,
						&clientAZise);
	if (clientN == -1)
		errorX(serverN, "serverZero: error on accept");

	printf("Client connected: %s\n",
			inet_ntoa(clientA.sin_addr));

	if (close(clientN) != 0 || close(serverN) != 0)
	{
		perror("serverZero: close error");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/**
 * main - entry point
 * Return: int
*/
int main(void)
{
	return (serverZero());
}
