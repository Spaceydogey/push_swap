/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:08:29 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/17 18:56:38 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_all_min(t_list **stack_a, t_ext **min, int iter, int size)
{
	t_list	*tmp;
	int		i;
	int		k;
	int		len;

	tmp = *stack_a;
	i = 0;
	len = LEN;
	// if ((LEN * iter) + len > size)
	// 	len = size - (LEN * iter);
	k = iter * LEN;
	while (++i <= size)
	{
		if (is_in_tab(&min[k], len - 1, tmp->content) == 1)
			update_min(&(min[k]), tmp->content, i, size, len);
		tmp = tmp->next;
	}
}

static void	move_a(t_list **stack_a, t_ext **min, t_iter iter)
{
	int		size;
	int		len;

	size = ps_lstsize(*stack_a);
	update_all_min(stack_a, min, iter.last_iter, size);
	while (iter.iter > 0 && iter.iter < iter.iter_max
		&& min[(iter.last_iter * LEN) + LEN - 1]->pos != size)
	{
		if (min[(iter.last_iter * LEN) + LEN - 1]->pos > (size / 2) + (size % 2))
		{
			rra(stack_a);
			min[(iter.last_iter * LEN) + LEN - 1]->pos += 1;
		}
		else
		{
			ra(stack_a);
			min[(iter.last_iter * LEN) + LEN - 1]->pos -= 1;
			if (min[(iter.last_iter * LEN) + LEN - 1]->pos == 0)
				min[(iter.last_iter * LEN) + LEN - 1]->pos = size;
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
			find_next_min(stack_a, min, iter.iter);
			push_all_min(stack_a, stack_b, min, iter.iter);
			move_a(stack_a, min, iter);
			sort_b(stack_a, stack_b, ps_lstsize(*stack_b));
			iter.iter += 1;
		}
	}
}
