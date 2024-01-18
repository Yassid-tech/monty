#include "monty.h"

/**
 * func_add - performs the addition of the
 * top two elements of the stack 
 * @stack: stack head
 * @line_num: number's line
 * Return: no return
 */
void func_add(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
int length = 0, result;
current_node = *stack;
while (current_node)
{
current_node = current_node->next;
length++;
}
if (length < 2)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
current_node = *stack;
result = current_node->n + current_node->next->n;
current_node->next->n = result;
*stack = current_node->next;
free(current_node);
}
