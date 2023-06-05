#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: Pointer to the head node of the list.
 * @index: Index of the node to retrieve, starting at 0.
 *
 * Return: If the node at the given index exists, return a pointer to it.
 *         Otherwise, return NULL.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current = head;
	unsigned int i;

	for (i = 0; i < index; i++)
	{
		if (current == NULL)
			return NULL;

		current = current->next;
	}

	return current;
}
