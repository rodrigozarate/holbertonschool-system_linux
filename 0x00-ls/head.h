#ifndef _MYOWNLS_
#define _MYOWNLS_


/* april 11, 2022 */
/* Rodrigo Zarate Algecira */
/* Low Level and Algorithms Program */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdint.h>

/**
* struct list_s - structure for node list
* @str: char
* @len: unit
* @next: pointer
*/

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* for nodes */
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);

/* errors */
void handle_errors(char *directory, char const *prog_name);

/* functions */
void xreturner(list_t *head, int *options, char const *prog_name);
void display_with_options(list_t *head, int *options, int flag_many,
				char const *prog_name);
list_t *handle_args(int argc, char const *argv[], int *options);
void read_local(char *head, int *options);
void print_full(struct dirent *read);
void display_line(char *read, int *options);
void flag_overload(struct dirent *read, int *options);

/* handle strings */
char *_strncpy(char *dest, char const *src, int n);
int _strlen(char const *s);
char *_strdup(const char *str);
int _strcmp(char const *s1, char *s2);

#endif
