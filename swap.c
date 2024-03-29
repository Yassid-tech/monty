#include "monty.h"

/**
 * func_swap - swaps the top two elements of the stack
 * @stack: stack head
 * @line_num: number's line
 * Return: no return
 */
void func_swap(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
int length = 0, temp;
current_node = *stack;
while (current_node)
{
current_node = current_node->next;
length++;
}
if (length < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
current_node = *stack;
temp = current_node->n;
current_node->n = current_node->next->n;
current_node->next->n = temp;
}
