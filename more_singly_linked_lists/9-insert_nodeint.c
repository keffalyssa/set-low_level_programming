#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: A pointer to the pointer of the head of the list.
 * @idx: The index of the list where the new node should be added.
 * @n: The data (integer) to insert in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	/* If inserting at the very beginning (index 0) */
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	temp = *head;
	/* Traverse the list to find the node just before the insertion point */
	for (i = 0; temp != NULL && i < idx - 1; i++)
	{
		temp = temp->next;
	}

	/* If idx is out of range, temp will be NULL */
	if (temp == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Insert the new node into the list */
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
