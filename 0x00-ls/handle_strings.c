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

/**
* _strcmp - compare two strings for lenght and equality of each char
* @s1: origin string
* @s2: compare string
* Return: int
*/
int _strcmp(char const *s1, char *s2)
{
	int j = 0, i = 0;

	while (s1[i] != '\0')
	{
		i++;
	}

	while (s1[j] == s2[j] && j < i)
	{
		j++;
	}

	return (s1[j] - s2[j]);
}
