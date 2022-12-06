/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:09:09 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/06 17:30:32 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	dst(t_ext **ext, int size)
{
	t_ext *res;

	res = *ext;
	res->dst = res->pos - 1;
	if (res->dst > size - res->pos + 1)
		res->dst = size - res->pos + 1;
}
static int	is_in_tab(t_ext **tab, int size, int content)
{
	int	i;

	i = -1;
// 0 1 2 3 ... size
	while (++i <= size)
	{
		if ((tab[i])->val == content)
			return (1);
	}
	return (0);
}

static t_ext	**find_min_20(t_list **stack_a, int len, int iter)
{
	int		i;
	int		k;
	int		size;
	t_list	*tmp;
	t_ext	**res;

	tmp = *stack_a;
	size = ps_lstsize(*stack_a);
//	printf(">>>min\n");
	res = malloc(sizeof(t_ext *) * len); 
	if (!tmp || !res)
		return (NULL);
	k = 0;
	while(k < len)
	{
		(res[k]) = malloc(sizeof(t_ext)); 
		if (!res[k])
			return (NULL); //TODO FREE ON FAILURE
		i = 1;
		while (tmp && i < iter * LEN)
		{
			i++;
			tmp = tmp->next;
		}
		if (!tmp)
			return (NULL);
		(res[k])->pos = i;
		(res[k])->val = tmp->content;
		dst(&res[k], size);
		while(tmp)
		{
			while (tmp && is_in_tab(res, k - 1, (res[k])->val) == 1)
			{	
				tmp = tmp->next;
				i++;
				if (tmp)
				{
					(res[k])->val = tmp->content;
					(res[k])->pos = i;
					dst(&(res[k]), size);
				}
			}//skip doubles
		//	printf("is in tab %d\n", is_in_tab(res, k, tmp->content));
			if (tmp && (res[k])->val >= tmp->content && is_in_tab(res, k - 1, tmp->content) == 0)
			{
				(res[k])->val = tmp->content;
				(res[k])->pos = i;
				dst(&(res[k]), size);
				while (tmp && is_in_tab(res, k, tmp->content) == 1)
				{
					tmp = tmp->next;
					i++;
				}
			}//change res to the new min value
			else
			{
				if (tmp)
				{
					tmp = tmp->next;
					i++;
				}
			}
		}
//		printf(">>>k %d min %d\n",k, (res[k])->val);
		tmp = *stack_a;
		k++;
	}
	return (res);
}

static int	is_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;

	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void goto_closest(t_list **stack_a, int len, int	iter)
{
	int	k;
	int	closest_min;
	int	closest_pos;
	int	size;
	t_ext	**min;

	k = 0;
	min = find_min_20(stack_a, len, iter);
	if (!min)
		return ;
	size = ps_lstsize(*stack_a);
	closest_min = (min[k])->dst;
//	printf(">closest min %d\n", closest_min);
	closest_pos = (min[k])->pos;
	while (k < len)
	{
//		printf(">>dst %d\n", (min[k])->dst);
		if (min[k]->dst < closest_min)
		{
			closest_min = (min[k])->dst;
			closest_pos = (min[k])->pos;
		}
		k++;
	}
//	printf("> %d\n", closest_min);
	while (closest_min > 0)
	{
		if (closest_pos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		closest_min--;
	}
	k = -1;
	while (++k < len)
		free(min[k]);
	free(min);
}

static void push_all_min(t_list **stack_a, t_list **stack_b, int len, int iter)
{
	t_ext	**min;
	int		size;

	size = ps_lstsize(*stack_a);
	if (len > size)
		len = size;
	while (len > 0)
	{
		goto_closest(stack_a, len, iter);
		pb(stack_a, stack_b);
		len--;
	}
}

static t_ext	find_max(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	tmp = *stack_a;
	if (!tmp)
		return (res);
	res.val = tmp->content;
	res.pos = 1;
	while(tmp)
	{
		i++;
		if (res.val <= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

static t_ext	find_min(t_list **stack_a)
{
	int		i;
	t_list	*tmp;
	t_ext	res;

	i = 0;
	tmp = *stack_a;
	if (!tmp)
		return (res);
	res.val = tmp->content;
	res.pos = 1;
	while(tmp)
	{
		i++;
		if (res.val >= tmp->content)
		{
			res.val = tmp->content;
			res.pos = i;
		}
		tmp = tmp->next;
	}
	return (res);
}

int	is_rev_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	sort_b(t_list **stack_a, t_list **stack_b)
{
	t_ext	max;
	int		size;

	max = find_max(stack_b);
	size = ps_lstsize(*stack_b);
	
	if (size == 0)
		return ;	
	if (is_rev_sorted(stack_b) == 1)
		return ;
	else if (max.pos == 1)
		pa(stack_a, stack_b);
	else if (max.pos > size / 2)
		rrb(stack_b);
	else if (max.pos <= size / 2)
		rb(stack_b);
	sort_b(stack_a, stack_b);
}

static void	sort_a(t_list **stack_a, t_list **stack_b)
{
	t_ext	min;
	t_ext	max;
	int		size;

	min = find_min(stack_a);
	max = find_max(stack_a);
	size = ps_lstsize(*stack_a);
	if (size == 0)
		return ;
	if (is_sorted(stack_a) == 1)
		return ;
	if (size == 3 && min.pos == 1 && max.pos == 2)
		rra(stack_a);
	else if (min.pos == 1)
		pb(stack_a, stack_b);
	else if (min.pos == 2 && max.pos == size)
		sa(stack_a);
	else if (min.pos > size / 2)
		rra(stack_a);
	else if (min.pos <= size / 2)
		ra(stack_a);
	sort_a(stack_a, stack_b);
}

static void push_all_of_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		pa(stack_a, stack_b);
}

static void	sort(t_list **stack_a, t_list **stack_b, int iter)
{
	t_ext	*min;
	int		len;
	int		size;

	if (is_sorted(stack_a))
			return ;
	size = ps_lstsize(*stack_a);
	if (size <= LEN || iter == 1)
		sort_a(stack_a, stack_b);
	else
	{
		printf("iter %d\n", iter);
		push_all_min(stack_a, stack_b, LEN, iter);
		sort_b(stack_a, stack_b);
		push_all_of_b(stack_a, stack_b);
		iter--;
	}
	sort(stack_a, stack_b, iter);
}

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int iter;
	
	stack_a = *lst;
	stack_b = NULL;
	iter = ps_lstsize(stack_a) / LEN;
	sort(&stack_a, &stack_b, iter);
	push_all_of_b(&stack_a, &stack_b);
}

