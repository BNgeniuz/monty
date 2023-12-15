#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void mo_push(stack_t **master, unsigned int index);
void mo_pall(stack_t **head, unsigned int number);
void mo_pint(stack_t **head, unsigned int number);
int execute(char *cont, stack_t **aux, unsigned int reader, FILE *fd);
void free_stack(stack_t *master);
void mo_pop(stack_t **master, unsigned int reader);
void mo_swap(stack_t **master, unsigned int reader);
void mo_add(stack_t **master, unsigned int reader);
void mo_nop(stack_t **master, unsigned int reader);
void mo_sub(stack_t **master, unsigned int reader);
void mo_div(stack_t **master, unsigned int reader);
void mo_mul(stack_t **master, unsigned int reader);
void mo_mod(stack_t **head, unsigned int reader);
void mo_pchar(stack_t **master, unsigned int reader);
void mo_pstr(stack_t **master, unsigned int reader);
void mo_rotl(stack_t **head, unsigned int counter);
void mo_rotr(stack_t **master, __attribute__((unused)) unsigned int reader);
void add_node(stack_t **master, int n);
void add_queue(stack_t **master, int o);
void mo_queue(stack_t **master, unsigned int reader);
void mo_stack(stack_t **master, unsigned int reader);

#endif
