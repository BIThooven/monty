#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define DELIM " \t\n\r"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct global - a global struct
 * @fname: the file name
 * @numbers: numbers to be added to stack
 * @buff: line to be read by getline
 * @opc: opcode to be used
 * @mode: integer in the struct
*/
typedef struct global
{
		FILE *fname;
		char *numbers;
		char *buff;
		char *opc;
		int mode;
} config;
extern config configs;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void sub(stack_t **head, unsigned int lines);
void split(char *buff, char *delim);
void push(stack_t **head, unsigned int linenum);
int _isdigit(char *s);
void add_nodeint_end(stack_t **head, const int n);
void stack_free(stack_t *h);
void add_nodeint(stack_t **h, const int n);
void del_nodeint_end(stack_t **h, unsigned int n);
int get_at_index(stack_t *h, unsigned int n);
int lengthofstack(stack_t *head);
void pall(stack_t **head, unsigned int time);
void pop(stack_t **head, unsigned int lines);
void pint(stack_t **head, unsigned int lines);
void swap(stack_t **head, unsigned int lines);
void add(stack_t **head, unsigned int lines);
void nop(stack_t **head, unsigned int lines);
void opcode_func(int lines, char *opt, stack_t **head);
#endif /* MONTY_H */
