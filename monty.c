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
	node_t *inst = init_node();
	size_t ma = 0, l = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_file(inst, EXIT_FAILURE);
	}
	inst->fd = fopen(argv[1], "r");

	if (!inst->fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_file(inst, EXIT_FAILURE);
	}

	while (getline(&inst->line, &ma, inst->fd) != -1)
	{
		inst->opcode = strtok(inst->line, " \n\t");
		inst->arg = strtok(NULL, " \n\t");
		if (inst->opcode == NULL)
		{
			inst->line_num++;
			continue;
		}
		argument_pass(inst);

		if (!check_opcode(inst))
		{
			l = inst->line_num;
			fprintf(stderr, "L%ld: unknown instruction %s\n", l, inst->opcode);
			free_all(inst, EXIT_FAILURE);
		}

		free(inst->line);
		inst->line = NULL;
		inst->line_num++;
	}

	free_all(inst, 0);
	return (0);
}

/**
 * free_file - free memory before malloc
 * @inst: main node
 * @error: num error
 *
 * Return: void
 */
void free_file(node_t *inst, int error)
{
	if (inst->fd)
		fclose(inst->fd);

	free(inst);
	exit(error);
}

/**
 * free_all - free all memory
 * @inst: main node
 * @error: num error
 *
 * Return: void
 */
void free_all(node_t *inst, int error)
{
	if (inst->head)
	{
		stack_t *tmp = inst->head;
		stack_t *next = NULL;

		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
	}

	fclose(inst->fd);
	free(inst->line);
	free(inst);

	exit(error);
}
