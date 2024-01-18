#include "monty.h"

/**
 * func_push - performs the addition of a node to the stack
 * @stack: stack head
 * @line_num: number's line
 * Return: no return
*/
void func_push(stack_t **stack, unsigned int line_num)
{
int value, index = 0, invalid_input = 0;
if (yass.arg)
{
if (yass.arg[0] == '-')
index++;
for (; yass.arg[index] != '\0'; index++)
{
if (yass.arg[index] > 57 || yass.arg[index] < 48)
invalid_input = 1;
}
if (invalid_input == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
value = atoi(yass.arg);
if (yass.lifi == 0)
add_node(stack, value);
else
add_queue(stack, value);
}
