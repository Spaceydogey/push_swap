/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:47:31 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/20 18:43:40 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_best_chunk.h"

static void	test_sort_a(t_list **stack_a, t_list **stack_b, int size, int *count)
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

static void test_sort(t_stacks stack, t_ext **min, t_iter iter, int *count)
{
	iter.last_iter = iter.iter - 1;
	if (iter.last_iter < 0)
		iter.last_iter = 0;
	if (is_sorted(stack.stack_a))
		return ;
	while (is_sorted(stack.stack_a) == 0)
	{
		iter.last_iter = iter.iter - 1;
		if (iter.last_iter < 0)
			iter.last_iter = 0;
		if (iter.iter >= iter.iter_max)
		{
			test_sort_a(stack.stack_a, stack.stack_b, ps_lstsize(*stack.stack_a), count);
			return ;
		}
		else
		{	
			find_next_min(stack.stack_a, min, iter);
			test_push_all_min(stack, min, iter, count);
			test_move_a(stack.stack_a, min, iter, count);
			test_sort_b(stack.stack_a, stack.stack_b, ps_lstsize(*stack.stack_b), count);
			iter.iter += 1;
		}
	}
}

static int	*test_chunk_size(t_list **lst, int chunk_size)
{
	t_stacks	stack;
	t_list		*stack_b;
	t_ext		**min;
	int			size;
	t_iter		iter;
	int			*res;

	res = malloc(sizeof(int));
	if (!res)
		return (NULL);
	*res = 0;
	stack.stack_a = lst;
	stack_b = NULL;
	stack.stack_b = &stack_b;
	size = ps_lstsize(*stack.stack_a);
	min = malloc(sizeof(t_ext) * size);
	if (!min)
		return (NULL);
	stack_b = NULL;
	iter.chunk_size = chunk_size;
	iter.iter = 0;
	iter.iter_max = size / iter.chunk_size;
	if (size % iter.chunk_size > 0)
		iter.iter_max += 1;
	test_sort(stack, min, iter, res);
	// printf(">res :%d\n", *res);
	test_push_all_of_b(stack.stack_a, stack.stack_b, res);
	free_min(min, iter.chunk_size * iter.iter_max);
	free(min);
	return (res);
}

void	test_push_all_of_b(t_list **stack_a, t_list **stack_b, int *count)
{
	while (*stack_b)
		pa_chunk(stack_a, stack_b, count);
}

// int	find_best_chunk_size(t_list **stack)
// {
// 	t_list	*tmp;
// 	int		chunk_size;
// 	int		min_op;
// 	int		*op;
// 	int		res;

// 	chunk_size = 10;
// 	tmp = *stack;
// 	min_op = INT_MAX;
// 	while (++chunk_size <= 70)
// 	{
// 		*stack = tmp;
// 		op = test_chunk_size(stack, 25);
// 		// if (is_sorted(stack) == 1)
// 		// 	return (0);
// 		printf("%d\n", *op);//
// 		if (min_op > *op)
// 		{
// 			res = chunk_size;
// 			min_op = *op;
// 		}
// 		free(op);
// 	}
// 	return (res);
// }

int	find_best_chunk_size(t_list **stack, int chunk_size, int min_op, int res)
{
	t_list	*tmp;
	// int		chunk_size;
	// int		min_op;
	int		*op;
	// int		res;
	if (chunk_size > 30)
		return (res);
	tmp = *stack;
	min_op = INT_MAX;
	op = test_chunk_size(&tmp, 25);
		// if (is_sorted(stack) == 1)
		// 	return (0);
	printf("%d\n", *op);
	chunk_size++;
	find_best_chunk_size(stack, chunk_size, min_op, res);
	if (min_op > *op)
	{
		res = chunk_size;
		min_op = *op;
	}
	free(op);
	return (res);
}
