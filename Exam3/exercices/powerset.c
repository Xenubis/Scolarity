#include <stdio.h>
#include <stdlib.h>

void	print_subset(int *set, int size, long mask)
{
	int	i;
	int	first;

	first = 1;
	i = 0;
	while (i < size)
	{
		if (mask & (1L << i))
		{
			if (!first)
				printf(" ");
			printf("%d", set[i]);
			first = 0;
		}
		i++;
	}
	printf("\n");
}

int	get_sum(int *set, int size, long mask)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < size)
	{
		if (mask & (1L << i))
			sum += set[i];
		i++;
	}
	return (sum);
}

int	main(int ac, char **av)
{
	int *set;
	int size;
	long mask;
	int i;

	if (ac < 2)
		return (0);
	size = ac - 2;
	set = malloc(sizeof(int) * size);
	if (!set)
		exit(1);
	i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	mask = 0;
	while (mask < (1L << size))
	{
		if (get_sum(set, size, mask) == atoi(av[1]))
			print_subset(set, size, mask);
		mask ++;
	}
	free(set);
	return (0);
}
