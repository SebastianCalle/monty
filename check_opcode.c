#include "monty.h"

/**
 * check_opcode - function that check if opcode exist
 * @args: arguments to check
 * @ints: node for the stack
 * Return: 1 if succesful or 0 if not
 */
int check_opcode(char **args, node_t *ints)
{
	int i;
	instruction_t stack_methods[] = {
			{"queue", toggle_type},
			{"stack", toggle_type},
			{"push", stack_push},
			{"pop", stack_pop},
			{"pall", pall},
			{"pint", pall},
			{NULL, NULL}
	};

	for (i = 0; i < 7; i++)
	{
		if (stack_methods[i].opcode && !strcmp(args[0], stack_methods[i].opcode))
		{
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

	if (!inst) /* If there is an error creating the main node */
		return (NULL);

	inst->head = NULL;  /* head of the stack */
	inst->tail = NULL;  /* tail of the stack */
	inst->line = NULL;
	inst->type = STACK; /* stack by default  */
	return (inst);
}
/**
 * free_stack - toggle type of the stack - queue
 * @main: main node
 * @fd: file descriptor
 *
 * Return: void
 */
void free_stack(node_t *main, FILE *fd)
{
	free(main->line);
	if (main->head)
	{
		stack_t *tmp = main->head;
		stack_t *next = NULL;

		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
	}

	fclose(fd);
	free(main);
}
/**
 * argument_pass - check if the argument is a digit
 * @args: str to check
 * @l: number line
 * @inst: ...
 * @fd: file descriptor
 *
 * Return: the number of arg or error
 */
int argument_pass(char **args, int l, node_t *inst, FILE *fd)
{
	int num = 0;
	unsigned int i;
	char *str = args[1];

	if (strcmp(args[0], "push") == 0 && !args[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		free_memory_int_error(args, inst, fd);
	}

	if (strcmp(args[0], "push") == 0)
	{
		for (i = 0; i < strlen(str); i++)
		{
			if (isdigit(str[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", l);
				free_memory_int_error(args, inst, fd);
			}

		}
		num = atoi(args[1]);
	}
	return (num);

}
/**
 * free_memory_int_error - free memory int error
 * @args: str to check
 * @inst: ...
 * @fd: file descriptor
 *
 * Return: the number of arg or error
 */
void free_memory_int_error(char **args, node_t *inst, FILE *fd)
{
	free(args[0]);
	free(args[1]);
	free(args);

	free_stack(inst, fd);
	exit(EXIT_FAILURE);
}