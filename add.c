#include "monty.h"

/**
 * add - function that add the top of the stack
 * @inst: node manage of stack
 *
 * Return: 0 if suscces or 1 if not
 */
int add(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	inst->head->next->value = num1 + num2;
	stack_pop(inst);
	return (0);
}

/**
 * sub - function that substract the top element of the stack whit seconde element
 * @inst: node manage of stack
 *
 * Return: 0 if susccess or 1 if not
 */
int sub(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	inst->head->next->value = num2 - num1;
	stack_pop(inst);
	return (0);
}
