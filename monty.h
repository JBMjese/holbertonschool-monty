#ifndef MONTY_H
#define MONTY_H

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



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


char *buff;

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void monty_handler(char *file);
void (*check_opcodes(void))(stack_t **, unsigned int);
void print_all(stack_t **stack, unsigned int line_number);
void printTop(stack_t **stack, unsigned int line_number);
void noOperation(stack_t **stack, unsigned int line_number);
void *my_calloc(unsigned int nmemb, unsigned int size);
int my_atoi(char *str, unsigned int line_number);
char **my_split(char *str, char *sep);
void my_free_stack(stack_t *head);

#endif
