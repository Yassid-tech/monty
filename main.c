#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
bus_t my_bus = {NULL, NULL, NULL, 0};
bus = &my_bus;
char *line_content;
FILE *monty_file;
size_t size = 0;
ssize_t read_line = 1;
stack_t *stack = NULL;
unsigned int line_counter = 0;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
monty_file = fopen(argv[1], "r");
bus.file = monty_file;
if (!monty_file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (read_line > 0)
{
line_content = NULL;
read_line = getline(&line_content, &size, monty_file);
bus.content = line_content;
line_counter++;
if (read_line > 0)
{
execute_opcod(line_content, &stack, line_counter, monty_file);
}
free(line_content);
}
free_stack_memory(stack);
fclose(monty_file);
return (0);
}
