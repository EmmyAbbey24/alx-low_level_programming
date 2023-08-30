#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list even if there's a loop.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *latest, *next;
size_t count = 0;

if (h == NULL || *h == NULL)
return (0);

latest = *h;
while (latest != NULL)
{
next = latest->next;
free(latest);
count++;

if ((size_t)latest <= (size_t)next)
break;

latest = next;
}

*h = NULL;
return (count);
}
