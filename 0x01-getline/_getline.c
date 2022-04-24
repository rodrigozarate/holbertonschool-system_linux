#include "_getline.h"

/**
 *  _getline - My own getline
 * @fd: the file descriptor
 * Return: string or NULL on error
 */
char *_getline(const int fd)
{
	int i, buffersize, outputsize = 0;
	char *buffer, *output = NULL;
	fdes_t *list;
	ssize_t *line;

	list = getnode(fd);
	if (fd == -1 || !list)
		return (NULL);
	buffer = list->buffer;
	while (1)
	{
		if (*line > 0)
		{
			buffersize = 0;
			while (buffer[buffersize] != '\n' && buffersize < *line)
				buffersize++;
			output = realloc(output, sizeof(*output)
								* (outputsize + buffersize + 1));
			for (i = 0; i < buffersize; i++)
				output[outputsize + i] = buffer[i];
			output[outputsize + buffersize] = '\0';
			outputsize += buffersize;
			movenode(buffer, buffer + buffersize);
			*line = *line - buffersize;
			if (*buffer == '\n')
			{
				movenode(buffer, buffer + 1);
				*line = *line - 1;
				break;
			}
		}
		*line = read(fd, buffer, READ_SIZE);
		if (*line == -1)
			return (NULL);
		buffer[*line] = '\0';
		if (*line == 0)
			break;

	}
	return (output);
}

/**
 * getnode - get the node
 * @fd: file descriptor
 * Return: NULL on -1 of new node
 */
fdes_t getnode(const int fd)
{
	static fdes_t *head;
	fdes_t *newnode;

	if (fd == -1)
	{
		freenode(head);
		head = NULL;
		return (NULL);
	}

	newnode = head;
	while (newnode && newnode->fd != fd)
		newnode = newnode->next;

	if (newnode == NULL)
		newnode = addnode(&head, fd);
	return (newnode);
}

/**
 * addnode - adds a node
 * @head: double pointer
 * @fd: file descriptor
 * Return: new node
 */
fdes_t *addnode(fdes_t **head, const int fd)
{
	fdes_t *newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->fd = fd;
	newnode->next = NULL;
	newnode->inbuf = 0;
	memset(newnode->buffer, 0, READ_SIZE);

	if (*head != NULL)
		newnode->next = *head;

	*head = newnode;
	return (newnode);
}

/**
 * movenode - move the node
 * @output: final string
 * @origin: inception
 * Return: The output
 */
char *movenode(char *output, char *origin)
{
	int i;
	int distance = (origin - output);

	for (i = 0; i < READ_SIZE; i++)
	{
		if (i + distance < READ_SIZE)
			output[i] = origin[i];
		else
			output[i] = '\0';
	}
	return (output);
}

/**
 * freenode - Free Willi
 * @head: pointer
 */
void freenode(fdes_t *head)
{
	if (head)
		freenode(head->next);
	free(head);
}
