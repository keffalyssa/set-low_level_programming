#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node and returns its data
 * @head: pointer to the pointer of the head of the list
 *
 * Return: head node's data (n), or 0 if list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int n;

	if (*head == NULL)
		return (0);

	tmp = *head;
	n = tmp->n;
	*head = (*head)->next;
	free(tmp);

	return (n);
}
