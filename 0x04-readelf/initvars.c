#include "header.h"

void initvars(initvars_t *state)
{
	state->p_name = NULL;
	state->f_name = NULL;
	state->elf_type = 0;
	state->big_endian = false;
	state->ELF_32bit = false;
	state->f_size = 0;
	state->f_stream = NULL;
	memset(&(state->f_header), 0, sizeof(Elf64_Ehdr));
}