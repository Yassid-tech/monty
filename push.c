#include "monty.h"

/**
 * func_push - add node to the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
*/
void func_push(stack_t **stack, unsigned int line_num)
{
int value, index = 0, invalid_input = 0;
if (bus.arg)
{
if (bus.arg[0] == '-')
index++;
for (; bus.arg[index] != '\0'; index++)
{
if (bus.arg[index] > 57 || bus.arg[index] < 48)
invalid_input = 1;
}
if (invalid_input == 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
value = atoi(bus.arg);
if (bus.lifi == 0)
add_node(stack, value);
else
add_queue(stack, value);
}
