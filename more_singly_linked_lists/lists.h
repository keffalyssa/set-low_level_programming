#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *insert_nodeint_at_index(listint_t **head,
unsigned int idx, int n);
int delete_nodeint_at_index(listint_t **head,
unsigned int index);

#endif
int sum_listint(listint_t *head);
listint_t *reverse_listint(listint_t **head);
size_t print_listint_safe(const listint_t *head);
