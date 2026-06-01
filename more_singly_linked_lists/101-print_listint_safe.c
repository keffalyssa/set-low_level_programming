#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * get_loop_start - finds the node where a loop begins
 * @head: pointer to head of list
 *
 * Return: pointer to loop start node, or NULL if no loop
 */
static listint_t *get_loop_start(const listint_t *head)
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
		return ((listint_t *)slow);
	}
	return (NULL);
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *loop = get_loop_start(head);

	while (head != NULL)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		if (head->next == loop && loop != NULL)
		{
			printf("-> [%p] %d\n", (void *)loop, loop->n);
			return (count);
		}
		head = head->next;
	}
	return (count);
}
