#include "header.h"

char magic4[(EI_NIDENT / 2)];

int openfile(initvars_t *state)
{
	state->f_stream = fopen(state->f_name, "rb");
	if (state->f_stream == NULL)
	{
		errorhandler("Salio mal\n", NULL, state);
		return (1);
	}
	if (fread(magic4, (EI_NIDENT / 2), 1, state->f_stream) != 1)
	{
		errorhandler("No hay magia\n", NULL, state);
		return (1);
	}

	return (0);
}