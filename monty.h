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
int parse(FILE *fd, node_t *inst);
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
char **_strtok(char *buffer, int *n);
int check_del(char c, char b);
int check_flag(char str, int *index, int *i, int *c);
int count_letters(char *str, int *index, int *l);
int count_arg(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
int check_opcode(char **args, node_t *inst);

/* Funtions stack*/
int toggle_type(node_t *main);
int stack_push(node_t *main);
int stack_pop(node_t *main);
int pall(node_t *main);

#endif /* MONTY_H */
