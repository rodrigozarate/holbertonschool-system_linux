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
	printf("  Version:                           %u%s\n",
			state->f_header.e_ident[EI_VERSION],
			state->f_header.e_ident[EI_VERSION] ==
			EV_CURRENT ? " (current)" : "");
	printf("  Version:                           0x%x\n",
			state->f_header.e_version);
	printf("  Entry point address:               0x%lx\n",
			state->f_header.e_entry);
	printf("  Start of program headers:          %lu (bytes into file)\n",
			state->f_header.e_phoff);
	printf("  Start of section headers:          %lu (bytes into file)\n",
			state->f_header.e_shoff);
	printf("  Flags:                             0x%x\n",
			state->f_header.e_flags);
	printf("  Size of this header:               %u (bytes)\n",
			state->f_header.e_ehsize);

	return (0);
}