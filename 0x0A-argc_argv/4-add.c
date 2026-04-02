#include <stdio.h>

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
int i, j, sum, num;

sum = 0;
if (argc == 1)
{
printf("0\n");
return (0);
}
for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j] != '\0'; j++)
{
if (argv[i][j] < '0' || argv[i][j] > '9')
{
printf("Error\n");
return (1);
}
}
num = 0;
for (j = 0; argv[i][j] != '\0'; j++)
num = num * 10 + (argv[i][j] - '0');
sum += num;
}
printf("%d\n", sum);
return (0);
}
