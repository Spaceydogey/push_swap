/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:08:32 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/16 23:22:22 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_ext	get_closest_min(t_ext **min, int k, int len, int iter)
{
	t_ext	closest;
	int		save;

	k = 0;
	save = k;
	closest.dst = INT_MAX;
	while (k < len)
	{
		if ((min[k])->dst < closest.dst && (min[k])->dst != -1)
		{
			closest.val = (min[k])->val;
			closest.dst = (min[k])->dst;
			closest.pos = (min[k])->pos;
			// printf("while\tval\tdst\tpos\n\t%d\t%d\t%d\n", closest.val, closest.dst, closest.pos);
			save = k;
		}
		k++;
	}
	(min[save])->dst = -1;
	return (closest);
}

static void	goto_closest(t_list **stack_a, t_ext **min, int len, int iter)
{
	int		k;
	t_ext	closest;
	int		size;


	k = (iter * LEN);
	size = ps_lstsize(*stack_a);
	if (size == -1)
		return ;
		t_list	*tmp = *stack_a;
		// while (tmp)
		// {
		// 	printf(" prevstack_a : %d\n", tmp->content);
		// 	tmp = tmp->next;
		// }
	update_all_min(stack_a, min, iter, size);
	// tmp = *stack_a;
	// 	while (tmp)
	// 	{
	// 		printf("stack_a : %d\n", tmp->content);
	// 		tmp = tmp->next;
	// 	}
	closest = get_closest_min(&(min[k]), k, len, iter);
	// update_all_min(stack_a, min, iter, size);
	// printf("val\tdst\tpos\n%d\t%d\t%d\n", closest.val, closest.dst, closest.pos);
	while (closest.dst > 0)
	{
		if (closest.pos <= (size / 2) + (size % 2))
			ra(stack_a);
		else
			rra(stack_a);
		// printf("while\tval\tdst\tpos\n\t%d\t%d\t%d\n", closest.val, closest.dst, closest.pos);
		closest.dst -= 1;
	}
}

int	push_all_min(t_list **stack_a, t_list **stack_b, t_ext **min, int iter)
{
	int		len;
	int		size;
	int		i;
	
	len = LEN;
	size = ps_lstsize(*stack_a);
	if ((iter * LEN) + len > size)
		len = size - (iter * LEN);
	i = len;
	while (i > 0)
	{
		goto_closest(stack_a, min, len, iter);
		// printf("pb val %d\n", (*stack_a)->content);
		pb(stack_a, stack_b);
		i--;
	}
	return (size - len);
}
