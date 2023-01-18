#include "monty.h"
/**
 * nop - does nothing
 * @stack: stack
 * @line_number: opcode line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
return;
}

/**
 * pchar -  prints the char at the top of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
_error(": can't pchar, stack empty", line_number);
return;
}
if ((isascii((*stack)->n)))
{
printf("%c\n", (*stack)->n);
}
else
{
_error(": can't pchar, value out of range", line_number);
return;
}
}
/**
 * pstr -  prints the string starting at the top of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;
tmp = *stack;
(void)line_number;
while (tmp)
{
if (!(isascii((*stack)->n)) || tmp->n == 0)
{
break;
}
printf("%c", tmp->n);
tmp = tmp->next;
}
printf("\n");
}

/**
 * rotl -  rotates the stack to the top
 * @stack: stack
 * @line_number: opcode line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *top_node;
top_node = tmp = *stack;
(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
while (tmp->next)
{
tmp = tmp->next;
}
*stack = (*stack)->next;
(*stack)->next->prev = NULL;
top_node->next = NULL;
top_node->prev = tmp;
tmp->next = top_node;
}

/**
 * rotr -  rotates the stack to the bottom
 * @stack: stack
 * @line_number: opcode line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp, *top_node;
top_node = tmp = *stack;
(void)line_number;
if (*stack == NULL || (*stack)->next == NULL)
{
return;
}
while (tmp->next)
{
tmp = tmp->next;
}
*stack = tmp;
tmp->prev->next = NULL;
tmp->prev = NULL;
top_node->prev = tmp;
tmp->next = top_node;
}
