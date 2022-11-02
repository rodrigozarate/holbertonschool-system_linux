#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * getAIPv4 - get the IPv4 Address
 * @hostname: hostname
 * @port: the port
 * Return: pointer
*/
struct addrinfo *getAIPv4(const char *hostname, const char *port)
{
	int getAdrrInfVal;
	struct addrinfo hints;
	struct addrinfo *hostInf;

	if (!hostname || !port)
	{
		fprintf(stderr, "getAIPv4: Wrong parameters\n");
		return (NULL);
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = 0;

	getAdrrInfVal = getaddrinfo(hostname, port, &hints, &hostInf);
	if (getAdrrInfVal != 0)
	{
		fprintf(stderr, "getAIPv4: getaddrinfo: %s\n",
				gai_strerror(getAdrrInfVal));
		return (NULL);
	}

	return (hostInf);
}

int ipVerify(struct addrinfo *hostAddI,
			const char *hostname, const char *port)
{
	int clientID;
	struct addrinfo *tempAI;

	if (!hostAddI || !hostname)
	{
		fprintf(stderr, "ipVerify: Param Error\n");
		return (-1);
	}

	for (tempAI = hostAddI; tempAI != NULL; tempAI = tempAI->ai_next)
	{
		clientID = socket(tempAI->ai_family, tempAI->ai_socktype,
							tempAI->ai_protocol);
		if (clientID == -1)
			continue;

		if (connect(clientID, tempAI->ai_addr,
						tempAI->ai_addrlen) != -1)
		{
			printf("Connected to %s:%s\n", hostname, port);
			break;
		}

		if (close(clientID) != 0)
		{
			perror("ipVerify: Close error");
			return (-1);
		}
	}

	if (!tempAI)
	{
		fprintf(stderr, "ipVerify: no valid address found for '%s'\n",
				hostname);
		return (-1);
	}

	return (clientID);
}

/**
 * basicClient - basic client
 * @hostname: hostname
 * @port: port
 * Return: Exit ok or not
*/
int basicClient(const char *hostname, const char *port)
{
	int clientID;
	struct addrinfo *hostAddI;

	if (!hostname || !port)
	{
		fprintf(stderr, "basicClient: Param Error\n");
		return (EXIT_FAILURE);
	}

	hostAddI = getAIPv4(hostname, port);
	if (!hostAddI)
		return (EXIT_FAILURE);

	clientID = ipVerify(hostAddI, hostname, port);
	freeaddrinfo(hostAddI);
	if (clientID == -1)
		return (EXIT_FAILURE);

	if (close(clientID) != 0)
	{
		perror("basicClient: Close Error\n");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

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
