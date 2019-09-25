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
		if (!strcmp(args[0], stack_methods[i].opcode))
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
