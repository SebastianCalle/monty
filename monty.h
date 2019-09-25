#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * @value: integer
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	struct stack_s *prev;
	struct stack_s *next;
	int value;
} stack_t;

/**
 * struct node_s - doubly linked list representation of a manager stack
 * @head: points to first element of a list
 * @tail: points to last element of a list
 * @opcode: current opcode
 * @type: type [stack | queue]
 * @arg: current argument by the current opcode
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct node_s
{
	stack_t *head;
	stack_t *tail;
	char *opcode;
	int type;
	int arg;
} node_t;

void free_stack(node_t *main, FILE *fd);
int parse(FILE *fd, node_t *main);
typedef int (*fun)(node_t *main);
node_t *init_main_node(void);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	fun f;
} instruction_t;

#endif /* MONTY_H */
