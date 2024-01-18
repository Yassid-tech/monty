#include "monty.h"
/**
 * func_pint - performs the print of the element in the top
 * @stack: stack head
 * @counter: number's line
 * Return: no return
*/
void func_pint(stack_t **stack, unsigned int counter)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
fclose(yass.file);
free(yass.content);
free_stack_memory(*stack);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}
