#include "methods.h"
#include "stack.h"

/**
 * get_methods - return function opcode
 * @main: main node
 *
 * Return: address to function
 */
fun get_methods(node_t *main)
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

	unsigned int i;

	for (i = 0; stack_methods[i].opcode; i++)
	{
		if (!strcmp(stack_methods[i].opcode, main->opcode))
		{
			return (stack_methods[i].f);
		}
	}

	return (NULL);
}