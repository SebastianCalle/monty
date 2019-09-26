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
	int n = 0, flag, l = 1;
	node_t *inst = NULL;
	char line[10000];
	char **args;
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!(fd = fopen(argv[1], "r")))
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	inst = init_node();
	while (fgets(line, 10000, (FILE *) fd))
	{
		args = _strtok(line, &n);
		if (args == NULL || args[0] == NULL)
			continue;
		inst->opcode = args[0];
		inst->arg = argument_pass(args, l, inst, fd);
		flag = check_opcode(args, inst);
		if (flag == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, args[0]);
			exit(EXIT_FAILURE);
		}
		l++;
		n = 0;
		free(args[0]);
		free(args[1]);
		free(args);
	}
	free_stack(inst, fd);
	return (0);
}
