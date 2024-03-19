#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    if (*head == NULL) // Check if the list is empty
        return (-1);

    dlistint_t *current = *head;
    unsigned int i;

    // Move to the node at the specified index or to the last node if index is out of bounds
    for (i = 0; i < index && current != NULL; i++)
        current = current->next;

    // If current is NULL, index is out of bounds
    if (current == NULL)
        return (-1);

    if (current->prev != NULL) // Check if current is not the first node
        current->prev->next = current->next;
    else
        *head = current->next; // Update head if current is the first node

    if (current->next != NULL) // Check if current is not the last node
        current->next->prev = current->prev;

    free(current);
    return (1);
}
