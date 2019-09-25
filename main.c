#include "methods.h"
#include "stack.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0 (Success)
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	instruction_t stack_methods[] = {
			{"queue", toggle_type},
			{"stack", toggle_type},
			{"push", stack_push},
			{"pop", stack_pop},
			{"pall", pall},
			{"pint", pall},
			{NULL, NULL}
	};

	FILE *fd = fopen(argv[1], "r");
	node_t *main = init_main_node();
	fun f = NULL;

	while (parse(fd, main))
	{
		f = get_methods(main, stack_methods);

		if (f) /* Execute function by opcode */
			f(main);

		free(main->opcode);
	}

	free_stack(main, fd);
}

/**
 * init_main_node - create new main node
 *
 * Return: new main node address
 */
node_t *init_main_node(void)
{
	node_t *main = malloc(sizeof(node_t)); /* Create main node */

	if (!main) /* If there is an error creating the main node */
		return (NULL);

	main->head = NULL;  /* head of the stack */
	main->tail = NULL;  /* tail of the stack */
	main->type = STACK; /* stack by default  */

	return (main);
}

/**
 * parse - parse line of the file
 * @fd: file descriptor
 * @main: main node
 *
 * Return: Always 1 (Success) : 0
 */
int parse(FILE *fd, node_t *main)
{
	char line[50] = {0};
	char *arg = NULL;

	if (!fgets(line, 50, (FILE *) fd))
		return (0);

	main->opcode = strdup(strtok(line, " \n\t"));
	arg = strtok(NULL, " \n\t");
	main->arg = arg ? atoi(arg) : 0;

	return (1);
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