#include "monty.h"
#include "queue.h"

/**
 * stack_push - add new node to the top of the list
 * @main: main node
 *
 * Return: Always 1 (Success) : NULL
 */
int stack_push(node_t *main)
{
	if (main->type == STACK)
	{
		stack_t *new_node = malloc(sizeof(stack_t));

		if (!new_node)
		{
			fprintf(stderr, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}

		new_node->value = atoi(main->arg);
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
			new_node->next = main->head;
			main->head = new_node;
		}
	}
	else
		queue_push(main);

	return (1);
}

/**
 * stack_pop - returns the value of the top of the stack
 * @main: main node
 *
 * Return: value top stack
 */
int stack_pop(node_t *main)
{
	stack_t *tmp;
	int value;

	if (main->head)
	{
		/*if (main->type == STACK)*/
		/*{*/
		tmp = main->head->next;
		value = main->head->value;
		free(main->head);
		main->head = tmp;

		if (main->head)
			tmp->prev = NULL;

		return (value);
		/*}*/
		/*else*/
		/*	queue_pop(main);*/
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", main->line_num);
		free_all(main, 1);
	}

	return (0);
}

/**
 * pall - print all items of a list
 * @main: main node
 *
 * Return: void
 */
int pall(node_t *main)
{
	stack_t *tmp = main->head;

	if (!main->head && !strcmp(main->opcode, "pint"))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", main->line_num);
		free_all(main, EXIT_FAILURE);
	}

	if (!strcmp(main->opcode, "pint"))
	{
		printf("%d\n", tmp->value);
		return (1);
	}

	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	return (1);
}

/**
 * toggle_type - toggle type of the stack - queue
 * @main: main node
 *
 * Return: Always 1 (Success)
 */
int toggle_type(node_t *main)
{
	if (!strcmp(main->opcode, "stack"))
		main->type = STACK;
	else
		main->type = QUEUE;

	return (1);
}

/**
 * swap - function that swap the top of the stack
 * @inst: node manage of stack
 * Return: 0 if suscces or 1 if not
 */
int swap(node_t *inst)
{
	stack_t *tmp = inst->head;
	int swp;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L<line_number>: can't swap, stack too shortu");
		exit(EXIT_FAILURE);
	}

	swp = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = swp;

	inst->head = tmp;
	inst->head->next = tmp->next;

	return (0);
}