/*
* display.c: compose the display
* Author: Rodrigo Zárate Algecira
* Date: April 11, 2022
*/

#include "head.h"

/**
* print_full - several
* @read: node
*/
void print_full(struct dirent *read)
{
	struct stat fileStat;
	struct group *grp;
	struct passwd *user;
	char *time;

	lstat((*read).d_name, &fileStat);
	user = getpwuid(fileStat.st_uid);
	grp = getgrgid(fileStat.st_gid);
	time = ctime(&(fileStat.st_mtime));
	time[16] = '\0';
	time = time + 4;

	printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf(" %lu", fileStat.st_nlink);
	printf(" %s %s", (*user).pw_name, (*grp).gr_name);
	printf(" %li",  (intmax_t)fileStat.st_size);
	printf(" %s %s\n", time, (*read).d_name);
}

/**
* display_line - single
* @read: node
* @options: options
*/
void display_line(char *read, int *options)
{
	if (options[0] == 1)
	{
		printf("%s\n", read);
	}
	else
	{
		 printf("%s ", read);
	}
}
