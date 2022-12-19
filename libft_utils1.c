/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:50:14 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/19 10:00:27 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, s_len);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
