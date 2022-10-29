#include <netinet/in.h>
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
int serverZero()
{
	int socketN;
	struct sockaddr_in socketA;

	socketN = socket(PF_INET, SOCK_STREAM. 0);
	if (socketN == -1)
	{
		perror("serverZero: id -1");
		return (EXIT_FAILURE);
	}
	socketA.sin_family = AF_INET;
	socketA.sin_port = htons(12345);
	socketA.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(socketN, (struct sockaddr *)&socketA,
				sizeof(struct socaddr_in)) == -1)
				errorX(socketN, "serverZero: bind failed");
	
	if (listen(socketN, MAX_PENDING) == -1)
		errorX(socketN, "serverZero: listen");

	printf("Server listening on port: %i\n",
			__builtin_bswap16((uint16_t)(socketA.sin_port)));

	/* infinite */
	for(;;)
	{}

	return (EXIT_SUCCESS)
}

/**
 * main - entry point
 * Return: int
*/
int main()
{
	return (serverZero());
}
