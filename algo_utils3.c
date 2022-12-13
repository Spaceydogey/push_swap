/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:32 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/13 13:52:40 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ext	get_closest_min(t_ext **min, int k, int len, int iter)
{
	t_ext	closest;

	closest.val = (min[k])->val;
	closest.dst = (min[k])->dst;
	closest.pos = (min[k])->pos;
	while (k < iter * LEN + len)
	{
		if ((min[k])->dst < closest.dst)
		{
			closest.val = (min[k])->val;
			closest.dst = (min[k])->dst;
			closest.pos = (min[k])->pos;
		}
		k++;
	}
	return (closest);
}

static void	goto_closest(t_list **stack_a, t_ext **min, int len, int iter)
{
	int		k;
	t_ext	closest;
	int		size;
	int		last_iter;

	last_iter = iter - 1;
	if (last_iter <= 0)
		last_iter = 0;
	k = iter * LEN;
	size = find_next_min(stack_a, min, iter);
	if (size == -1)
		return ;
	if ((iter * LEN) + len >= size)
		len = size - (iter * LEN);
	closest = get_closest_min(min, k, len, iter);
	while (--closest.dst >= 0)
	{
		if (closest.pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	k = -1;
	while (++k < size)
		free(min[k]);
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

int	find_next_min(t_list **stack_a, t_ext **min, int iter)
{
	int		i;
	int		k;
	int		size;
	t_list	*tmp;

	tmp = *stack_a;
	size = ps_lstsize(*stack_a);
	if (!tmp)
		return (-1);
	k = 0;
	i = 1;
	while (k < size)
	{
		(min[k]) = malloc(sizeof(t_ext));
		if (!min[k])
			return (-1);
		(min[k])->pos = i;
		(min[k])->val = tmp->content;
		dst(&min[k], size);
		while (tmp)
		{
			while (tmp && is_in_tab(min, k - 1, (min[k])->val) == 1)
			{	
				tmp = tmp->next;
				i++;
				if (tmp)
				{
					(min[k])->val = tmp->content;
					(min[k])->pos = i;
					dst(&(min[k]), size);
				}
			}
			if (tmp && (min[k])->val >= tmp->content
				&& is_in_tab(min, k - 1, tmp->content) == 0)
			{
				(min[k])->val = tmp->content;
				(min[k])->pos = i;
				dst(&(min[k]), size);
				while (tmp && is_in_tab(min, k, tmp->content) == 1)
				{	
					tmp = tmp->next;
					i++;
				}
			}
			else
			{
				if (tmp)
				{
					tmp = tmp->next;
					i++;
				}
			}
		}
		tmp = *stack_a;
		k++;
		i = 1;
	}
	return (size);
}
