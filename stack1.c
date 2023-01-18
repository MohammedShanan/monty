#include "monty.h"
/**
 * push - prints the value at the top of the stack
 * @stack: stack
 * @line_num: opcode line number
 * @arg: opcode argument
 * @id: id to specify the format of the data
 */
void push(stack_t **stack, unsigned int line_num, char *arg, char id)
{
if (is_num(arg) == -1)
{
_error(": usage: push integer", line_num);
return;
}
if (id == 'q')
{
add_dnodeint_end(stack, atoi(arg));
}
else
{
add_dnodeint(stack, atoi(arg));
}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
_error(": can't pint, stack empty", line_number);
return;
}
printf("%i\n", (*stack)->n);
}
/**
 * pop -removers the value at the top of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
if (*stack == NULL)
{
_error(": can't pop, an empty stack", line_number);
return;
}
tmp = *stack;
*stack = (*stack)->next;
if (tmp->next)
{
(*stack)->prev = NULL;
}
free(tmp);
}
/**
 * pall - prints all the values on the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *h;
h = *stack;
(void)line_number;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}
/**
 * swap - swaps the top two elements of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't swap, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node1->next = node2->next;
node1->prev = node2;
node2->next = node1;
node2->prev = NULL;
*stack = node2;
}
