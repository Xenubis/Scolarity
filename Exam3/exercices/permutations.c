#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	permutation(char *str, int i, int len)
{
	int	j;

	if (i == len)
	{
		puts(str);
		return ;
	}
	j = i;
	sort(str + i);
	while (j < len)
	{
		swap(&str[i], &str[j]);
		permutation(str, i + 1, len);
		swap(&str[i], &str[j]);
		sort(str + i);
		j++;
	}	
}

int	main(int ac, char **av)
{
	int	len;

	len = 0;
	if (ac != 2)
		return (0);
	while (av[1][len])
		len++;
	sort(av[1]);
	permutation(av[1], 0, len);
	return (0);
}