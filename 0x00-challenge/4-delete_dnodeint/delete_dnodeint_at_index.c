#include "lists.h"
#include <stdlib.h>

/**
 * delete_at_head - Delete a node at the head of the list
 *
 * @head: A pointer to the first element of a list
 *
 * Return: The new head of the list
 */
dlistint_t *delete_at_head(dlistint_t *head)
{
	dlistint_t *new_head = head->next;

	if (new_head != NULL)
		new_head->prev = NULL;
	free(head);
	return (new_head);
}

/**
 * delete_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: The new head of the list, or NULL on failure
 */
dlistint_t *delete_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *tmp = head;
	unsigned int p = 0;
	dlistint_t *node_to_delete;

	while (p < index - 1 && tmp != NULL)
	{
		tmp = tmp->next;
		p++;
	}

	if (p != index - 1 || tmp == NULL)
		return (NULL);

	node_to_delete = tmp->next;
	if (node_to_delete->next != NULL)
		node_to_delete->next->prev = tmp;
	tmp->next = node_to_delete->next;
	free(node_to_delete);
	return (head);
}

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
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = delete_at_head(*head);
		return (1);
	}

	*head = delete_at_index(*head, index);
	return ((*head != NULL) ? 1 : -1);
}
