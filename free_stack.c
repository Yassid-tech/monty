#include "monty.h"

/**
 * free_stack_memory - deallocates memory for a 
 * doubly linked list
 * @stack_head: stack's head
 */
void free_stack_memory(stack_t *stack_head)
{
stack_t *current_node;
current_node = stack_head;
while (stack_head)
{
current_node = stack_head->next;
free(stack_head);
stack_head = current_node;
}
}
