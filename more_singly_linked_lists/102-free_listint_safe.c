#include <stdlib.h>
#include "lists.h"

/**
 * get_loop_node - finds loop start node
 * @head: pointer to head of list
 *
 * Return: loop start node or NULL
 */
static listint_t *get_loop_node(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow != fast)
			continue;
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return (slow);
	}
	return (NULL);
}

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to pointer to head of list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *loop = get_loop_node(*h);
	listint_t *current = *h, *next;
	size_t count = 0;

	if (loop != NULL)
		loop->next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}
	*h = NULL;
	return (count);
}
