/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:30:08 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/13 13:06:49 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pa_size(t_list **stack_a, t_list **stack_b, int size)
{		
	pa(stack_a, stack_b);
	size -= 1;
	return (size);
}

static void	rr_or_rb(int *check_ra, t_list **stack_a, t_list **stack_b)
{
	if (*check_ra == 1)
	{
		rr(stack_a, stack_b);
		*check_ra = 0;
	}
	else
		rb(stack_b);
}

static void	init_max_min(t_ext *max, t_ext *min, int size, t_list **stack_b)
{
		*max = find_max(stack_b);
		*min = find_min(stack_b);
		max->dst = dst(max->pos, size);
		min->dst = dst(min->pos, size);
}

static void	b_mvt(t_list **stack_a, t_list **stack_b, int size, int *check_ra)
{
	t_ext	max;
	t_ext	min;

	init_max_min(&max, &min, size, stack_b);
	if (min.pos == 1)
	{
		size = pa_size(stack_a, stack_b, size);
		*check_ra = 1;
	}
	else if (max.pos == 1)
		size = pa_size(stack_a, stack_b, size);
	else if (max.dst < min.dst + 1)
	{
		if (max.pos > (size / 2) + (size % 2))
			rrb(stack_b);
		else if (max.pos <= (size / 2) + (size % 2))
			rr_or_rb(check_ra, stack_a, stack_b);
	}
	else if (max.dst >= min.dst + 1)
	{
		if (min.pos > (size / 2) + (size % 2))
			rrb(stack_b);
		else if (min.pos <= (size / 2) + (size % 2))
			rr_or_rb(check_ra, stack_a, stack_b);
	}
}

void	sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		check_ra;

	while (size > 0)
	{
		if (is_rev_sorted(stack_b) == 1)
			return (push_all_of_b(stack_a, stack_b));
		check_ra = 0;
		b_mvt(stack_a, stack_b, size, &check_ra);
		if (check_ra == 1)
			ra(stack_a);
	}
}
