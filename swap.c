#include "monty.h"

/**
 * func_swap - swaps the top two elements of the stack
 * @stack: stack head
 * @line_num: line_number
 * Return: no return
 */
void func_swap(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
int length = 0, temp;
current_node = *stack_head;
while (current_node)
{
current_node = current_node->next;
length++;
}
if (length < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack_head);
exit(EXIT_FAILURE);
}
current_node = *stack_head;
temp = current_node->n;
current_node->n = current_node->next->n;
current_node->next->n = temp;
}
