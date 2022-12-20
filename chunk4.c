/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:41:04 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 15:01:43 by hdelmas          ###   ########.fr       */
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
	k = iter.last_iter * iter.chunk_size;
	while (incr.i <= size)
	{
		if (is_in_tab(&min[k], len - 1, tmp->content) == 1)
			update_min(&(min[k]), tmp->content, incr, iter);
		tmp = tmp->next;
		incr.i += 1;
	}
}

void	test_move_a(t_list **stack_a, t_ext **min, t_iter iter, int *count)
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
			rra_chunk(stack_a, count);
			min[(iter.last_iter * len) + len - 1]->pos += 1;
		}
		else
		{
			ra_chunk(stack_a, count);
			min[(iter.last_iter * len) + len - 1]->pos -= 1;
			if (min[(iter.last_iter * len) + len - 1]->pos == 0)
				min[(iter.last_iter * len) + len - 1]->pos = size;
		}
	}
} 