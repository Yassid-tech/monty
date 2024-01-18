#include "monty.h"
/**
 * func_pint - prints the top
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void func_pint(stack_t **stack, unsigned int counter)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(bus.file);
free(bus.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
