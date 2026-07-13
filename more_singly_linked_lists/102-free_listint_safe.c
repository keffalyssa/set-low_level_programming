#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *curr, *next_node;
size_t len = 0;
long int diff;

if (h == NULL || *h == NULL)
return (0);

curr = *h;
while (curr != NULL)
{
diff = curr - curr->next;
if (diff > 0)
{
next_node = curr->next;
free(curr);
curr = next_node;
len++;
}
else
{
free(curr);
curr = NULL;
len++;
break;
}
}

*h = NULL;
return (len);
}
