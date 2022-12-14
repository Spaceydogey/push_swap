/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:23:41 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/14 21:58:54 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_min(t_ext **min, t_list *stack, int pos, int size)
{
		(*min)->pos = pos;
		(*min)->val = stack->content;
		(*min)->dst = dst((*min)->pos, size);
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
	k = -1;
	i = 1;
	while (++k < size)
	{
		(min[k]) = malloc(sizeof(t_ext));
		if (!min[k])
			return (-1);
		set_min(&min[k], tmp, i, size);
		while (tmp)
		{
			while (tmp && is_in_tab(min, k - 1, (min[k])->val) == 1)
			{	
				tmp = tmp->next;
				i++;
				if (tmp)
					set_min(&min[k], tmp, i, size);
			}
			if (tmp && (min[k])->val >= tmp->content
				&& is_in_tab(min, k - 1, tmp->content) == 0)
			{
				set_min(&min[k], tmp, i, size);
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
		i = 1;
	}
	return (size);
}
