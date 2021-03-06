/*
* xreturner.c: compose the return
* Author: Rodrigo Zárate Algecira
* Date: April 11, 2022
*/

#include "head.h"

/**
* xreturner - the one that returns
* @file_names: stream nodes
* @options: self explanatory
* @prog_name: main program name char pointer
*/

void xreturner(list_t *file_names, int *options, char const *prog_name)
{
	list_t *head = file_names;
	int flag_many = 0;

	if (head == NULL)
	{
		read_local(".", options);
		return;
	}

	if (head->next)
	{
		flag_many = 1;
	}

	while (head != NULL)
	{
		display_with_options(head, options, flag_many, prog_name);
		head = head->next;
	}
}

/**
* display_with_options - self explanatory
* @head: nodes
* @options: self explanatory
* @flag_many: indicate if file_names must be parsed or not
* @prog_name: main program name char pointer
*/
void display_with_options(list_t *head, int *options, int flag_many,
				char const *prog_name)
{
	DIR *dir;
	struct dirent *read;
	char *ilname;

	ilname = head->str;
	dir = opendir(ilname);
	if (errno == 20)
	{
		if (flag_many == 0)
			printf("%s\n", ilname);
		errno = 0;
	}

	if (errno == 22)
		errno = 0;

	if (dir != NULL)
		read = readdir(dir);

	if (flag_many == 1 && errno == 0)
	{
		if (read->d_type == DT_DIR)
		{
			printf("%s:\n", ilname);
		}
		else
		{
			printf("%s\n", ilname);
		}
	}

	if (dir != NULL)
	{
		/* read = readdir(dir);*/
		while (read != NULL)
		{
			if (options[1] == 1)
			{
				print_full(read);
				options[0] = 1;
			}
			else
			{
				flag_overload(read, options);
			}
			read = readdir(dir);
		}
		if (head->next != NULL || errno != 0)
			printf("\n");
	}

	if (errno != 0)
	{
		handle_errors(head->str, prog_name);
	}

	if (options[0] != 1 && errno == 0)
		printf("\n");

	closedir(dir);
}

/**
* read_local - read dir
* @head: node
* @options: self explanatory
*/
void read_local(char *head, int *options)
{
	DIR *dir;
	struct dirent *read;
	int onet, twot;

	dir = opendir(head);
	if (dir != NULL)
	{
		read = readdir(dir);
		while (read != NULL)
		{
			if (options[1] == 1)
			{
				onet = _strcmp(read->d_name, ".");
				twot = _strcmp(read->d_name, "..");
				if (onet && twot)
				{
					print_full(read);
					options[0] = 1;
				}
			}
			else
			{
				flag_overload(read, options);
			}
			read = readdir(dir);
		}
	}
	if (options[0] != 1)
		printf("\n");

	closedir(dir);
}

/**
* flag_overload - just in case
* @read: the args
* @options: the options
*/
void flag_overload(struct dirent *read, int *options)
{
	int onep, twop;

	if (options[2] == 1)
	{
		display_line(read->d_name, options);
	}
	else
	{
		onep = _strcmp(read->d_name, ".");
		twop = _strcmp(read->d_name, "..");
		if (options[3] == 1 && onep && twop)
			display_line(read->d_name, options);
		else
			if (read->d_name[0] != '.')
				display_line(read->d_name, options);
	}
}
