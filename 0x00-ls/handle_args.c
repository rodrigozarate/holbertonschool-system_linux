#include "head.h"

/**
 * handle_args - options
 * @argc: count
 * @argv: argument itself
 * @options: options
 * Return: object
*/

list_t *handle_args(int argc, char const *argv[], int *options)
{
	int i = 1, j = 1;
	list_t *file_names = NULL;

	while (i < argc)
	{
		if (argv[i][0] == '-' && _strlen(argv[i]) > 1)
		{
			j = 1;
			while (_strlen(argv[i]) > j)
			{
				switch (argv[i][j])
				{
				case '1':
					options[0] = 1;
					break;
				case 'l':
					options[1] = 1;
					break;
				case 'a':
					options[2] = 1;
					break;
				case 'A':
					options[3] = 1;
					break;
				default:
					break;
				}
				j++;
			}
		}
		else
		{
		   file_names = add_node(&file_names, argv[i]);
		}
		i++;
	}
	return (file_names);
}
