#include "header.h"

/**
 * errorhandler - habdle error
 * @format: char
 * @errorstring: char
 * @state: struct
 */
void errorhandler(char *format, char *errorstring, initvars_t *state)
{
	fprintf(stderr, "%s: Error: ", state->p_name);
	if (errorstring == NULL)
		fprintf(stderr, format, state->f_name);
	else
		fprintf(stderr, format, state->f_name, errorstring);
}
