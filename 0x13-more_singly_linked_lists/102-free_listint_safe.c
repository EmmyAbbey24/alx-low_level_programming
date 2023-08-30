#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list, even if there's a loop.
 * @h: A pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
listint_t *latest, *temp;

if (h == (listint_t **)NULL)
return (count);

latestt = *h;

while (latest != (listint_t *)NULL)
{
temp = latest;
latest = latest->next;
free(temp);
count++;

// Break if loop detected
if (temp->next >= temp)
{
*h = (listint_t *)NULL;
break;
}
}

return (count);
}
