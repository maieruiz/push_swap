#include <stdio.h>
#include <math.h>

int	root(int num)
{
	int	i;

	i = 0;
	while (i * i <= num)
		i++;
	return (i - 1);
}

int	main(void)
{
	printf("root: %i\n", root(100));
	printf("root: %i\n", (int)sqrt(100));
	printf("root: %i\n", root(0));
	printf("root: %i\n", (int)sqrt(0));
	printf("root: %i\n", root(2));
	printf("root: %i\n", (int)sqrt(2));
	printf("root: %i\n", root(4));
	printf("root: %i\n", (int)sqrt(4));
	printf("root: %i\n", root(3));
	printf("root: %i\n", (int)sqrt(3));
	printf("root: %i\n", root(10));
	printf("root: %i\n", (int)sqrt(10));
	printf("root: %i\n", root(9));
	printf("root: %i\n", (int)sqrt(9));
	printf("root: %i\n", root(45));
	printf("root: %i\n", (int)sqrt(45));
	printf("root: %i\n", root(36));
	printf("root: %i\n", (int)sqrt(36));
	printf("root: %i\n", root(35));
	printf("root: %i\n", (int)sqrt(35));
	printf("root: %i\n", root(37));
	printf("root: %i\n", (int)sqrt(37));
}