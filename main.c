/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelmas <hdelmas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:13:24 by hdelmas           #+#    #+#             */
/*   Updated: 2022/12/13 13:13:26 by hdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ps_algo.h"

void	push_swap(t_list **lst)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ext	**min;
	int		size;

	stack_a = *lst;
	size = ps_lstsize(stack_a);
	min = malloc(sizeof(t_ext) * size);
	stack_b = NULL;
	if (size < LEN)
		sort_a(&stack_a, &stack_b, size);
	else
		sort(&stack_a, &stack_b, min, 0, size / LEN);
	push_all_of_b(&stack_a, &stack_b);
	ps_lstclear(&stack_a);
	free(min);
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
