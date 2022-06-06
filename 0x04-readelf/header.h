#ifndef _ELF_READER_
#define _ELF_READER_

#include <elf.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct initvars - initial values to pass across the program
 * @p_name
 * @p_status
 * @elf_type
 */
typedef struct initvars_s {
	char *p_name;
	char *f_name;
	int f_size;
	_Bool elf_type;
	_Bool ELF_32bit;
	_Bool big_endian;
	FILE *f_stream;
	Elf64_Ehdr f_header;
} initvars_t;

void initvars(initvars_t *state);
void errorhandler(char *format, char *errorstring, initvars_t *state);
void freewilli(initvars_t *state);
int openfile(initvars_t *state);
int getfileheader(initvars_t *state);
int printfileheader(initvars_t *state);
const char *getosabi(unsigned char osabi);
const char *getelft(Elf64_Half e_type);
const char *getmname(Elf64_Half e_machine);

#endif /* _ELF_READER_ */