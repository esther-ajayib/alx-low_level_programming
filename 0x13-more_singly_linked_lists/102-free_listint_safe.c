#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h;
	size_t count = 0;

	while (current != NULL)
	{
		listint_t *next = current->next;

		free(current);
		count++;

		if (next >= current)
		{
			*h = NULL;
			break;
		}

		current = next;
	}

	return (count);
}

