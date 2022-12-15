/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:32 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/15 14:56:57 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ext	get_closest_min(t_ext **min, int k, int len, int iter)
{
	t_ext	closest;
	int		save;

	closest.dst = INT_MAX;
	save = k;
	while (k < iter * LEN + LEN)
	{
		if ((min[k])->dst < closest.dst && (min[k])->dst != -1)
		{
			closest.val = (min[k])->val;
			closest.dst = (min[k])->dst;
			closest.pos = (min[k])->pos;
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
	t_ext	closest;
	int		size;
	int		last_iter;
	t_list	*tmp;
	int		i;

	last_iter = iter - 1;
	if (last_iter <= 0)
		last_iter = 0;
	k = (iter * LEN);
	size = ps_lstsize(*stack_a);
	if (size == -1)
		return ;
	if ((iter * LEN) + len >= size)
		len = size - (iter * LEN);
	tmp = *stack_a;
	i = 1;
	while (tmp)
	{
		if (is_in_tab(&min[k], LEN - 1, tmp->content) == 1)
			update_min(&(min[k]), tmp->content, i, size);
		i++;
		tmp = tmp->next;
	}
	closest = get_closest_min(min, k, len, iter);
	while (closest.dst > 0)
	{
		if (closest.pos <= (size / 2) + (size % 2))
			ra(stack_a);
		else
			rra(stack_a);
		closest.dst -= 1;
	}
}

int	push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;
	int		last_iter;
	int		size;
	int		res;

	len = LEN;
	size = ps_lstsize(*stack_a);
	if ((iter * LEN) + len >= size)
		len = size - (iter * LEN);
	res = len;
	while (len > 0)
	{
		goto_closest(stack_a, min, len, iter);
		pb(stack_a, stack_b);
		len--;
	}
	return (size - res);
}
