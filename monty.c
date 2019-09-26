#include "monty.h"
#include <string.h>

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int n = 0, flag, i;
	node_t *inst = NULL;
	size_t ma = 0;
	char **args;
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	inst = init_node(), inst->fd = fd;
	while (getline(&inst->line, &ma, fd) != -1)
	{
		args = _strtok(inst->line, &n);
		if (args == NULL || args[0] == NULL)
			continue;
		inst->opcode = args[0];
		inst->arg = argument_pass(args, inst->line_num, inst, fd);
		flag = check_opcode(args, inst);
		if (flag == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", inst->line_num, args[0]);
			free_memory_int_error(args, inst, fd);
			exit(EXIT_FAILURE);
		}
		inst->line_num++;
		n = 0;
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
	}
	free_stack(inst, fd);
	return (0);
}
