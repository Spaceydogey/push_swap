#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c == 32) || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

long	ps_atoi(const char *nptr)
{
	long int		res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr) == 1)
		nptr++;
	if (*nptr == 45 || *nptr == 43)
		if (*(nptr++) == 45)
			sign *= -1;
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = (10 * res + (*nptr - 48));
		if (sign * res < INT_MIN || sign * res > INT_MAX)
			break ;
		nptr++;
	}
	return ((res * sign));
}
