#include "monty.h"

/**
 * rotr - rotate last element of the stack becomes the top element
 * @inst: node of the stack
 * Return: 0 if is not succes
 */
int rotr(node_t *inst)
{
	stack_t *top = inst->head;
	int num;

	if (!inst->head || top->next == NULL)
		return (0);
	num = inst->tail->value;
	add_dnodeint(&top, num);
	inst->head = top;
	queue_pop(inst);

	return (1);
}
