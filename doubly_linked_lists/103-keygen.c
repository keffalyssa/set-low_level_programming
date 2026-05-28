#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * compute_k0_k2 - computes first 3 key indices
 * @u: username
 * @len: length
 * @k: output array
 */
void compute_k0_k2(char *u, int len, int *k)
{
	int i, sum, prod;

	k[0] = (len ^ 0x3b) & 0x3f;

	sum = 0;
	for (i = 0; i < len; i++)
		sum += (unsigned char)u[i];
	k[1] = (sum ^ 0x4f) & 0x3f;

	prod = 1;
	for (i = 0; i < len; i++)
		prod *= (unsigned char)u[i];
	k[2] = (prod ^ 0x55) & 0x3f;
}

/**
 * compute_k3_k5 - computes last 3 key indices
 * @u: username
 * @len: length
 * @k: output array
 */
void compute_k3_k5(char *u, int len, int *k)
{
	int i, max_c, sq_sum, val;

	max_c = (unsigned char)u[0];
	for (i = 1; i < len; i++)
		if ((unsigned char)u[i] > max_c)
			max_c = (unsigned char)u[i];
	srand(max_c ^ 0x0e);
	k[3] = rand() & 0x3f;

	sq_sum = 0;
	for (i = 0; i < len; i++)
		sq_sum += (unsigned char)u[i] * (unsigned char)u[i];
	k[4] = (sq_sum ^ 0xef) & 0x3f;

	val = 0;
	for (i = 0; i < (unsigned char)u[0]; i++)
		val = rand();
	k[5] = (val ^ 0xe5) & 0x3f;
}

/**
 * main - keygen for crackme5
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *cs = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int k[6], i, len;
	char key[7];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s username\n", argv[0]);
		return (1);
	}
	len = strlen(argv[1]);
	compute_k0_k2(argv[1], len, k);
	compute_k3_k5(argv[1], len, k);
	for (i = 0; i < 6; i++)
		key[i] = cs[k[i]];
	key[6] = '\0';
	printf("%s\n", key);
	return (0);
}
