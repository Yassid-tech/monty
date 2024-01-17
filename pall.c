#include "monty.h"

/**
 * func_pall - prints the stack
 * @stack: stack head
 * @line_num: not used
 * Return: no return
*/
void func_pall(stack_t **stack, unsigned int line_num)
{
stack_t *current_node;
(void)line_num;
current_node = *stack;
if (current_node == NULL)
return;
while (current_node)
{
printf("%d\n", current_node->n);
current_node = current_node->next;
}
}
