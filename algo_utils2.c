/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:32:58 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/16 22:05:27 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_algo.h"

int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;

	i = -1;
	while (++i <= size)
	{
		if ((tab[i])->val == content)
			return (1);
	}
	return (0);
}

int	dst(int pos, int size)
{
	t_ext	res;

	res.dst = pos - 1;
	if (res.dst > size - res.dst)
		res.dst = size - res.dst;
	return (res.dst);
}

void	update_min(t_ext **min, int content, int pos, int size, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if ((min[i])->val == content)
		{
			(min[i])->pos = pos;
			(min[i])->dst = dst(pos, size);
			// printf("minval\tmindst\tminpos\n%d\t\t%d\t\t%d\n", (min[i])->val, (min[i])->dst, (min[i])->pos);
			break ;
		}
	}
}