/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:32:58 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 14:56:02 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	update_min(t_ext **min, int content, t_incr incr, t_iter iter)
{
	int	i;

	i = -1;
	while (++i < iter.chunk_size)
	{
		if ((min[i])->val == content)
		{
			(min[i])->pos = incr.i;
			(min[i])->dst = dst(incr.i, incr.max);
			break ;
		}
	}
}
