#include "monty.h"
#include <stdio.h>
/**
 * interpreter - interpret the file
 * @f: file
 */
void interpreter(FILE *f)
{
char *buff;
stack_t *stack = NULL;
size_t n;
unsigned int line_num = 1;
buff = NULL;
while (getline(&buff, &n, f) != -1)
{
parse_line(buff, line_num, &stack);
check_status(f, buff, stack);
line_num++;
free(buff);
buff = NULL;
}
fclose(f);
free(buff);
free_dlistint(stack);
}
/**
 * _error - print error massage
 * @msg: error massage
 * @line_num: opcode line number
 */
void _error(char *msg, int line_num)
{
status = EXIT_FAILURE;
fprintf(stderr, "L%i%s\n", line_num, msg);
}
/**
 * parse_line - check if for errors
 * @line: buffer containing the line
 * @line_num: opcode line number
 * @stack: stack
 */
void parse_line(char *line, unsigned int line_num, stack_t **stack)
{
char *opcode, *arg;
static char id = 's';
void (*fun)(stack_t  **stack, unsigned int line_number);
opcode = strtok(line, " \n\t");
arg = strtok(NULL, " \n\t");
if (opcode[0] == '#')
{
opcode = "nop";
}
if (strcmp("queue", opcode) == 0 || strcmp("stack", opcode) == 0)
{
id = strcmp("queue", opcode) == 0 ? 'q' : 's';
}
else if (strcmp("push", opcode) == 0)
{
push(stack, line_num, arg, id);
}
else
{
fun = get_op_func(opcode);
if (fun == NULL)
{
status = EXIT_FAILURE;
fprintf(stderr, "L%i: unknown instruction %s\n", line_num, opcode);
}
else
{
fun(stack, line_num);
}
}
}
/**
 * check_status - check if for errors
 * @f: file
 * @buff: buffer containing the line
 * @stack: stack
 */
void check_status(FILE *f, char *buff, stack_t *stack)
{
if (status == EXIT_FAILURE)
{
fclose(f);
free_dlistint(stack);
free(buff);
exit(EXIT_FAILURE);
}
}
/**
 * remove_spaces - removes leading spaces
 * @str: buffer containing the line
 * Return: string with leading spaces removed
 */
char *remove_spaces(char *str)
{
while (*str == ' ')
{
str++;
}
return (str);
}
