#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_loop_start - finds loop start node
 * @head: pointer to head of list
 *
 * Return: loop start node or NULL
 */
static const listint_t *get_loop_start(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;

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
 * count_unique - counts unique nodes
 * @head: pointer to head
 * @loop: loop start node or NULL
 *
 * Return: total unique node count
 */
static size_t count_unique(const listint_t *head, const listint_t *loop)
{
	size_t pre = 0, in_loop = 0;
	const listint_t *cur;

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
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *loop = get_loop_start(head);
	size_t total = count_unique(head, loop);
	size_t i = 0;

	while (i < total)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		i++;
		if (i == total && loop != NULL)
			printf("-> [%p] %d\n", (void *)head->next, head->next->n);
		head = head->next;
	}
	return (total);
}
