/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:47:31 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/21 15:51:23 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_best_chunk.h"

static void	test_sort_a(t_list **stack_a,
		t_list **stack_b, int size, int *count)
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
		rra_chunk(stack_a, count);
	else if (min.pos == 1)
	{
		size--;
		pb_chunk(stack_a, stack_b, count);
	}
	else if (min.pos == 2 && max.pos == size)
		sa_chunk(stack_a, count);
	else if (min.pos > (size / 2) + (size % 2))
		rra_chunk(stack_a, count);
	else if (min.pos <= (size / 2) + (size % 2))
		ra_chunk(stack_a, count);
	test_sort_a(stack_a, stack_b, size, count);
}

static void	test_sort(t_stacks st, t_ext **min, t_iter iter, int *count)
{
	iter.last_iter = iter.iter - 1;
	if (iter.last_iter < 0)
		iter.last_iter = 0;
	if (is_sorted(st.stack_a))
		return ;
	while (is_sorted(st.stack_a) == 0)
	{
		iter.last_iter = iter.iter - 1;
		if (iter.last_iter < 0)
			iter.last_iter = 0;
		if (iter.iter >= iter.iter_max)
		{
			test_sort_a(st.stack_a, st.stack_b, ps_lstsize(*st.stack_a), count);
			return ;
		}
		else
		{	
			find_next_min(st.stack_a, min, iter);
			test_push_all_min(st, min, iter, count);
			test_move_a(st.stack_a, min, iter, count);
			test_sort_b(st.stack_a, st.stack_b, ps_lstsize(*st.stack_b), count);
			iter.iter += 1;
		}
	}
}

static void	init_iter(t_iter *iter, t_stacks stack, int chunk_size)
{
	iter->chunk_size = chunk_size;
	iter->iter = 0;
	iter->iter_max = ps_lstsize(*stack.stack_a) / iter->chunk_size;
	if (ps_lstsize(*stack.stack_a) % iter->chunk_size > 0)
		iter->iter_max += 1;
}

static int	*test_chunk_size(t_list **lst, int chunk_size)
{
	t_stacks	stack;
	t_list		*stack_b;
	t_ext		**min;
	t_iter		iter;
	int			*res;

	res = malloc(sizeof(int));
	if (!res)
		return (NULL);
	*res = 0;
	stack.stack_a = lst;
	stack_b = NULL;
	stack.stack_b = &stack_b;
	min = malloc(sizeof(t_ext) * ps_lstsize(*stack.stack_a));
	if (!min)
		return (NULL);
	stack_b = NULL;
	init_iter(&iter, stack, chunk_size);
	test_sort(stack, min, iter, res);
	test_push_all_of_b(stack.stack_a, stack.stack_b, res);
	ps_lstclear(stack.stack_a);
	free_min(min, iter.chunk_size * iter.iter_max);
	free(min);
	return (res);
}

int	find_best_chunk_size(int save_ac, char **save_av)
{
	t_list	*tmp;
	int		chunk_size;
	int		min_op;
	int		*op;
	int		res;

	chunk_size = 10;
	min_op = INT_MAX;
	while (++chunk_size <= 70)
	{
		tmp = parsing(save_ac, save_av);
		if (!tmp)
			return (-1);
		op = test_chunk_size(&tmp, chunk_size);
		if (min_op > *op)
		{
			res = chunk_size;
			min_op = *op;
		}
		free(op);
	}
	return (res);
}
