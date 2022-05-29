#include "header.h"

int main(int argc, char **argv)
{
	initvars_t state;
	int flag = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	initvars(&state);
	state.p_name = argv[0];
	state.f_name = argv[1];

	flag = openfile(&state);
	if (flag == 0)
	{
		flag = getfileheader(&state);
		if (flag == 0)
		{
			flag = printfileheader(&state);
		}
		else
		{
			errorhandler("%s: Failed to read file header\n",
				NULL, &state);
		}
	}

	freewilli(&state);
	return (flag);
}