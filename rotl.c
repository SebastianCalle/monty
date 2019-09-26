#include "monty.h"

/**
 * rotl - rotathes the stack to the top
 * @inst: node the stack
 * Return: 1 if is succes or 0 if not
 */
int rotl(node_t *inst)
{
	stack_t *top = inst->head;
	stack_t *top2 = inst->head;
	stack_t *aux = top->next;

	if (!inst->head)
		return (0);
	while (top->next)
	{
		top = top->next;
	}
	inst->head = aux;
	top->next = top2;
	top2->next = NULL;

	return (1);
}
