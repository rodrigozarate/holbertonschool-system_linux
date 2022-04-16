#include "head.h"

/**
 * handle_errors - handles errors
 * @directory: directory
 * @prog_name: main program name
 * Return: 2
 */

void handle_errors(char *directory, char const *prog_name)
{

	if (errno == ENOENT)
		fprintf(stderr, "%s: cannot access %s: ", prog_name, directory);
	else if (errno == EACCES)
		fprintf(stderr, "%s: cannot open directory %s: ",
			prog_name, directory);
	/* perror(""); */
}
