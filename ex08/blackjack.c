#include <stdio.h>
#include <stdlib.h>

int	main(int c, char **v)
{
	int	i;
	int	ace;
	int res;

	if (c != 2)
		return (1);
	i = -1;
	res = 0;
	ace = 11;
	while (v[1][++i])
	{
		if (v[1][i] >= '2' && v[1][i] <= '9')
			res += v[1][i] - 48;
		else if (v[1][i] == 'J' || v[1][i] == 'T' || v[1][i] == 'K' || v[1][i] == 'D')
			res += 10;
		else if (v[1][i] == 'A')
		{
			if (res + 11 > 21)
				ace = 1;
			res += ace;
		}
		else
			return (printf("Wrong input type!\n"), 1);
	}
	if (res == 21)
		return (printf("Blackjack!\n"), 0);
	else
		return (printf("%d\n", res), 0);
}
