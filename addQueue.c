#include "monty.h"

/**
 * add_queue - adds a node to the tail of the stack
 * @stack_head: head of the stack
 * @value: new value
 * Return: no return
*/
void add_queue(stack_t **stack_head, int value)
{
stack_t *new_node, *temp;
temp = *stack_head;
new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
printf("Error\n");
}
new_node->n = value;
new_node->next = NULL;
if (temp)
{
while (temp->next)
temp = temp->next;
}
if (!temp)
{
*stack_head = new_node;
new_node->prev = NULL;
}
else
{
temp->next = new_node;
new_node->prev = temp;
}
}
