#include "monty.h"
int status = EXIT_FAILURE;
/**
 * main - prints all the values on the stack
 * @argc: argument count
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
FILE *f;
if (argc != 2)
{
write(2, "USAGE: monty file\n", 18);
exit(EXIT_FAILURE);
}
f = fopen(argv[1], "r");
if (f == NULL)
{
write(2, "Error: Can't open file ", 23);
write(2, argv[1], strlen(argv[1]));
write(2, "\n", 1);
exit(EXIT_FAILURE);
}
interpreter(f);
return (0);
}
