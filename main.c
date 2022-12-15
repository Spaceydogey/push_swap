/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:13:24 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/15 18:45:49 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_min(t_ext **min, int size)
{
	int	k;

	k = -1;
	while (++k < size)
		free(min[k]);
	free(min);
}

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ext	**min;
	int		size;
	t_iter	iter;

	stack_a = *lst;
	size = ps_lstsize(stack_a);
	min = malloc(sizeof(t_ext) * size);
	stack_b = NULL;
	iter.iter = 0;
	iter.iter_max = size / LEN;
	// if (size % LEN > 0)
	// 	iter.iter_max += 1;
	if (size < LEN)
		sort_a(&stack_a, &stack_b, size);
	else
		sort(&stack_a, &stack_b, min, iter);
	push_all_of_b(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	free_min(min, size);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;

	//TODO add support to input string containing multiple element of the stack 
	if (ac < 2)
		return (1);
	stack_a = parsing(ac, av);
	if (!stack_a)
	{
		ft_putendl_fd("Error\n", 2);
		return (1);
	}
	push_swap(&stack_a);
	return (0);
}
