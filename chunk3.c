/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:41:18 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 14:59:25 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_best_chunk.h"

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

static int	goto_closest(t_list **stack_a, t_ext **min, int len, t_iter iter)
{
	int		k;
	t_ext	*closest;
	int		size;
	int		count;

	k = (iter.iter * iter.chunk_size);
	size = ps_lstsize(*stack_a);
	if (size == -1)
		return (-1);
	update_all_min(stack_a, min, iter, size);
	closest = get_closest_min(&(min[k]), k, len);
	count = 0;
	while (closest->dst > 0)
	{
		if (closest->pos <= (size / 2) + (size % 2))
			ra_chunk(stack_a, &count);
		else
			rra_chunk(stack_a, &count);
		closest->dst -= 1;
	}
	free(closest);
	return (count);
}

void	test_push_all_min(t_stacks stack, t_ext **min, t_iter iter, int *count)
{
	int		len;
	int		size;
	int		i;

	len = iter.chunk_size;
	size = ps_lstsize(*stack.stack_a);
	if ((iter.iter * iter.chunk_size) + len > size)
		len = size - (iter.iter * iter.chunk_size);
	i = len;
	while (i > 0)
	{
		*count += goto_closest(stack.stack_a, min, len, iter);
		pb_chunk(stack.stack_a, stack.stack_b, count);
		i--;
	}
}
