/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:32:58 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/13 13:19:47 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_algo.h"

int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;
	int	k;

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
