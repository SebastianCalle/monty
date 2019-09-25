#include "queue.h"

/**
 * queue_push - add new node to the top of the list
 * @main: main node
 *
 * Return: Always 1 (Success) : NULL
 */
int queue_push(node_t *main)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
		return (0);

	new_node->value = main->arg;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!main->head)
	{
		main->head = new_node;
		main->tail = new_node;
		return (1);
	}
	else
	{
		new_node->prev = main->tail;
		main->tail->next = new_node;
		main->tail = new_node;
	}

	return (1);
}

/**
 * queue_pop - returns the value of the top of the stack
 * @main: main node
 *
 * Return: value of the tail stack
 */
int queue_pop(node_t *main)
{
	if (main->tail)
	{
		stack_t *tmp = main->tail->prev;
		int value = main->tail->value;

		if (tmp)
		{
			free(main->tail);
			main->tail = tmp;
			main->tail->next = NULL;
		}

		return (value);
	}

	return (0);
}