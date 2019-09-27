#include "monty.h"

/**
 * check_opcode - function that check if opcode exist
 * @ints: node for the stack
 *
 * Return: 1 if succesful or 0 if not
 */
int check_opcode(node_t *ints)
{
	int eval = 0;
	int i;

	instruction_t stack_methods[] = {
			{"queue", toggle_type}, {"stack", toggle_type},
			{"push", stack_push}, {"pop", stack_pop},
			{"pall", pall}, {"pint", pall},
			{"swap", swap}, {"add", add},
			{"sub", sub}, {"div", divide},
			{"mul", multiply}, {"mod", mod},
			{"pchar", pchar}, {"pstr", pstr},
			{"rotl", rotl}, {"rotr", rotr},
			{"nop", NULL}, {NULL, NULL}
	};

	if (ints->opcode[0] == '#')
		return (1);

	for (i = 0; stack_methods[i].opcode; i++)
	{
		eval = stack_methods[i].opcode ? 1 : 0;
		if (eval && !strcmp(ints->opcode, stack_methods[i].opcode))
		{
			if (strcmp(ints->opcode, "nop"))
				stack_methods[i].f(ints);

			return (1);
		}
	}

	return (0);
}
/**
 * init_node - create new main node
 *
 * Return: new main node address
 */
node_t *init_node()
{
	node_t *inst = malloc(sizeof(node_t)); /* Create main node */

	if (!inst)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	inst->head = NULL;  /* head of the stack */
	inst->tail = NULL;  /* tail of the stack */
	inst->line = NULL;  /* current line      */
	inst->type = STACK; /* stack by default  */
	inst->fd   = NULL;
	inst->line_num = 1;
	return (inst);
}

/**
 * argument_pass - check if the argument is a digit
 * @inst: ...
 *
 * Return: the number of arg or error
 */
int argument_pass(node_t *inst)
{
	unsigned int i;

	if (strcmp(inst->opcode, "push") == 0 && !inst->arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", inst->line_num);
		free_all(inst, EXIT_FAILURE);
	}

	if (strcmp(inst->opcode, "push") == 0)
	{
		for (i = 0; i < strlen(inst->arg); i++)
		{
			if (i == 0 && (inst->arg[i] == '-' || inst->arg[i] == '+'))
				continue;

			if (isdigit(inst->arg[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", inst->line_num);
				free_all(inst, EXIT_FAILURE);
			}
		}
	}

	return (1);
}
