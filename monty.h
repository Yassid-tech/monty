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
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
 * struct yass_id - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct yass_id
{
char *arg;
FILE *file;
char *content;
int lifi;
} yass_id;
extern yass_id yass;

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

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void func_push(stack_t **stack, unsigned int line_num);
void func_pall(stack_t **stack, unsigned int line_num);
void func_pint(stack_t **stack, unsigned int number);
int execute_opcod(char *line_content, stack_t **head, unsigned int stack_head, FILE *monty_file);
void free_stack_memory(stack_t *stack_head);
void func_pop(stack_t **stack, unsigned int line_num);
void func_swap(stack_t **stack, unsigned int line_num);
void func_add(stack_t **stack, unsigned int line_num);
void func_nop(stack_t **stack, unsigned int line_num);
void func_sub(stack_t **stack, unsigned int line_num);
void func_div(stack_t **stack, unsigned int line_num);
void func_mul(stack_t **stack, unsigned int line_num);
void func_mod(stack_t **stack, unsigned int line_num);
void func_pchar(stack_t **stack, unsigned int line_num);
void add_node(stack_t **stack_head, int value);
void add_queue(stack_t **stack_head, int value);
#endif
