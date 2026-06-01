#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count, loop_pos, i;
	const listint_t *slow, *fast, *loop_node, *current;

	slow = head;
	fast = head;
	loop_node = NULL;

	/* Floyd's cycle detection */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			loop_node = slow;
			break;
		}
	}

	/* Find the start of the loop */
	if (loop_node != NULL)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		loop_node = slow; /* loop_node now points to loop entry */
	}

	/* Count nodes before loop */
	count = 0;
	loop_pos = 0;
	current = head;
	if (loop_node != NULL)
	{
		while (current != loop_node)
		{
			current = current->next;
			loop_pos++;
		}
		/* Count nodes in loop */
		current = loop_node;
		do {
			current = current->next;
			loop_pos++;
		} while (current != loop_node);
		count = loop_pos;
	}

	/* Print the list */
	current = head;
	i = 0;
	if (loop_node == NULL)
	{
		/* No loop - print all */
		while (current != NULL)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			current = current->next;
			count++;
		}
	}
	else
	{
		/* Print until we reach loop entry again */
		while (i < count)
		{
			printf("[%p] %d\n", (void *)current, current->n);
			if (current->next == loop_node && i == count - 1)
			{
				printf("-> [%p] %d\n",
					(void *)loop_node, loop_node->n);
			}
			current = current->next;
			i++;
		}
	}

	return (count);
}
