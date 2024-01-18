#include "monty.h"

/**
 * func_mod - calculates the remainder of the division
 * between the second-to-top element and the head stack
 * @stack: stack  head
 * @line_num: number's line
 * Return: no return
 */
void func_mod(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
int result, node_count;
current_node = *stack;
for (node_count = 0; current_node != NULL; node_count++)
current_node = current_node->next;
if (node_count < 2)
{
fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
current_node = *stack;
if (current_node->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
result = current_node->next->n % current_node->n;
current_node->next->n = result;
*stack = current_node->next;
free(current_node);
}
