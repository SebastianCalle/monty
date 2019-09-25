#include "methods.h"

/**
 * get_methods - return function opcode
 * @main: main node
 *
 * Return: address to function
 */
fun get_methods(node_t *main,  instruction_t *stack_methods)
{
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