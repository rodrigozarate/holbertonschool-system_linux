/*
* main.c: Emulation of ls command
* Author: Rodrigo Zárate Algecira
* Date: April 11, 2022
*/

#include "head.h"

/**
* main - my own ls command
* @argc: counter
* @argv: arguments
* Return: exit Success or Failure
*/

int main(int argc, char const *argv[])
{
	list_t *file_names = NULL;
	list_t *head = NULL;
	int options[4] = {0, 0, 0, 0};

	file_names = handle_args(argc, argv, options);
	head = file_names;

	xreturner(head, options);

	free_list(head);
	return (0);
}
