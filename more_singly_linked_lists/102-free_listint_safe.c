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
 * count_unique - counts unique nodes in list
 * @head: pointer to head
 * @loop: loop start node or NULL
 *
 * Return: total unique node count
 */
static size_t count_unique(listint_t *head, listint_t *loop)
{
	size_t pre = 0, in_loop = 0;
	listint_t *cur;

	if (loop == NULL)
	{
		while (head != NULL)
		{
			pre++;
			head = head->next;
		}
		return (pre);
	}
	cur = head;
	while (cur != loop)
	{
		pre++;
		cur = cur->next;
	}
	cur = loop;
	do {
		in_loop++;
		cur = cur->next;
	} while (cur != loop);
	return (pre + in_loop);
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
	size_t total = count_unique(*h, loop);
	size_t count = 0;
	listint_t *current = *h, *next;

	while (count < total)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}
	*h = NULL;
	return (total);
}
