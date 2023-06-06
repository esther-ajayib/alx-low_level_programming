#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position
 * @head: Pointer to the head of the list
 * @idx: Index where the new node should be added
 * @n: Value to be assigned to the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 1;
	listint_t *new_node, *current;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		new_node->n = n;
		return (new_node);
	}

	if (idx == 0)
	{
		new_node->next = *head;
		new_node->n = n;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	while (i < idx)
	{
		current = current->next;
		i++;
	}

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
