#include "head.h"

/**
* _strncpy - copy a string
* @dest: string
* @src: string
* @n: int
* Return: dest
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

/**
* _strlen - Measure string
* @s: char
* Return: i
*/

int _strlen(char const *s)
{
	int i = 0;

	if (s != NULL)
	{
		while (*s != '\0')
		{
			s++;
			i++;
		}
	}
	return (i);
}

/**
* _strdup - duplicate string
* @str: pointer
* Return: Pointer to new string
*/
char *_strdup(const char *str)
{
	int len;
	int i;
	char *s;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	s = malloc(sizeof(*s) * (len + 1));
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
