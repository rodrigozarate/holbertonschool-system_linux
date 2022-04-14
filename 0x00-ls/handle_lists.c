#include "head.h"
/**
 * add_node - Self explanatory
 * @head: pointer
 * @str: string to add
 * Return: Address of the new element or NULL
 */
list_t *add_node(list_t **head, const char *str)
{
	char *c;
	int i;
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	c = _strdup(str);
	if (c == NULL)
	{
		free(new);
		return (NULL);
	}

	for (i = 0; str[i];)
		i++;

	new->str = c;
	new->len = i;
	new->next = *head;

	*head = new;

	return (new);
}
/**
 * free_list - free Willy
 * @head: pointer
 */
void free_list(list_t *head)
{
	list_t *p;

	while (head)
	{
		p = head->next;
		free(head->str);
		free(head);
		head = p;
	}
}
