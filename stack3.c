#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void add(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't add, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n + node1->n;
pop(stack, line_number);
}
/**
 * sub- subtracts the top element of the stack
 * from the second top element of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't sub, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n - node1->n;
pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't mul, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
node2->n = node2->n * node1->n;
pop(stack, line_number);
}
/**
 * _div - divides the second top element of the stack
 * by the top element of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't div, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
if (node1->n == 0)
{
_error(": division by zero", line_number);
return;
}
node2->n = node2->n / node1->n;
pop(stack, line_number);
}
/**
 * mod -computes the rest of the
 * division of the second top element of the stack
 * by the top element of the stack
 * @stack: stack
 * @line_number: opcode line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
stack_t *node1, *node2;
if (*stack == NULL || (*stack)->next == NULL)
{
_error(": can't mod, stack too short", line_number);
return;
}
node1 = *stack;
node2 = (*stack)->next;
if (node1->n == 0)
{
_error(": division by zero", line_number);
return;
}
node2->n = node2->n % node1->n;
pop(stack, line_number);
}
