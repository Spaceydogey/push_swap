/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:08:37 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/14 16:08:37 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a(t_list **stack_a, t_list **stack_b, int size)
{
	t_ext	min;
	t_ext	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
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
