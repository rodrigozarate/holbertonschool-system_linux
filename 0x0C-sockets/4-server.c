#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX_PENDING 10
#define RECV_BUFSZ 1024


/**
 * errorExit - exits on error
 * @scktID: file descriptor of socket
 * @messageErr: message
 */
void errorExit(int scktID, char *messageErr)
{
	if (close(scktID) != 0)
	{
		perror("basicServer: close");
		exit(EXIT_FAILURE);
	}

	if (messageErr)
		perror(messageErr);

	exit(EXIT_FAILURE);
}


/**
 * tcpIpSkt - opens IPv4/TCP socket
 * @port: port
 * @addr: pointer
 * Return: if of socket
 */
int tcpIpSkt(uint16_t port, struct sockaddr_in *addr)
{
	int scktID;

	if (!addr)
	{
		fprintf(stderr, "basicServer: tcpIpSkt: NULL addr\n");
		exit(EXIT_FAILURE);
	}

	scktID = socket(PF_INET, SOCK_STREAM, 0);
	if (scktID == -1)
	{
		perror("basicServer: tcpIpSkt: socket");
		exit(EXIT_FAILURE);
	}

	addr->sin_family = AF_INET;
	addr->sin_port = htons(port);
	addr->sin_addr.s_addr = htonl(INADDR_ANY);

	return (scktID);
}


/**
 * basicServer - opens an IPv4/TCP socket
 * Return: Exit ok or not
 */
int basicServer(void)
{
	int serverID, clientID;
	struct sockaddr_in server_addr = {0}, client_addr = {0};
	socklen_t client_addr_sz = sizeof(struct sockaddr_in);
	char recvbuf[RECV_BUFSZ] = {'\0'};

	serverID = tcpIpSkt(8080, &server_addr);
	if (bind(serverID, (struct sockaddr *)&server_addr,
		 sizeof(struct sockaddr_in)) == -1)
		errorExit(serverID, "basicServer: bind");

	if (listen(serverID, MAX_PENDING) == -1)
		errorExit(serverID, "basicServer: listen");

	printf("Server listening on port %i\n",
	       __builtin_bswap16((uint16_t)(server_addr.sin_port)));

	clientID = accept(serverID, (struct sockaddr *)&client_addr,
			    &client_addr_sz);
	if (clientID == -1)
		errorExit(serverID, "basicServer: accept");
	printf("Client connected: %s\n",
	       inet_ntoa(client_addr.sin_addr));

	if (recv(clientID, (void *)recvbuf, RECV_BUFSZ, 0) == -1)
		errorExit(serverID, "basicServer: recv");
	printf("Message received: \"%s\"\n", recvbuf);

	if (close(clientID) != 0 || close(serverID) != 0)
	{
		perror("basicServer: close");
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * main - entry point
 * Return: int from basicServer
 */
int main(void)
{
	return (basicServer());
}
