#include "monty.h"
/**
 * add_dnodeint - function that adds a new node at the beginnig
 * @head: list
 * @n: number of new node
 * Return: the new node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL, *aux;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (NULL);
	}
	aux = *head;
	if (*head == NULL)
	{
		new->value = n;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	while (aux)
	{
		if (aux->prev != NULL)
		{
			aux = aux->prev;
			continue;
		}
		new->value = n;
		new->prev = NULL;
		new->next = aux;
		break;
	}
	*head = new;
	return (*head);

}
