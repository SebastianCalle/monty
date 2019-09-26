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
	FILE *fd;
	int type;
	int arg;
} node_t;

void free_stack(node_t *main, FILE *fd);
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
int argument_pass(char **args, int l, node_t *inst, FILE *fd);
void free_memory_int_error(char **args, node_t *inst, FILE *fd);

/* Funtions stack*/
int toggle_type(node_t *inst);
int stack_push(node_t *inst);
int stack_pop(node_t *inst);
int pall(node_t *inst);
int swap(node_t *inst);


#endif /* MONTY_H */
