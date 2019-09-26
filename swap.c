#include "monty.h"

/**
 * swap - function that swap the top of the stack
 * @inst: node manage of stack
 * Return: 0 if suscces or 1 if not
 */
int swap(node_t *inst)
{
	stack_t *tmp = inst->head;
	int swp;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr,"L<line_number>: can't swap, stack too shortu");
		exit(EXIT_FAILURE);
	}

	swp = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = swp;

	inst->head = tmp;
	inst->head->next = tmp->next;

	return (0);
}
