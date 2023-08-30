#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
listint_t *latest, *temp;

if (head == NULL)
return;

latest = *head;

while (current != NULL)
{
temp = latest;
latest = latest->next;
free(temp);
}

*head = NULL;
}
