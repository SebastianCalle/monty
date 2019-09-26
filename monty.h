#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
 * @line: current line of the file
 * @line_num: current line of the file
 * @fd: file descriptor
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct node_s
{
	stack_t *head;
	stack_t *tail;
	int line_num;
	char *opcode;
	char *line;
	char *arg;
	FILE *fd;
	int type;
} node_t;

typedef int (*fun)(node_t *inst);
node_t *init_node();

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

void free_file(node_t *inst, int error);
void free_all(node_t *inst, int error);
int argument_pass(node_t *inst);
int check_opcode(node_t *inst);

/* Funtions stack*/
int toggle_type(node_t *main);
int stack_push(node_t *main);
int queue_push(node_t *main);
int stack_pop(node_t *main);
int swap(node_t *inst);
int pall(node_t *main);
int add(node_t *inst);
int sub(node_t *inst);
int divide(node_t *inst);
int multiply(node_t *inst);
int mod(node_t *inst);
int pchar(node_t *inst);

#endif /* MONTY_H */
