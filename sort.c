/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:08:29 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 14:58:31 by hdelmas          ###   ########.fr       */
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
	k = iter.last_iter * iter.chunk_size;
	while (incr.i <= size)
	{
		if (is_in_tab(&min[k], len - 1, tmp->content) == 1)
			update_min(&(min[k]), tmp->content, incr, iter);
		tmp = tmp->next;
		incr.i += 1;
	}
}

static void	move_a(t_list **stack_a, t_ext **min, t_iter iter)
{
	int		size;
	int		len;

	len = iter.chunk_size;
	size = ps_lstsize(*stack_a);
	update_all_min(stack_a, min, iter, size);
	while (iter.iter > 0 && iter.iter < iter.iter_max
		&& min[(iter.last_iter * len) + len - 1]->pos != size)
	{
		if (min[(iter.last_iter * len) + len - 1]->pos
			> (size / 2) + (size % 2))
		{
			rra(stack_a);
			min[(iter.last_iter * len) + len - 1]->pos += 1;
		}
		else
		{
			ra(stack_a);
			min[(iter.last_iter * len) + len - 1]->pos -= 1;
			if (min[(iter.last_iter * len) + len - 1]->pos == 0)
				min[(iter.last_iter * len) + len - 1]->pos = size;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b, t_ext **min, t_iter iter)
{
	iter.last_iter = iter.iter - 1;
	if (iter.last_iter < 0)
		iter.last_iter = 0;
	if (is_sorted(stack_a))
		return ;
	while (is_sorted(stack_a) == 0)
	{
		iter.last_iter = iter.iter - 1;
		if (iter.last_iter < 0)
			iter.last_iter = 0;
		if (iter.iter >= iter.iter_max)
		{
			sort_a(stack_a, stack_b, ps_lstsize(*stack_a));
			return ;
		}
		else
		{	
			find_next_min(stack_a, min, iter);
			push_all_min(stack_a, stack_b, min, iter);
			move_a(stack_a, min, iter);
			sort_b(stack_a, stack_b, ps_lstsize(*stack_b));
			iter.iter += 1;
		}
	}
}
