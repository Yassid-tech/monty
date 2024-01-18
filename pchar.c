#include "monty.h"

/**
 * func_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void func_pchar(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
current_node = *stack;
if (!current_node)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
if (current_node->n > 127 || current_node->n < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
printf("%c\n", current_node->n);
}
