#include "monty.h"
#include <string.h>
#include <ctype.h>
/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char line[10000];
	char **args;
	FILE *fd;
	int n = 0, flag, l = 1;
	node_t *inst = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
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
			fprintf(stderr, "USAGE: monty file\n");
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
