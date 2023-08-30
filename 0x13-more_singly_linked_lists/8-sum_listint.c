#include "lists.h"

/**
 * sum_listint - Returns the sum of all the data (n) in a listint_t list.
 * @head: A pointer to the head of the list.
 *
 * Return: The sum of all the data, or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *latest = head;

while (latest != NULL)
{
sum += latest->n;
latest = latest->next;
}

return (sum);
}
