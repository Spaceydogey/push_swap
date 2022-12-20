/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:24:59 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 17:37:39 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_best_chunk.h"

static int	pa_size_chunk(t_list **stack_a, t_list **stack_b, int size, int *count)
{		
	pa_chunk(stack_a, stack_b, count);
	size -= 1;
	return (size);
}

static void	rr_or_rb_chunk(int *check_ra, t_list **stack_a, t_list **stack_b, int *count)
{
	if (*check_ra == 1)
	{
		rr_chunk(stack_a, stack_b, count);
		*check_ra = 0;
	}
	else
		rb_chunk(stack_b, count);
}

static void	init_max_min(t_ext *max, t_ext *min, int size, t_list **stack_b)
{
		*max = find_max(stack_b);
		*min = find_min(stack_b);
		max->dst = dst(max->pos, size);
		min->dst = dst(min->pos, size);
}

static int	b_mvt(t_list **stack_a, t_list **stack_b, int size, int *check_ra)
{
	t_ext	max;
	t_ext	min;
	int		count;

	count = 0;
	init_max_min(&max, &min, size, stack_b);
	if (min.pos == 1)
	{
		size = pa_size_chunk(stack_a, stack_b, size, &count);
		*check_ra = 1;
	}
	else if (max.pos == 1)
		size = pa_size_chunk(stack_a, stack_b, size, &count);
	else if (max.dst < min.dst + 1)
	{
		if (max.pos > (size / 2) + (size % 2))
			rrb_chunk(stack_b, &count);
		else if (max.pos <= (size / 2) + (size % 2))
			rr_or_rb_chunk(check_ra, stack_a, stack_b, &count);
	}
	else if (max.dst >= min.dst + 1)
	{
		if (min.pos > (size / 2) + (size % 2))
			rrb_chunk(stack_b, &count);
		else if (min.pos <= (size / 2) + (size % 2))
			rr_or_rb_chunk(check_ra, stack_a, stack_b, &count);
	}
	return (count);
}

void	test_sort_b(t_list **stack_a, t_list **stack_b, int size, int *count)
{
	int		check_ra;

	while (size > 0)
	{
		if (is_rev_sorted(stack_b) == 1)
			return (test_push_all_of_b(stack_a, stack_b, count));
		check_ra = 0;
		*count += b_mvt(stack_a, stack_b, size, &check_ra);
		if (check_ra == 1)
			ra_chunk(stack_a, count);
	}
}