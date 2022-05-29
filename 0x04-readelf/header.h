#ifndef _ELF_READER_
#define _ELF_READER_

#include <elf.h>
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
	_Bool elf_type;
	FILE *f_stream;
} initvars_t;

void initvars(initvars_t *state);
void errorhandler(char *format, char *errorstring, initvars_t *state);
void freewilli(initvars_t *state);
int openfile(initvars_t *state);
int getfileheader(initvars_t *state);
int printfileheader(initvars_t *state);

#endif /* _ELF_READER_ */