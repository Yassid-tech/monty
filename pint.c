#include "monty.h"
/**
 * func_pint - prints the top
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void func_pint(stack_t **stack, unsigned int counter)
{
if (*head == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack_memory(*head);
exit(EXIT_FAILURE);
}
printf("%d\n", (*head)->n);
}
