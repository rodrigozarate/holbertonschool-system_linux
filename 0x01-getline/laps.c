#include "laps.h"

/**
 * race_state - Keep track of the number of laps made by several cars in a race
 * @id: array of int identifier of a car (unique)
 * @size: the size of the array
 */
void race_state(int *id, size_t size)
{
	size_t i;
	static cardef_t *head;
	cardef_t *newcar;

	/* if functions is called with size = 0 free all memory */
	if (size == 0)
	{
		free_car(head);
		return;
	}
	/* get array */
	for (i = 0; i < size; i++)
	{
		newcar = get_car(head, id[i]);
		/* if new element add node else print state and sum 1 */
		/* number of laps +1 for all cars in identifier */
		if (newcar)
		{
			newcar->laps++;
		}
		else
		{
			/* if identifier is unknown */
			/* store array element if not in keys */
			add_car(&head, id[i]);
			/* create a new car with laps = 0 */
			/* Print Car X joined the race \n X = identifier */
			printf("Car %d joined the race\n", id[i]);

		}
	}
	/* Each time the function is called */
	/* print state of race */
	/* HEADER Race state: \n */
	print_race(head);
}

/**
 * add_car - insert node
 * @head: list pointer
 * @id: id to insert
 * Return: pointer to new node
 */
cardef_t *add_car(cardef_t **head, int id)
{
	cardef_t *newnode, *car;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->id = id;
	newnode->laps = 0;
	newnode->next = NULL;

	if (*head == NULL || (*head)->id > id)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	car = *head;
	while (car->next)
	{
		if (car->next->id >= id)
		{
			newnode->next = car->next;
			break;
		}
		car = car->next;
	}
	car->next = newnode;
	return (newnode);
}

/**
 * get_car - get the info of the car
 * @head: pointer
 * @id: id to find
 * Return: car id if found
 */
cardef_t *get_car(cardef_t *head, int id)
{
	cardef_t *car;

	for (car = head; car; car = car->next)
		if (car->id == id)
			break;
	return (car);
}

/**
 * print_race - Print race status
 * @head: pointer
 */
void print_race(cardef_t *head)
{
	cardef_t *car;

	printf("Race state:\n");
		for (car = head; car; car = car->next)
			/* Car X [Y laps] */
			printf("Car %d [%d laps]\n", car->id, car->laps);
}

/**
 * free_car - free willi
 * @head: pointer to first element of list
 */
void free_car(cardef_t *head)
{
	if (!head)
		return;
	free_car(head->next);
	free(head);

}
