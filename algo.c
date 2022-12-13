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

void	sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	t_ext	max;
	t_ext	min;
	int		check_ra;


	// min.dst = min.pos + 1;
	// max.dst = max.pos;
	while (size > 0)
	{
		check_ra = 0;
		max = find_max(stack_b);
		min = find_min(stack_b);
		min.dst = min.pos;
		if (min.dst > (size / 2))
			min.dst = size - min.pos;	
		max.dst = max.pos;
		if (max.dst > (size / 2))
			max.dst = size - max.pos;
		if (is_rev_sorted(stack_b) == 1)
		{
			push_all_of_b(stack_a, stack_b);
			return ;
		}
		else if (min.pos == 1)
		{
			pa(stack_a, stack_b);
			check_ra = 1;
			size -= 1;
		}
		else if (max.pos == 1)
		{
			pa(stack_a, stack_b);
			size -= 1;
		}
		// else if (max.pos > (size / 2) + (size % 2))
		// 	rrb(stack_b);
		// else if (max.pos <= (size / 2) + (size % 2))
		// {
		// 	if (check_ra == 1)
		// 	{
		// 		rr(stack_a, stack_b);
		// 		check_ra = 0;
		// 	}
		// 	else
		// 		rb(stack_b);
		// }
		else if (max.dst < min.dst + 1)
		{
			if (max.pos > (size / 2) + (size % 2))
				rrb(stack_b);
			else if (max.pos <= (size / 2) + (size % 2))
			{
				if (check_ra == 1)
				{
					rr(stack_a, stack_b);
					check_ra = 0;
				}
				else
					rb(stack_b);
			}
		}
		else if (max.dst >= min.dst + 1)
		{
			if (min.pos > (size / 2) + (size % 2))
				rrb(stack_b);
			else if (min.pos <= (size / 2) + (size % 2))
			{
				if (check_ra == 1)
				{
					rr(stack_a, stack_b);
					check_ra = 0;
				}
				else
					rb(stack_b);
			}
		}
		if (check_ra == 1)
			ra(stack_a);
	}
	// sort_b(stack_a, stack_b, size);
}

void	sort_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_ext	min;
	t_ext	max;
	// int		size;

	min = find_min(stack_a);
	max = find_max(stack_a);
	// size = ps_lstsize(*stack_a);
	if (size == 0)
		return ;
	if (is_sorted(stack_a) == 1)
		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (min.pos == 1)
	{
		size--;
		pb(stack_a, stack_b);
	}
	else if (min.pos == 2 && max.pos == size)
		sa(stack_a);
	else if (min.pos > (size / 2) + (size % 2))
		rra(stack_a);
	else if (min.pos <= (size / 2) + (size % 2))
		ra(stack_a);
	sort_a(stack_a, stack_b, size);
}

void	sort(t_list **stack_a, t_list **stack_b, t_ext **min, int iter, int iter_max)
{
	int		k;
	int		size;
	int		last_iter;


	last_iter = iter - 1;
	if (last_iter < 0)
		last_iter = 0;
	if (is_sorted(stack_a))
		return ;
	if (iter > iter_max)
	{
		sort_a(stack_a, stack_b, ps_lstsize(*stack_a));
		return ;
	}
	else
	{
			
		push_all_min(stack_a, stack_b, min, iter);
		size = find_next_min(stack_a, min, iter);
		while (iter > 0 && iter < iter_max && min[(last_iter * LEN) + LEN - 1]->pos != size)
		{
			if (min[(last_iter * LEN) + LEN - 1]->pos > size / 2)
			{
				rra(stack_a);
				min[(last_iter * LEN) + LEN - 1]->pos += 1;
			}
			else
			{
				ra(stack_a);
				min[(last_iter * LEN) + LEN - 1]->pos -= 1;
				if (min[(last_iter * LEN) + LEN - 1]->pos == -1)
					min[(last_iter * LEN) + LEN - 1]->pos = size;
			}
			// ft_putnbr_fd(ps_lstsize(*stack_a), 1);
			// write(1,"\t",1);
			// ft_putnbr_fd(min[(last_iter * LEN) + LEN - 1]->val, 1);
			// write(1,"\t",1);
			// ft_putnbr_fd(min[(last_iter * LEN) + LEN - 1]->pos, 1);
			// write(1,"\n",1);
		}
		k = -1;
		while (++k < size)
			free(min[k]);
		sort_b(stack_a, stack_b, ps_lstsize(*stack_b));
		iter++;
	}
	sort(stack_a, stack_b, min, iter, iter_max);
}
