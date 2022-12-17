/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:32 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/17 19:13:17 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ext	*get_closest_min(t_ext **min, int k, int len, int iter)
{
	t_ext	*closest;
	int		save;

	k = 0;
	save = k;
	closest = malloc(sizeof(t_ext));
	closest->dst = INT_MAX;
	while (k < len)
	{
		if ((min[k])->dst < closest->dst && (min[k])->dst != -1)
		{
			closest->val = (min[k])->val;
			closest->dst = (min[k])->dst;
			closest->pos = (min[k])->pos;
			save = k;
		}
		k++;
	}
	(min[save])->dst = -1;
	return (closest);
}

static void	goto_closest(t_list **stack_a, t_ext **min, int len, int iter)
{
	int		k;
	t_ext	*closest;
	int		size;

	k = (iter * LEN);
	size = ps_lstsize(*stack_a);
	if (size == -1)
		return ;
	update_all_min(stack_a, min, iter, size);
	closest = get_closest_min(&(min[k]), k, len, iter);
	while (closest->dst > 0)
	{
		if (closest->pos <= (size / 2) + (size % 2))
			ra(stack_a);
		else
			rra(stack_a);
		closest->dst -= 1;
	}
	free(closest);
}

int	push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;
	int		size;
	int		i;

	len = LEN;
	size = ps_lstsize(*stack_a);
	if ((iter * LEN) + len > size)
		len = size - (iter * LEN);
	i = len;
	while (i > 0)
	{
		goto_closest(stack_a, min, len, iter);
		pb(stack_a, stack_b);
		i--;
	}
	return (size - len);
}
