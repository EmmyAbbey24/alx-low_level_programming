#include <stdlib.h>
#include "lists.h"

/**
 * free_list - Frees a linked list
 * @head: Pointer to the beginning of the list
 *
 * Description: This function frees the memory allocated for each
 * node in the linked list, including the strings stored in them.
 */
void free_list(list_t *head)
{
list_t *temp;

while (head)
{
temp = head->next;
free(head->str);
free(head);
head = temp;
}
}
