#include "monty.h"

/**
 * execute_opcod - executes the operation code
 * @content: line content
 * @stack: head linked list - stack
 * @line: counter's line
 * @file: pointer to monty file
 * Return: no return
*/
int execute_opcod(char *content, stack_t **stack, unsigned int line, FILE *file)
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
yass.arg = strtok(NULL, " \n\t");
while (opcode_table[index].opcode && operation)
{
if (strcmp(operation, opcode_table[index].opcode) == 0)
{
opcode_table[index].f(stack, line);
return (0);
}
index++;
}
if (operation && opcode_table[index].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line, operation);
fclose(file);
free(content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
return (1);
}
