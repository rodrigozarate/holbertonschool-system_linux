#ifndef _MYOWNLS_
#define _MYOWNLS_


/* april 11, 2022 */
/* Rodrigo Zarate Algecira */
/* Low Level and Algorithms Program */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

void free_list(list_t *head);

/* functions */
void returner(list_t *head, int *options);
list_t *handle_args(int argc, char const *argv[], int *options);

#endif
