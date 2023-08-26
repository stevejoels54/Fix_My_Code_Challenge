#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (index == 0)
	{
		tmp = (*head)->next;
		if (tmp != NULL)
			tmp->prev = NULL;
		free(*head);
		*head = tmp;
	}
	else
	{
		tmp = (*head)->next;
		while (p < index - 1 && tmp != NULL)
		{
			tmp = tmp->next;
			p++;
		}
		if (p != index - 1 || tmp == NULL)
		{
			*head = saved_head;
			return (-1);
		}
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		free(tmp);
		*head = saved_head;
	}
	return (1);
}