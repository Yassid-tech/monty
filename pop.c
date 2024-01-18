#include "monty.h"

/**
 * func_pop - pops the top element off the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void func_pop(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
current_node = *stack;
*stack = current_node->next;
free(current_node);
}
