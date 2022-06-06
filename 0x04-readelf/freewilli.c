#include "header.h"

/**
 * freewilli - free mem
 * @state: struct
 */
void freewilli(initvars_t *state)
{
	if (state->p_name != NULL)
	{
		state->p_name = NULL;
	}
	if (state->f_name != NULL)
	{
		state->f_name = NULL;
	}
	if (state->elf_type != 0)
	{
		state->elf_type = 0;
	}
}
