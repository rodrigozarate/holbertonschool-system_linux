#include "head.h"

/**
 * handle_errors - handles errors
 * @directory: directory
 * Return: 2
 */

void handle_errors(char *directory)
{

	if (errno == ENOENT)
		fprintf(stderr, "hls: cannot access %s: ", directory);
	else if (errno == EACCES)
		fprintf(stderr, "hls: cannot open directory %s", directory);
	perror("");
}
