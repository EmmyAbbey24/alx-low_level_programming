#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index of a listint_t list.
 * @head: A pointer to a pointer to the head of the list.
 * @index: The index of the node to be deleted, starting at 0.
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *latest, *temp;
unsigned int count = 0;

if (head == NULL || *head == NULL)
return (-1);

if (index == 0)
{
temp = *head;
*head = (*head)->next;
free(temp);
return (1);
}

latest = *head;

while (latest != NULL)
{
if (count == index - 1)
{
if (latestt->next == NULL)
return (-1);

temp = latest->next;
latest->next = temp->next;
free(temp);
return (1);
}
latest = latest->next;
count++;
}

return (-1);
}

