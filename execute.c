#include "monty.h"

/**
 * execute_opcode - executes the opcode
 * @content: line content
 * @stack_head: head linked list - stack
 * @line_counter: line_counter
 * @file: pointer to monty file
 * Return: no return
*/
int execute_opcode(char *content, stack_t **stack_head, unsigned int line_counter,FILE *file)
{
instruction_t opcode_table[] = {
{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
{"pop", func_pop},
{"swap", func_swap},
{"add", func_add},
{"nop", func_nop},
{"sub", func_sub},
{"div", func_div},
{"mul", func_mul},
{"mod", func_mod},
{"pchar", func_pchar},
{NULL, NULL}
};
unsigned int index = 0;
char *operation;
operation = strtok(content, " \n\t");
if (operation && operation[0] == '#')
return (0);
bus.arg = strtok(NULL, " \n\t");
while (opcode_table[index].opcode && operation)
{
if (strcmp(operation, opcode_table[index].opcode) == 0)
{
opcode_table[index].f(stack_head, line_counter);
return (0);
}
index++;
}
if (operation && opcode_table[index].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, operation);
fclose(file);
free(content);
free_stack_memory(*stack_head);
exit(EXIT_FAILURE);
}
return (1);
}
