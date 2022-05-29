#ifndef _ELF_READER_
#define _ELF_READER_

/**
 * struct initvars - initial values to pass across the program
 * @p_name
 * @p_status
 * @elf_type
 */
typedef struct initvars_s {
	char *p_name;
	char *f_name;
	bool elf_type;
} initvars_t;

#endif /* _ELF_READER_ */