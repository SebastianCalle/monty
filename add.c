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
 * sub - function that substract the top element of the stack
 * @inst: node manage of stack
 *
 * Return: 0 if susccess or 1 if not
 */
int sub(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	inst->head->next->value = num2 - num1;
	stack_pop(inst);
	return (0);
}
/**
 * divide - function that divide the top element of the stack
 * @inst: node manage of stack
 *
 * Return: 0 if susccess or 1 if not
 */
int divide(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", inst->line_num);
		free_all(inst, 1);

	}
	inst->head->next->value = num2 / num1;
	stack_pop(inst);
	return (0);
}
/**
 * multiply - function that multiplicate the top element of the stack
 * @inst: node manage of stack
 *
 * Return: 0 if susccess or 1 if not
 */
int multiply(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	inst->head->next->value = num2 * num1;
	stack_pop(inst);
	return (0);
}
/**
 * mod - function that module the top element of the stack whit seconde element
 * @inst: node manage of stack
 *
 * Return: 0 if susccess or 1 if not
 */
int mod(node_t *inst)
{
	int num1, num2;

	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", inst->line_num);
		free_all(inst, 1);
	}

	num2 = inst->head->next->value;
	num1 = inst->head->value;

	if (num1 == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", inst->line_num);
		free_all(inst, 1);

	}
	inst->head->next->value = num2 % num1;
	stack_pop(inst);
	return (0);

}
