#include "header.h"

/**
 * printfileheader - prints file header
 * @state: struct
 * Return: always 0
 */
int printfileheader(initvars_t *state)
{
	int i;
	puts("ELF Header:");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x ", state->f_header.e_ident[i]);
	putchar('\n');
	printf("  Class:                             %s\n",
			state->ELF_32bit ? "ELF32" : "ELF64");
	printf("  Data:                              %s, %s endian\n",
			"2's complement", state->big_endian ? "big" : "little");

	return (0);
}