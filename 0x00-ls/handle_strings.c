#include "head.h"

/**
*_strncpy - 0
*@dest: string
*@src: string
*@n: int
*Return: dest
*/
char *_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (i = 0; i < n && src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
