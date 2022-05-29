#include "header.h"

/**
 * getfileheader - define the headers
 * @state: struct
 * Return: 0 if ok 1 if  not ok
 */
int getfileheader(initvars_t *state)
{
	if (state->elf_type == 1)
		return (1);

	return (0);
}