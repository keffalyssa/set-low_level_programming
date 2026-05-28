#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char *username;
	int len, i;
	int k0, k1, k2, k3, k4, k5;
	int sum, prod, max_c, sq_sum;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}

	username = argv[1];
	len = strlen(username);

	k0 = (len ^ 0x3b) & 0x3f;

	sum = 0;
	for (i = 0; i < len; i++)
		sum += (unsigned char)username[i];
	k1 = (sum ^ 0x4f) & 0x3f;

	prod = 1;
	for (i = 0; i < len; i++)
		prod *= (unsigned char)username[i];
	k2 = (prod ^ 0x55) & 0x3f;

	max_c = (unsigned char)username[0];
	for (i = 1; i < len; i++)
		if ((unsigned char)username[i] > max_c)
			max_c = (unsigned char)username[i];
	srand(max_c ^ 0x0e);
	k3 = rand() & 0x3f;

	sq_sum = 0;
	for (i = 0; i < len; i++)
		sq_sum += (unsigned char)username[i] * (unsigned char)username[i];
	k4 = (sq_sum ^ 0xef) & 0x3f;

	sum = 0;
	for (i = 0; i < (unsigned char)username[0]; i++)
		sum = rand();
	k5 = (sum ^ 0xe5) & 0x3f;

	key[0] = charset[k0];
	key[1] = charset[k1];
	key[2] = charset[k2];
	key[3] = charset[k3];
	key[4] = charset[k4];
	key[5] = charset[k5];
	key[6] = '\0';

	printf("%s\n", key);
	return (0);
}
