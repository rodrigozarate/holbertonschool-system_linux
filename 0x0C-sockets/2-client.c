#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - entry
 * @argc: count
 * @argv: vector
 * Return: value of func or FAIL
*/
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	return  (clientHostPort(argv[1], argv[2]));
}
