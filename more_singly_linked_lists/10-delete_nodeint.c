#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A pointer to the pointer of the head of the list.
 * @index: The index of the node that should be deleted. Index starts at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *next_node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* If the node to be deleted is the first node (index 0) */
	if (index == 0)
	{
		*head = temp->next;
		free(temp);
		return (1);
	}

	/* Traverse to find the node just before the one we want to delete */
	for (i = 0; temp != NULL && i < index - 1; i++)
	{
		temp = temp->next;
	}

	/* If index is out of bounds or the node to delete doesn't exist */
	if (temp == NULL || temp->next == NULL)
		return (-1);

	/* next_node is the node to be deleted */
	next_node = temp->next;

	/* Unlink the deleted node from the list */
	temp->next = next_node->next;

	/* Free memory of the deleted node */
	free(next_node);

	return (1);
}
