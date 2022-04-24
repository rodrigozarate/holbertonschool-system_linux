#ifndef _MY_GETLINE_H_
#define _MY_GETLINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_SIZE 2

/**
 * struct fdes_s - struct
 * @fd: file descriptor
 * @inbuf: info in buffer
 * @buffer: buffer
 * @next: next structure 
 */
typedef struct fdes_s
{
	int fd;
	ssize_t inbuf;
	char buffer[READ_SIZE];
	struct fdes_s *next;
} fdes_t;

char *_getline(const int fd);
fdes_t getnode(const int fd);
fdes_t *addnode(fdes_t **head, const int fd);
char *movenode(char *output, char *origin);
void freenode(fdes_t *head)

#endif