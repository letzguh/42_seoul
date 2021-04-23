#include <unistd.h>

int	not_seen_before(char *s, char c, int max_pos)
{
	int i;
	i = -1;
	while (++i < max_pos)
	{
		if (s[i] == c)
			return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int i;
	int j;

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					if (not_seen_before(av[1], av[1][i], i))
						{
							write(1, &av[1][i], 1);
							break;
						}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
