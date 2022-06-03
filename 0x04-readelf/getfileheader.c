#include "header.h"

/**
 * getfileheader - define the headers
 * @state: struct
 * Return: 0 if ok 1 if  not ok
 */
int getfileheader(initvars_t *state)
{
	if (state->f_header.e_ident[EI_DATA] == ELFDATA2MSB)
		state->big_endian = true;

	if (state->f_header.e_ident[EI_CLASS] != ELFCLASS64)
		state->ELF_32bit = true;

	if (state->ELF_32bit)
	{
		/* Elf32_Ehdr ehdr32; */
		printf("vaca\n");
	}
	else
	{
		Elf64_Ehdr ehdr64;

		if (fread(&(ehdr64.e_type), (sizeof(ehdr64) - EI_NIDENT),
					1, state->f_stream) != 1)
			return (1);

		state->f_header.e_type      = ehdr64.e_type;
		state->f_header.e_machine   = ehdr64.e_machine;
		state->f_header.e_version   = ehdr64.e_version;
		state->f_header.e_entry     = ehdr64.e_entry;
		state->f_header.e_phoff     = ehdr64.e_phoff;
		state->f_header.e_shoff     = ehdr64.e_shoff;
		state->f_header.e_flags     = ehdr64.e_flags;
		state->f_header.e_ehsize    = ehdr64.e_ehsize;
		state->f_header.e_phentsize = ehdr64.e_phentsize;
		state->f_header.e_phnum     = ehdr64.e_phnum;
		state->f_header.e_shentsize = ehdr64.e_shentsize;
		state->f_header.e_shnum     = ehdr64.e_shnum;
		state->f_header.e_shstrndx  = ehdr64.e_shstrndx;
	}

	return (0);
}