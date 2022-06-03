#include "header.h"


int openfile(initvars_t *state)
{
	char magic4[(EI_NIDENT / 2)];
	struct stat statbuf;

	if (stat(state->f_name, &statbuf) < 0)
	{
		if (errno == ENOENT)
			errorhandler("%s: No such file\n", NULL, state);
		else
			errorhandler("%s: System error\n", strerror(errno), state);
		
		return (1);
	}

	if (!S_ISREG(statbuf.st_mode))
	{
		errorhandler("Not regular file", NULL, state);

		return (1);
	}
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
	state->f_size = statbuf.st_size;
	rewind(state->f_stream);

	return (0);
}