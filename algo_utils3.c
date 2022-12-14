/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:32 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 14:56:21 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_all_min(t_list **stack_a, t_ext **min, t_iter iter, int size)
{
	t_list	*tmp;
	t_incr	incr;
	int		i;
	int		k;
	int		len;

	tmp = *stack_a;
	incr.i = 1;
	incr.max = size;
	len = iter.chunk_size;
	k = iter.iter * iter.chunk_size;
	while (incr.i <= size)
	{
		if (is_in_tab(&min[k], len - 1, tmp->content) == 1)
			update_min(&(min[k]), tmp->content, incr, iter);
		tmp = tmp->next;
		incr.i += 1;
	}
}

t_ext	*get_closest_min(t_ext **min, int k, int len)
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

static void	goto_closest(t_list **stack_a, t_ext **min, int len, t_iter iter)
{
	int		k;
	t_ext	*closest;
	int		size;

	k = (iter.iter * iter.chunk_size);
	size = ps_lstsize(*stack_a);
	if (size == -1)
		return ;
	update_all_min(stack_a, min, iter, size);
	closest = get_closest_min(&(min[k]), k, len);
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

int	push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, t_iter iter)
{
	int		len;
	int		size;
	int		i;

	len = iter.chunk_size;
	size = ps_lstsize(*stack_a);
	if ((iter.iter * iter.chunk_size) + len > size)
		len = size - (iter.iter * iter.chunk_size);
	i = len;
	while (i > 0)
	{
		goto_closest(stack_a, min, len, iter);
		pb(stack_a, stack_b);
		i--;
	}
	return (size - len);
}
