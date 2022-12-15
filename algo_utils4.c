/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:23:41 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/15 17:01:13 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min(t_ext **min, t_list *stack, int pos, int size)
{
		(*min)->pos = pos;
		(*min)->val = stack->content;
		(*min)->dst = dst((*min)->pos, size);
}

void	update_min(t_ext **min, int content, int pos, int size)
{
	int	i;

	i = -1;
	while (++i < LEN)
	{
		if ((min[i])->val == content)
		{
			(min[i])->pos = pos;
			(min[i])->dst = dst(pos, size);
			break ;
		}
	}
}

static t_list	*ps_next(t_list **lst, int *i)
{
	if (*lst)
	{
		*lst = (*lst)->next;
		*i += 1;
		return (*lst);
	}
	return (NULL);
}

static void	set_all_min(t_list **stack_a, t_ext **min, int size, int k)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 1;
	set_min(&min[k], tmp, i, size);
	while (tmp)
	{
		while (tmp && is_in_tab(min, k - 1, (min[k])->val) == 1)
			if (ps_next(&tmp, &i))
				set_min(&min[k], tmp, i, size);
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
			ps_next(&tmp, &i);
	}
}

int	find_next_min(t_list **stack_a, t_ext **min, int iter)
{
	int		i;
	int		k;
	int		size;

	size = ps_lstsize(*stack_a);
	k = (iter * LEN) - 1;
	while (++k < LEN + (iter * LEN))
	{
		(min[k]) = malloc(sizeof(t_ext));
		if (!min[k])
			return (-1);
		set_all_min(stack_a, min, size, k);
	}	
	return (size);
}
